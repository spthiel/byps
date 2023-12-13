package byps.gen.api;
/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */
public class CommentInfo {
	
	public final static String KIND_SUMMARY = "@summary";
	public final static String KIND_REMARKS = "@remarks";
	public final static String KIND_DEPRECATED = "@deprecated";

	public final String kind;
	public final String text;
	
	public CommentInfo(String kind, String text) {
		super();
		this.kind = kind;
		this.text = text != null ? text.trim() : null;
	}
	
	public CommentInfo() {
		this(null, null);
	}
}
