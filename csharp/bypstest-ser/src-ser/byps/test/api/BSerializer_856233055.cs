﻿//
// Serializer for byps.test.api.BResult_601099730
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace byps.test.api
{
	
	public class BSerializer_856233055 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_856233055();
		
		public BSerializer_856233055()
			: base(856233055) {}
		
		public BSerializer_856233055(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BResult_601099730 obj = (BResult_601099730)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:498
			bout.writeObj(obj.resultValue, false, byps.test.api.BSerializer_601099730.instance);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BResult_601099730 obj = (BResult_601099730)(obj1 != null ? obj1 : bin.onObjectCreated(new BResult_601099730()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:453
			obj.resultValue = (IDictionary<long,short>)bin.readObj(false, null);
			
			return obj;
		}
		
	}
} // namespace
