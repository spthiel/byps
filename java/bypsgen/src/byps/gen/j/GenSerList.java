package byps.gen.j;
/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */
import java.io.IOException;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import byps.BBinaryModel;
import byps.BException;
import byps.BExceptionC;
import byps.gen.api.SerialInfo;
import byps.gen.api.TypeInfo;
import byps.gen.utils.CodePrinter;


public class GenSerList {
	static Logger log = LoggerFactory.getLogger(GenSerList.class);

	GenSerList(PrintContext pctxt, SerialInfo serInfo, CodePrinter pr) throws BException {
		this(pctxt, serInfo, pr, BBinaryModel.MEDIUM);
	}
	
	GenSerList(PrintContext pctxt, SerialInfo serInfo, CodePrinter pr, BBinaryModel bmodel) throws BException {
		this.serInfo = serInfo;
		this.pr = pr;
		this.serializerName = pctxt.getSerializerClassName(serInfo, bmodel);
		this.pack = pctxt.getSerializerPackage(serInfo);
		this.pctxt = pctxt;
		this.bmodel = bmodel;
		
		if (serInfo.typeArgs.size() != 1) throw new BException(BExceptionC.INTERNAL, "Expected 1 type argument for Set/List class: " + serInfo.toString());
		elmType = serInfo.typeArgs.get(0);
		
	}
	
	protected void printConstructors() throws IOException {
		//log.debug(GeneratorJ.class.getName(), "printConstructors");
		
		pr.print("public ").print(serializerName).println("() {");
		pr.beginBlock();
		pr.println("super(" + serInfo.typeId + ");");
		pr.endBlock();
		pr.println("}");
		
		//log.debug(GeneratorJ.class.getName(), "printConstructors");
	}
	
	protected void printSingletonInstance() throws IOException {
		//log.debug(GeneratorJ.class.getName(), "printSingletonInstance");

		pr.print("public final static BSerializer instance = new ").print(""+serializerName).println("();");
		
		//log.debug(GeneratorJ.class.getName(), "printSingletonInstance");
	}

	protected String getListTypeNameForCreate(TypeInfo tinfo) throws IOException {
		String listType = tinfo.toString("java.util");
		int p = listType.indexOf("Set<");
		if (p == 0) {
			listType = "HashSet" + listType.substring(3);
		}
		else {
			p = listType.indexOf("List<");
			if (p == 0) {
				listType = "ArrayList" + listType.substring(4);
			}
		}
		return listType;
	}
	
	protected void printRead() throws IOException {
		String listType = getListTypeNameForCreate(serInfo);

	    pr.println("public Object read(final Object obj1, final BInput bin1, final long version) throws BException {");
		pr.beginBlock();
	    pr.println("final BInputBin bin = (BInputBin)bin1;");
	    pr.println("final BBufferBin bbuf = bin.bbuf;");
	    
    	pr.println("final int n = bbuf.getLength();");

	    pr.print("final ").print(listType).print(" arr = new ").print(listType)
    		.print(serInfo.isListType() ? "(n)" : "()").println(";");
		pr.println("bin.onObjectCreated(arr);");

	    pr.println("for (int i0 = 0; i0 < n; i0++) {");
	    pr.beginBlock();
	    
		CodePrinter mpr = pr.print(elmType.toString()).print(" ");
		pctxt.printStreamGetItem(mpr, bmodel, "obj", elmType);
		
		pr.println("arr.add(obj);");

	    pr.endBlock();
	    pr.println("}");
	    pr.println("return arr;");
		pr.endBlock();
		pr.println("}");
	}
	
	protected void printWrite() throws IOException {
		String listType = serInfo.toString();

	    pr.println("public void write(Object obj1, BOutput bout1, final long version)  throws BException {");
	    pr.beginBlock();
	    
	    pr.println("BOutputBin bout = (BOutputBin)bout1;");
	    pr.println("BBufferBin bbuf = bout.bbuf;");
	    
	    pr.print(listType).print(" arr = (").print(listType).print(")obj1;").println();
	    pr.println("int n = arr.size();");
    	pr.println("bbuf.putLength(n);");
	    pr.print("for (").print(elmType.toString()).print(" obj : arr) {").println();
	    pr.beginBlock();
	    pctxt.printStreamPutItem(pr, bmodel, "obj", elmType);
	    pr.endBlock();
	    pr.println("}");
	    
	    pr.endBlock();
	    pr.println("}");
	}

  protected void printPrepareForLazyLoading() {
    String listType = serInfo.toString("java.util");
    
    pr.println("@Override");
    pr.println("public void prepareForLazyLoading(final Object obj1, final BInput bin, final long version) throws BException {");
    pr.beginBlock();

    pr.print(listType).print(" arr = (").print(listType).print(")obj1;").println();

    pr.print("for (").print(elmType.toString()).print(" obj : arr) {").println();
    pr.beginBlock();

    pctxt.printStreamPrepareMember(pr, bmodel, "obj", "", false, elmType);
    
    pr.endBlock();
    pr.println("}");

    pr.endBlock();
    pr.println("}");
  }

	void generate() throws IOException {
		//log.debug(GenSerList.class.getName(), "generateListSerializer");
		
		pr.print("package ").print(pack).print(";").println();
		pr.println();
		
		pctxt.printDoNotModify(pr, getClass(), "Serializer for " + serInfo);

		pr.println("import byps.*;");
		pr.println("import java.util.*;");

		pr.println();
		
		pr.println("@SuppressWarnings({\"all\", \"deprecation\", \"unchecked\"})");
		
		pr.print("public class ").print(serializerName)
		  .print(" extends BSerializer").println(" {");
		
		pr.beginBlock();
		pr.println();
		
		printSingletonInstance();
		pr.println();
		
		printConstructors();
		pr.println();
		
		// getSize method can be inherited for Object types
		
		printRead();
		pr.println();

		printWrite();
		pr.println();
		
    // Does element type contain members that are potentially lazy loaded?
    if (pctxt.isLazyLoadingType(serInfo)) {
  		printPrepareForLazyLoading();
  		pr.println();
    }
    
		pr.endBlock();
		
		pr.println("}");

		//log.debug(GenSerList.class.getName(), "generateListSerializer");
	}

	
	final protected SerialInfo serInfo;
	final protected CodePrinter pr;
	final protected String serializerName;
	final protected String pack;
	final protected TypeInfo elmType;
	final protected PrintContext pctxt;
	final protected BBinaryModel bmodel;
}
