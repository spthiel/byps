﻿#include "Testser-impl.h"
using namespace ::std;
using namespace ::byps;

namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteSetTypes_setChar1
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteSetTypes_setChar1::BRequest_RemoteSetTypes_setChar1() : BMethodRequest(1900796440) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteSetTypes_setChar1::BRequest_RemoteSetTypes_setChar1(const byps::PSetCharacter& char1)
	: BMethodRequest(1900796440) 
	, char1(char1)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteSetTypes_setChar1::BSerializable_getTypeId() {
	return 1462409067; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteSetTypes_setChar1::serialize(BIO& ar, const BVERSION version) {
	ar & this->char1;
}
void byps::test::api::remote::BRequest_RemoteSetTypes_setChar1::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteSetTypes __byps__remoteT = byps_ptr_cast<RemoteSetTypes>(__byps__remote);
	__byps__remoteT->setChar1(char1, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_1462409067(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteSetTypes_setChar1>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteSetTypes_setDate1
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteSetTypes_setDate1::BRequest_RemoteSetTypes_setDate1() : BMethodRequest(1900796440) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteSetTypes_setDate1::BRequest_RemoteSetTypes_setDate1(const byps::PSetDate& obj1)
	: BMethodRequest(1900796440) 
	, obj1(obj1)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteSetTypes_setDate1::BSerializable_getTypeId() {
	return 1461676227; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteSetTypes_setDate1::serialize(BIO& ar, const BVERSION version) {
	ar & this->obj1;
}
void byps::test::api::remote::BRequest_RemoteSetTypes_setDate1::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteSetTypes __byps__remoteT = byps_ptr_cast<RemoteSetTypes>(__byps__remote);
	__byps__remoteT->setDate1(obj1, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_1461676227(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteSetTypes_setDate1>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteSetTypes_setDouble1
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteSetTypes_setDouble1::BRequest_RemoteSetTypes_setDouble1() : BMethodRequest(1900796440) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteSetTypes_setDouble1::BRequest_RemoteSetTypes_setDouble1(const byps::PSetDouble& double1)
	: BMethodRequest(1900796440) 
	, double1(double1)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteSetTypes_setDouble1::BSerializable_getTypeId() {
	return 185153786; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteSetTypes_setDouble1::serialize(BIO& ar, const BVERSION version) {
	ar & this->double1;
}
void byps::test::api::remote::BRequest_RemoteSetTypes_setDouble1::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteSetTypes __byps__remoteT = byps_ptr_cast<RemoteSetTypes>(__byps__remote);
	__byps__remoteT->setDouble1(double1, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_185153786(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteSetTypes_setDouble1>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteSetTypes_setFloat1
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteSetTypes_setFloat1::BRequest_RemoteSetTypes_setFloat1() : BMethodRequest(1900796440) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteSetTypes_setFloat1::BRequest_RemoteSetTypes_setFloat1(const byps::PSetFloat& float1)
	: BMethodRequest(1900796440) 
	, float1(float1)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteSetTypes_setFloat1::BSerializable_getTypeId() {
	return 1999943579; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteSetTypes_setFloat1::serialize(BIO& ar, const BVERSION version) {
	ar & this->float1;
}
void byps::test::api::remote::BRequest_RemoteSetTypes_setFloat1::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteSetTypes __byps__remoteT = byps_ptr_cast<RemoteSetTypes>(__byps__remote);
	__byps__remoteT->setFloat1(float1, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_1999943579(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteSetTypes_setFloat1>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteSetTypes_setInt1
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteSetTypes_setInt1::BRequest_RemoteSetTypes_setInt1() : BMethodRequest(1900796440) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteSetTypes_setInt1::BRequest_RemoteSetTypes_setInt1(const byps::PSetInteger& int1)
	: BMethodRequest(1900796440) 
	, int1(int1)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteSetTypes_setInt1::BSerializable_getTypeId() {
	return 462631448; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteSetTypes_setInt1::serialize(BIO& ar, const BVERSION version) {
	ar & this->int1;
}
void byps::test::api::remote::BRequest_RemoteSetTypes_setInt1::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteSetTypes __byps__remoteT = byps_ptr_cast<RemoteSetTypes>(__byps__remote);
	__byps__remoteT->setInt1(int1, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_462631448(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteSetTypes_setInt1>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteSetTypes_setInt2
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteSetTypes_setInt2::BRequest_RemoteSetTypes_setInt2() : BMethodRequest(1900796440) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteSetTypes_setInt2::BRequest_RemoteSetTypes_setInt2(const byps_ptr< ::std::set< PArrayInt > >& int2)
	: BMethodRequest(1900796440) 
	, int2(int2)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteSetTypes_setInt2::BSerializable_getTypeId() {
	return 462631447; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteSetTypes_setInt2::serialize(BIO& ar, const BVERSION version) {
	ar & this->int2;
}
void byps::test::api::remote::BRequest_RemoteSetTypes_setInt2::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteSetTypes __byps__remoteT = byps_ptr_cast<RemoteSetTypes>(__byps__remote);
	__byps__remoteT->setInt2(int2, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_462631447(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteSetTypes_setInt2>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteSetTypes_setLong1
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteSetTypes_setLong1::BRequest_RemoteSetTypes_setLong1() : BMethodRequest(1900796440) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteSetTypes_setLong1::BRequest_RemoteSetTypes_setLong1(const byps::PSetLong& long1)
	: BMethodRequest(1900796440) 
	, long1(long1)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteSetTypes_setLong1::BSerializable_getTypeId() {
	return 1453876689; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteSetTypes_setLong1::serialize(BIO& ar, const BVERSION version) {
	ar & this->long1;
}
void byps::test::api::remote::BRequest_RemoteSetTypes_setLong1::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteSetTypes __byps__remoteT = byps_ptr_cast<RemoteSetTypes>(__byps__remote);
	__byps__remoteT->setLong1(long1, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_1453876689(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteSetTypes_setLong1>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteSetTypes_setObj1
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteSetTypes_setObj1::BRequest_RemoteSetTypes_setObj1() : BMethodRequest(1900796440) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteSetTypes_setObj1::BRequest_RemoteSetTypes_setObj1(const byps_ptr< ::std::set< PSerializable > >& obj1)
	: BMethodRequest(1900796440) 
	, obj1(obj1)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteSetTypes_setObj1::BSerializable_getTypeId() {
	return 462464544; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteSetTypes_setObj1::serialize(BIO& ar, const BVERSION version) {
	ar & this->obj1;
}
void byps::test::api::remote::BRequest_RemoteSetTypes_setObj1::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteSetTypes __byps__remoteT = byps_ptr_cast<RemoteSetTypes>(__byps__remote);
	__byps__remoteT->setObj1(obj1, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_462464544(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteSetTypes_setObj1>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteSetTypes_setPrimitiveTypes1
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteSetTypes_setPrimitiveTypes1::BRequest_RemoteSetTypes_setPrimitiveTypes1() : BMethodRequest(1900796440) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteSetTypes_setPrimitiveTypes1::BRequest_RemoteSetTypes_setPrimitiveTypes1(const byps_ptr< ::std::set< byps::test::api::prim::PPrimitiveTypes > >& primitiveTypes1)
	: BMethodRequest(1900796440) 
	, primitiveTypes1(primitiveTypes1)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteSetTypes_setPrimitiveTypes1::BSerializable_getTypeId() {
	return 250758937; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteSetTypes_setPrimitiveTypes1::serialize(BIO& ar, const BVERSION version) {
	ar & this->primitiveTypes1;
}
void byps::test::api::remote::BRequest_RemoteSetTypes_setPrimitiveTypes1::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteSetTypes __byps__remoteT = byps_ptr_cast<RemoteSetTypes>(__byps__remote);
	__byps__remoteT->setPrimitiveTypes1(primitiveTypes1, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_250758937(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteSetTypes_setPrimitiveTypes1>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteSetTypes_setShort1
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteSetTypes_setShort1::BRequest_RemoteSetTypes_setShort1() : BMethodRequest(1900796440) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteSetTypes_setShort1::BRequest_RemoteSetTypes_setShort1(const byps::PSetShort& short1)
	: BMethodRequest(1900796440) 
	, short1(short1)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteSetTypes_setShort1::BSerializable_getTypeId() {
	return 1926522501; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteSetTypes_setShort1::serialize(BIO& ar, const BVERSION version) {
	ar & this->short1;
}
void byps::test::api::remote::BRequest_RemoteSetTypes_setShort1::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteSetTypes __byps__remoteT = byps_ptr_cast<RemoteSetTypes>(__byps__remote);
	__byps__remoteT->setShort1(short1, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_1926522501(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteSetTypes_setShort1>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteSetTypes_setString1
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteSetTypes_setString1::BRequest_RemoteSetTypes_setString1() : BMethodRequest(1900796440) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteSetTypes_setString1::BRequest_RemoteSetTypes_setString1(const byps::PSetString& string1)
	: BMethodRequest(1900796440) 
	, string1(string1)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteSetTypes_setString1::BSerializable_getTypeId() {
	return 753392826; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteSetTypes_setString1::serialize(BIO& ar, const BVERSION version) {
	ar & this->string1;
}
void byps::test::api::remote::BRequest_RemoteSetTypes_setString1::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteSetTypes __byps__remoteT = byps_ptr_cast<RemoteSetTypes>(__byps__remote);
	__byps__remoteT->setString1(string1, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_753392826(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteSetTypes_setString1>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteStreams_getImage
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteStreams_getImage::BRequest_RemoteStreams_getImage() : BMethodRequest(1043578866) {
}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteStreams_getImage::BSerializable_getTypeId() {
	return 61677379; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteStreams_getImage::serialize(BIO& ar, const BVERSION version) {
}
void byps::test::api::remote::BRequest_RemoteStreams_getImage::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteStreams __byps__remoteT = byps_ptr_cast<RemoteStreams>(__byps__remote);
	__byps__remoteT->getImage([__byps__asyncResult](PContentStream __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_15(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_61677379(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteStreams_getImage>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteStreams_getImages
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteStreams_getImages::BRequest_RemoteStreams_getImages() : BMethodRequest(1043578866) {
}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteStreams_getImages::BSerializable_getTypeId() {
	return 1911998634; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteStreams_getImages::serialize(BIO& ar, const BVERSION version) {
}
void byps::test::api::remote::BRequest_RemoteStreams_getImages::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteStreams __byps__remoteT = byps_ptr_cast<RemoteStreams>(__byps__remote);
	__byps__remoteT->getImages([__byps__asyncResult](byps::PMapIntegerInputStream __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_476459792(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_1911998634(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteStreams_getImages>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteStreams_getSharedStream
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteStreams_getSharedStream::BRequest_RemoteStreams_getSharedStream() : BMethodRequest(1043578866) {
	id = 0;
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteStreams_getSharedStream::BRequest_RemoteStreams_getSharedStream(int64_t id)
	: BMethodRequest(1043578866) 
	, id(id)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteStreams_getSharedStream::BSerializable_getTypeId() {
	return 1652400477; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteStreams_getSharedStream::serialize(BIO& ar, const BVERSION version) {
	ar & this->id;
}
void byps::test::api::remote::BRequest_RemoteStreams_getSharedStream::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteStreams __byps__remoteT = byps_ptr_cast<RemoteStreams>(__byps__remote);
	__byps__remoteT->getSharedStream(id, [__byps__asyncResult](PContentStream __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_15(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_1652400477(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteStreams_getSharedStream>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteStreams_getStreamDeferedProperies
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteStreams_getStreamDeferedProperies::BRequest_RemoteStreams_getStreamDeferedProperies() : BMethodRequest(1043578866) {
}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteStreams_getStreamDeferedProperies::BSerializable_getTypeId() {
	return 1205766796; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteStreams_getStreamDeferedProperies::serialize(BIO& ar, const BVERSION version) {
}
void byps::test::api::remote::BRequest_RemoteStreams_getStreamDeferedProperies::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteStreams __byps__remoteT = byps_ptr_cast<RemoteStreams>(__byps__remote);
	__byps__remoteT->getStreamDeferedProperies([__byps__asyncResult](PContentStream __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_15(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_1205766796(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteStreams_getStreamDeferedProperies>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteStreams_getStreamDoNotClone
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteStreams_getStreamDoNotClone::BRequest_RemoteStreams_getStreamDoNotClone() : BMethodRequest(1043578866) {
}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteStreams_getStreamDoNotClone::BSerializable_getTypeId() {
	return 692369677; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteStreams_getStreamDoNotClone::serialize(BIO& ar, const BVERSION version) {
}
void byps::test::api::remote::BRequest_RemoteStreams_getStreamDoNotClone::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteStreams __byps__remoteT = byps_ptr_cast<RemoteStreams>(__byps__remote);
	__byps__remoteT->getStreamDoNotClone([__byps__asyncResult](PContentStream __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_15(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_692369677(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteStreams_getStreamDoNotClone>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteStreams_getTextStream
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteStreams_getTextStream::BRequest_RemoteStreams_getTextStream() : BMethodRequest(1043578866) {
}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteStreams_getTextStream::BSerializable_getTypeId() {
	return 818823403; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteStreams_getTextStream::serialize(BIO& ar, const BVERSION version) {
}
void byps::test::api::remote::BRequest_RemoteStreams_getTextStream::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteStreams __byps__remoteT = byps_ptr_cast<RemoteStreams>(__byps__remote);
	__byps__remoteT->getTextStream([__byps__asyncResult](PContentStream __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_15(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_818823403(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteStreams_getTextStream>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteStreams_getVideoCheckSupportByteRange
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteStreams_getVideoCheckSupportByteRange::BRequest_RemoteStreams_getVideoCheckSupportByteRange() : BMethodRequest(1043578866) {
}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteStreams_getVideoCheckSupportByteRange::BSerializable_getTypeId() {
	return 1006919505; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteStreams_getVideoCheckSupportByteRange::serialize(BIO& ar, const BVERSION version) {
}
void byps::test::api::remote::BRequest_RemoteStreams_getVideoCheckSupportByteRange::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteStreams __byps__remoteT = byps_ptr_cast<RemoteStreams>(__byps__remote);
	__byps__remoteT->getVideoCheckSupportByteRange([__byps__asyncResult](PContentStream __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_15(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_1006919505(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteStreams_getVideoCheckSupportByteRange>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteStreams_putSharedStream
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteStreams_putSharedStream::BRequest_RemoteStreams_putSharedStream() : BMethodRequest(1043578866) {
	id = 0;
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteStreams_putSharedStream::BRequest_RemoteStreams_putSharedStream(int64_t id, const PContentStream& stream)
	: BMethodRequest(1043578866) 
	, id(id)
	, stream(stream)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteStreams_putSharedStream::BSerializable_getTypeId() {
	return 468339492; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteStreams_putSharedStream::serialize(BIO& ar, const BVERSION version) {
	ar & this->id;
	ar & this->stream;
}
void byps::test::api::remote::BRequest_RemoteStreams_putSharedStream::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteStreams __byps__remoteT = byps_ptr_cast<RemoteStreams>(__byps__remote);
	__byps__remoteT->putSharedStream(id, stream, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_468339492(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteStreams_putSharedStream>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteStreams_setImage
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteStreams_setImage::BRequest_RemoteStreams_setImage() : BMethodRequest(1043578866) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteStreams_setImage::BRequest_RemoteStreams_setImage(const PContentStream& istrm)
	: BMethodRequest(1043578866) 
	, istrm(istrm)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteStreams_setImage::BSerializable_getTypeId() {
	return 622789839; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteStreams_setImage::serialize(BIO& ar, const BVERSION version) {
	ar & this->istrm;
}
void byps::test::api::remote::BRequest_RemoteStreams_setImage::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteStreams __byps__remoteT = byps_ptr_cast<RemoteStreams>(__byps__remote);
	__byps__remoteT->setImage(istrm, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_622789839(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteStreams_setImage>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteStreams_setImages
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteStreams_setImages::BRequest_RemoteStreams_setImages() : BMethodRequest(1043578866) {
	doNotReadStreamAtKey = 0;
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteStreams_setImages::BRequest_RemoteStreams_setImages(const byps::PMapIntegerInputStream& istrms, int32_t doNotReadStreamAtKey)
	: BMethodRequest(1043578866) 
	, istrms(istrms)
	, doNotReadStreamAtKey(doNotReadStreamAtKey)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteStreams_setImages::BSerializable_getTypeId() {
	return 2126615710; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteStreams_setImages::serialize(BIO& ar, const BVERSION version) {
	ar & this->doNotReadStreamAtKey;
	ar & this->istrms;
}
void byps::test::api::remote::BRequest_RemoteStreams_setImages::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteStreams __byps__remoteT = byps_ptr_cast<RemoteStreams>(__byps__remote);
	__byps__remoteT->setImages(istrms, doNotReadStreamAtKey, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_2126615710(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteStreams_setImages>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteStreams_setStreamDoNotMaterialize
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteStreams_setStreamDoNotMaterialize::BRequest_RemoteStreams_setStreamDoNotMaterialize() : BMethodRequest(1043578866) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteStreams_setStreamDoNotMaterialize::BRequest_RemoteStreams_setStreamDoNotMaterialize(const PContentStream& stream)
	: BMethodRequest(1043578866) 
	, stream(stream)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteStreams_setStreamDoNotMaterialize::BSerializable_getTypeId() {
	return 199832593; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteStreams_setStreamDoNotMaterialize::serialize(BIO& ar, const BVERSION version) {
	ar & this->stream;
}
void byps::test::api::remote::BRequest_RemoteStreams_setStreamDoNotMaterialize::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteStreams __byps__remoteT = byps_ptr_cast<RemoteStreams>(__byps__remote);
	__byps__remoteT->setStreamDoNotMaterialize(stream, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_199832593(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteStreams_setStreamDoNotMaterialize>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteStreams_throwLastException
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteStreams_throwLastException::BRequest_RemoteStreams_throwLastException() : BMethodRequest(1043578866) {
}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteStreams_throwLastException::BSerializable_getTypeId() {
	return 2127402965; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteStreams_throwLastException::serialize(BIO& ar, const BVERSION version) {
}
void byps::test::api::remote::BRequest_RemoteStreams_throwLastException::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteStreams __byps__remoteT = byps_ptr_cast<RemoteStreams>(__byps__remote);
	__byps__remoteT->throwLastException([__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_2127402965(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteStreams_throwLastException>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteWithAuthentication_doit
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteWithAuthentication_doit::BRequest_RemoteWithAuthentication_doit() : BMethodRequest(1983670399) {
	value = 0;
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteWithAuthentication_doit::BRequest_RemoteWithAuthentication_doit(int32_t value)
	: BMethodRequest(1983670399) 
	, value(value)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteWithAuthentication_doit::BSerializable_getTypeId() {
	return 1251509013; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteWithAuthentication_doit::serialize(BIO& ar, const BVERSION version) {
	ar & this->value;
	ar & this->sess;
}
void byps::test::api::remote::BRequest_RemoteWithAuthentication_doit::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteWithAuthentication __byps__remoteT = byps_ptr_cast<RemoteWithAuthentication>(__byps__remote);
	__byps__remoteT->doit(sess, value, [__byps__asyncResult](int32_t __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_5(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
// checkpoint byps.gen.cpp.GenApiClass:860
void byps::test::api::remote::BRequest_RemoteWithAuthentication_doit::setSession(const PSerializable& __byps__sess) {
	sess = byps_ptr_cast<byps::test::api::auth::SessionInfo>(__byps__sess);
}

}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_1251509013(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteWithAuthentication_doit>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteWithAuthentication_expire
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteWithAuthentication_expire::BRequest_RemoteWithAuthentication_expire() : BMethodRequest(1983670399) {
}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteWithAuthentication_expire::BSerializable_getTypeId() {
	return 72176172; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteWithAuthentication_expire::serialize(BIO& ar, const BVERSION version) {
	ar & this->sess;
}
void byps::test::api::remote::BRequest_RemoteWithAuthentication_expire::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteWithAuthentication __byps__remoteT = byps_ptr_cast<RemoteWithAuthentication>(__byps__remote);
	__byps__remoteT->expire(sess, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
// checkpoint byps.gen.cpp.GenApiClass:860
void byps::test::api::remote::BRequest_RemoteWithAuthentication_expire::setSession(const PSerializable& __byps__sess) {
	sess = byps_ptr_cast<byps::test::api::auth::SessionInfo>(__byps__sess);
}

}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_72176172(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteWithAuthentication_expire>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteWithAuthentication_login
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteWithAuthentication_login::BRequest_RemoteWithAuthentication_login() : BMethodRequest(1983670399) {
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteWithAuthentication_login::BRequest_RemoteWithAuthentication_login(const ::std::wstring& userName, const ::std::wstring& userPwd)
	: BMethodRequest(1983670399) 
	, userName(userName)
	, userPwd(userPwd)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteWithAuthentication_login::BSerializable_getTypeId() {
	return 134687724; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteWithAuthentication_login::serialize(BIO& ar, const BVERSION version) {
	ar & this->userName;
	ar & this->userPwd;
	ar & this->sess;
}
void byps::test::api::remote::BRequest_RemoteWithAuthentication_login::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteWithAuthentication __byps__remoteT = byps_ptr_cast<RemoteWithAuthentication>(__byps__remote);
	__byps__remoteT->login(sess, userName, userPwd, [__byps__asyncResult](byps::test::api::auth::PSessionInfo __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_65775978(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
// checkpoint byps.gen.cpp.GenApiClass:860
void byps::test::api::remote::BRequest_RemoteWithAuthentication_login::setSession(const PSerializable& __byps__sess) {
	sess = byps_ptr_cast<byps::test::api::auth::SessionInfo>(__byps__sess);
}

}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_134687724(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteWithAuthentication_login>(bio, pObj, pObjS, pBase);	
}
}}}
namespace byps { namespace test { namespace api { namespace remote { 

//-------------------------------------------------
// Implementation of class BRequest_RemoteWithAuthentication_setReloginCount
// Generated from class byps.gen.cpp.GenApiClass

// checkpoint byps.gen.cpp.GenApiClass:505
BRequest_RemoteWithAuthentication_setReloginCount::BRequest_RemoteWithAuthentication_setReloginCount() : BMethodRequest(1983670399) {
	count = 0;
}
// checkpoint byps.gen.cpp.GenApiClass:552
byps::test::api::remote::BRequest_RemoteWithAuthentication_setReloginCount::BRequest_RemoteWithAuthentication_setReloginCount(int32_t count)
	: BMethodRequest(1983670399) 
	, count(count)
	{}
// checkpoint byps.gen.cpp.PrintContext:496
BTYPEID byps::test::api::remote::BRequest_RemoteWithAuthentication_setReloginCount::BSerializable_getTypeId() {
	return 802968058; 
}
// checkpoint byps.gen.cpp.GenApiClass:892
void BRequest_RemoteWithAuthentication_setReloginCount::serialize(BIO& ar, const BVERSION version) {
	ar & this->count;
}
void byps::test::api::remote::BRequest_RemoteWithAuthentication_setReloginCount::execute(const PRemote& __byps__remote, PAsyncResult __byps__asyncResult) {
	PRemoteWithAuthentication __byps__remoteT = byps_ptr_cast<RemoteWithAuthentication>(__byps__remote);
	__byps__remoteT->setReloginCount(count, [__byps__asyncResult](bool __byps__result, const BException& __byps__ex) {
		if (__byps__ex) {
			__byps__asyncResult->setAsyncResult(BVariant(__byps__ex));
		}
		else {
			PSerializable __byps__methodResult(new BResult_19(__byps__result));
			__byps__asyncResult->setAsyncResult(BVariant(__byps__methodResult));
		}
	});
}
}}}}

// checkpoint byps.gen.cpp.GenApiClass:949
namespace byps { namespace test { namespace api { 
void BSerializer_802968058(BIO& bio, POBJECT& pObj, PSerializable& pObjS, void* pBase) {
	BSerializer_ObjS_Template<byps::test::api::remote::BRequest_RemoteWithAuthentication_setReloginCount>(bio, pObj, pObjS, pBase);	
}
}}}
