﻿//
// Serializer for byps.test.api.BResult_5
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace byps.test.api
{
	
	public class BSerializer_432867943 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_432867943();
		
		public BSerializer_432867943()
			: base(432867943) {}
		
		public BSerializer_432867943(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BResult_5 obj = (BResult_5)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:498
			bbuf.putInt(obj.resultValue);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BResult_5 obj = (BResult_5)(obj1 != null ? obj1 : bin.onObjectCreated(new BResult_5()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:453
			obj.resultValue = bbuf.getInt();
			
			return obj;
		}
		
	}
} // namespace
