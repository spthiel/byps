﻿//
// Serializer for byps.test.api.BResult_1406124761
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace byps.test.api
{
	
	public class BSerializer_2127200796 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_2127200796();
		
		public BSerializer_2127200796()
			: base(2127200796) {}
		
		public BSerializer_2127200796(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BResult_1406124761 obj = (BResult_1406124761)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:498
			bout.writeObj(obj.resultValue, false, byps.test.api.BSerializer_1406124761.instance);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BResult_1406124761 obj = (BResult_1406124761)(obj1 != null ? obj1 : bin.onObjectCreated(new BResult_1406124761()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:453
			obj.resultValue = (ISet<int[]>)bin.readObj(false, null);
			
			return obj;
		}
		
	}
} // namespace
