﻿//
// 
// THIS FILE HAS BEEN GENERATED. DO NOT MODIFY.
//

using System;
using System.Collections.Generic;
using byps;

namespace byps.test.api.remote
{
	
	public sealed class BRequest_RemoteInlineInstance_getPoint2DListList : BMethodRequest, BSerializable
	{
	
		#region Execute
		
		public override int getRemoteId() { return 567395951; }
		
		public override void execute(BRemote __byps__remote, BAsyncResultIF<Object> __byps__asyncResult) {
			// checkpoint byps.gen.cs.GenApiClass:429
			try {
				RemoteInlineInstance __byps__remoteT = (RemoteInlineInstance)__byps__remote;				
				BAsyncResultSendMethod<IList<IList<byps.test.api.inl.Point2D>>> __byps__outerResult = new BAsyncResultSendMethod<IList<IList<byps.test.api.inl.Point2D>>>(__byps__asyncResult, new byps.test.api.BResult_1823330785());				
				__byps__remoteT.GetPoint2DListList(BAsyncResultHelper.ToDelegate(__byps__outerResult));
			} catch (Exception e) {
				__byps__asyncResult.setAsyncResult(null, e);
			}
		}		
		
		#endregion
		
		#region Fields
		
		#endregion
		
		
		public static readonly long serialVersionUID = 1650554387L;		
	} // end class
}  // end namespace
