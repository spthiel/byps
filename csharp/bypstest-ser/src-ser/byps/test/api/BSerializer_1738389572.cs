﻿//
// Serializer for byps.test.api.BResult_1359468275
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace byps.test.api
{
	
	public class BSerializer_1738389572 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_1738389572();
		
		public BSerializer_1738389572()
			: base(1738389572) {}
		
		public BSerializer_1738389572(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BResult_1359468275 obj = (BResult_1359468275)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:498
			bout.writeObj(obj.resultValue, false, byps.test.api.BSerializer_1359468275.instance);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BResult_1359468275 obj = (BResult_1359468275)(obj1 != null ? obj1 : bin.onObjectCreated(new BResult_1359468275()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:453
			obj.resultValue = (double[])bin.readObj(false, byps.test.api.BSerializer_1359468275.instance);
			
			return obj;
		}
		
	}
} // namespace
