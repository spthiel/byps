﻿//
// Serializer for byps.test.api.remote.BRequest_RemotePrimitiveTypes_setDate
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace byps.test.api.remote
{
	
	public class BSerializer_243998223 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_243998223();
		
		public BSerializer_243998223()
			: base(243998223) {}
		
		public BSerializer_243998223(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_RemotePrimitiveTypes_setDate obj = (BRequest_RemotePrimitiveTypes_setDate)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:498
			bbuf.putDate(obj.vValue);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_RemotePrimitiveTypes_setDate obj = (BRequest_RemotePrimitiveTypes_setDate)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_RemotePrimitiveTypes_setDate()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:453
			obj.vValue = bbuf.getDate();
			
			return obj;
		}
		
	}
} // namespace
