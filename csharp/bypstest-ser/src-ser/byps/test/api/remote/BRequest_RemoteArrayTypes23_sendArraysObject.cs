﻿//
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace byps.test.api.remote
{
	
	public sealed class BRequest_RemoteArrayTypes23_sendArraysObject : BMethodRequest, BSerializable
	{
	
		#region Execute
		
		public override int getRemoteId() { return 769717182; }
		
		public override void execute(BRemote __byps__remote, BAsyncResultIF<Object> __byps__asyncResult) {
			// checkpoint byps.gen.cs.GenApiClass:429
			try {
				RemoteArrayTypes23 __byps__remoteT = (RemoteArrayTypes23)__byps__remote;				
				BAsyncResultSendMethod<Object[]> __byps__outerResult = new BAsyncResultSendMethod<Object[]>(__byps__asyncResult, new byps.test.api.BResult_183594037());				
				__byps__remoteT.SendArraysObject(arr2Value, arr3Value, arr4Value, BAsyncResultHelper.ToDelegate(__byps__outerResult));
			} catch (Exception e) {
				__byps__asyncResult.setAsyncResult(null, e);
			}
		}		
		
		#endregion
		
		#region Fields
		
		internal Object[,] arr2Value;

		internal Object[,,] arr3Value;

		internal Object[,,,] arr4Value;

		#endregion
		
		
		public static readonly long serialVersionUID = 1306614381L;		
	} // end class
}  // end namespace
