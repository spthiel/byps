﻿//
// Serializer for byps.test.api.remote.BRequest_RemoteListTypes_setInt4
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace byps.test.api.remote
{
	
	public class BSerializer_136821225 : BSerializer {
		
		public readonly static BSerializer instance = new BSerializer_136821225();
		
		public BSerializer_136821225()
			: base(136821225) {}
		
		public BSerializer_136821225(int typeId)
			: base(typeId) {}
		
		
		public override void write(Object obj1, BOutput bout1, long version)
		{
			BRequest_RemoteListTypes_setInt4 obj = (BRequest_RemoteListTypes_setInt4)obj1;			
			BOutputBin bout = (BOutputBin)bout1;
			BBufferBin bbuf = bout.bbuf;
			// checkpoint byps.gen.cs.PrintContext:498
			bout.writeObj(obj.int4Value, false, byps.test.api.BSerializer_1633500852.instance);
		}
		
		public override Object read(Object obj1, BInput bin1, long version)
		{
			BInputBin bin = (BInputBin)bin1;
			BRequest_RemoteListTypes_setInt4 obj = (BRequest_RemoteListTypes_setInt4)(obj1 != null ? obj1 : bin.onObjectCreated(new BRequest_RemoteListTypes_setInt4()));
			
			BBufferBin bbuf = bin.bbuf;
			// checkpoint byps.gen.cs.PrintContext:453
			obj.int4Value = (IList<IDictionary<int,IList<HashSet<int>>>>)bin.readObj(false, null);
			
			return obj;
		}
		
	}
} // namespace
