﻿//
// Serializer for byps.test.api.remote.BRequest_RemoteArrayTypes4dim_setBool
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace byps.test.api.remote
{
	
	public class BSerializer_185807085 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_185807085();
		
		public BSerializer_185807085()
			: base(185807085) {}
		
		public BSerializer_185807085(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_RemoteArrayTypes4dim_setBool obj = (BRequest_RemoteArrayTypes4dim_setBool)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:498
			bout.writeObj(obj.vValue, false, byps.test.api.BSerializer_945713488.instance);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_RemoteArrayTypes4dim_setBool obj = (BRequest_RemoteArrayTypes4dim_setBool)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_RemoteArrayTypes4dim_setBool()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:453
			obj.vValue = (bool[,,,])bin.readObj(false, byps.test.api.BSerializer_945713488.instance);
			
			return obj;
		}
		
	}
} // namespace
