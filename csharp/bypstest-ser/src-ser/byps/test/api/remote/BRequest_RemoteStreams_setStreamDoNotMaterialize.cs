﻿//
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace byps.test.api.remote
{
	
	public sealed class BRequest_RemoteStreams_setStreamDoNotMaterialize : BMethodRequest, BSerializable
	{
	
		#region Execute
		
		public override int getRemoteId() { return 1043578866; }
		
		public override void execute(BRemote __byps__remote, BAsyncResultIF<Object> __byps__asyncResult) {
			// checkpoint byps.gen.cs.GenApiClass:429
			try {
				RemoteStreams __byps__remoteT = (RemoteStreams)__byps__remote;				
				BAsyncResultSendMethod<Object> __byps__outerResult = new BAsyncResultSendMethod<Object>(__byps__asyncResult, new byps.test.api.BResult_19());				
				__byps__remoteT.SetStreamDoNotMaterialize(streamValue, BAsyncResultHelper.ToDelegate(__byps__outerResult));
			} catch (Exception e) {
				__byps__asyncResult.setAsyncResult(null, e);
			}
		}		
		
		#endregion
		
		#region Fields
		
		internal System.IO.Stream streamValue;

		#endregion
		
		
		public static readonly long serialVersionUID = 199832593L;		
	} // end class
}  // end namespace
