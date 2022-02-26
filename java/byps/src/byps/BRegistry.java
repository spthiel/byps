package byps;

/* USE THIS FILE ACCORDING TO THE COPYRIGHT RULES IN LICENSE.TXT WHICH IS PART OF THE SOURCE CODE PACKAGE */

import java.io.InputStream;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

public abstract class BRegistry {

  public final static int TYPEID_BOOL = 1;
  public final static int TYPEID_INT8 = 2;
  public final static int TYPEID_INT16 = 3;
  public final static int TYPEID_WCHAR = 4;
  public final static int TYPEID_INT32 = 5;
  public final static int TYPEID_INT64 = 6;
  public final static int TYPEID_FLOAT = 7;
  public final static int TYPEID_DOUBLE = 8;

  public final static int TYPEID_STRING = 10;
  // public final static int TYPEID_WSTRING = 11; unused, Strings are always transported as UTF-8

  public final static int TYPEID_LIST = 12;
  public final static int TYPEID_MAP = 13;
  public final static int TYPEID_SET = 14;
  public final static int TYPEID_STREAM = 15;
  public final static int TYPEID_STUB = 16;
  public final static int TYPEID_DATE = 17;
  public final static int TYPEID_VOID = 19;
  public final static int TYPEID_EXCEPTION = 20;
  public final static int TYPEID_OBJECT = 21;
  public final static int TYPEID_VALUECLASS = 22;
  public final static int TYPEID_PUBLISH_CLIENT = 23;
  public final static int TYPEID_HTTP_REQUEST = 24; // Used by bypshttp-shmem
  public final static int TYPEID_HEADER = 30;

  public final static int TYPEID_STRING_UTF16 = TYPEID_STRING;

  public final static int TYPEID_MIN_USER = 64;

  public final BBinaryModel bmodel;
  
  private Map<Class<?>, BSerializer> classToSerializer = Collections.synchronizedMap(new HashMap<Class<?>, BSerializer>());
  
  /**
   * Use this class loader to lookup serializer classes.
   * BYPS-62
   */
  private ClassLoader classLoader;
  
  public BRegistry(BBinaryModel bmodel) {
    this.bmodel = bmodel;
    
    Class<?> thisClass = this.getClass();
    this.classLoader = thisClass.getClassLoader();
  }

  public int getMinTypeIdUser() {
    return TYPEID_MIN_USER;
  }

  public int getMaxTypeIdUser() {
    return getMaxTypeId();
  }

  public final int getMaxTypeId() {
    if (bmodel == BBinaryModel.JSON) return Integer.MAX_VALUE;
    if (bmodel == BBinaryModel.MEDIUM) return Integer.MAX_VALUE;
    // if (bmodel == BBinaryModel.SMALL) return Short.MAX_VALUE;
    // if (bmodel == BBinaryModel.TINY) return Byte.MAX_VALUE;
    // if (bmodel == BBinaryModel.LARGE) return Integer.MAX_VALUE;
    throw new IllegalStateException();
  }

  @SuppressWarnings("unchecked")
  protected BSerializer internalGetSerializer(int typeId) throws BException {
    BSerializer ser = null;
    if (typeId >= TYPEID_MIN_USER) {
      BRegisteredSerializer[] ssers = getSortedSerializers();
      
      // BYPS-22: binary search was implemented badly. Replaced by Arrays.binarySearch.
      
      int index = Arrays.binarySearch(ssers, BRegisteredSerializer.makeCompareKey(typeId));
      if (index >= 0) {
        BRegisteredSerializer rser = ssers[index];
        if (rser.instance == null) {
          Class<BSerializer> c;
          try {
            c = (Class<BSerializer>)loadClass(rser.name);
            Constructor<BSerializer> constr = c.getConstructor();
            rser.instance = constr.newInstance();
          } catch (Exception e) {
            throw new BException(BExceptionC.CORRUPT, "No serializer for typeId=" + typeId);
          }
        }
        ser = rser.instance;
      }
    }
    else {
      ser = getBuiltInSerializer(typeId);
    }
    return ser;
  }
  
  /**
   * Load class by {@link #classLoader}.
   * @param className
   * @return class object
   * @throws ClassNotFoundException
   * 
   * BYPS-62
   */
  protected Class<?> loadClass(String className) throws ClassNotFoundException {
    return classLoader.loadClass(className);
  }

  public BSerializer getSerializer(int typeId) throws BException {
    BSerializer ser = internalGetSerializer(typeId);
    if (ser != null) return ser;
    throw new BException(BExceptionC.CORRUPT, "No serializer for typeId=" + typeId);
  }
  
  public BSerializer getSerializer(Object obj, boolean throwEx) throws BException {
    Class<?> clazz = obj.getClass();
    BSerializer ser = classToSerializer.get(clazz);
    try {
      
      if (ser == null) {

        int typeId = 0; 

        while (clazz != Object.class) {
  
          if (clazz == InputStream.class) {
            typeId = BRegistry.TYPEID_STREAM;
            break;
          }
  
          try {
            Field field = clazz.getDeclaredField("serialVersionUID");
            field.setAccessible(true);
            long longTypeId = field.getLong(obj);
            typeId = (int) (longTypeId & getMaxTypeId());
            break;
          } catch (NoSuchFieldException e) {
            clazz = clazz.getSuperclass();
          }
        }
      
        ser = getSerializer(typeId);
        classToSerializer.put(clazz, ser);
      }
      
    } catch (Exception e) {
      if (throwEx) {
        throw new BException(BExceptionC.CORRUPT, "No serializer for className=" + clazz.getName() + ". " + "Only classes marked with BSerializable can be serialized as \"Object\" types. "
            + "This error occurs e. g. if a List<Object> contains String values. String is not a BSerializable.");
      }
    }

    return ser;

    // else if (obj instanceof BRemote) {
    // String stubName = makeStubName(clazz.getName());
    // try {
    // Class<?> stubClazz = Class.forName(stubName);
    // Field field = stubClazz.getDeclaredField("serialVersionUID");
    // field.setAccessible(true);
    // long longTypeId = field.getLong(null);
    // int typeId = (int)(longTypeId & maxTypeId);
    // ser = getSerializer(typeId);
    // mapClassToSerializer.put(clazz, ser);
    // } catch (Exception e) {
    // throw BException.createNoSerializer(clazz.getName(), e);
    // }
    // }

    // This function can only be called for objects that inherit from BSerializable.
    // Other objects cannot be exported anonymously. For those objects, the 
    // BSerializer object has to be supplied in writeObject.
    
    // This limitation is required, because it is not possible to get 
    // the type information from Generic arguments in Java. 
    // E.g. you cannot distinguish between List<String> or List<Long> at
    // runtime.
    
    // This function has to work for BRemote respectively BSkeleton too. 
    // That's why we do not check whether the passed object implements
    // BSerializable. Only the field serialVersionUID is evaluated.
    
  }

  protected static class BRegisteredSerializer implements Comparable<BRegisteredSerializer> {
    public int typeId;
    public String name;
    public BSerializer instance;

    public BRegisteredSerializer(int typeId, String name) {
      this.typeId = typeId;
      this.name = name;
    }

    @Override
    public int compareTo(BRegisteredSerializer rhs) {
      return this.typeId - rhs.typeId;
    }
    
    public static BRegisteredSerializer makeCompareKey(int typeId) {
      return new BRegisteredSerializer(typeId, "");
    }
  }

  protected abstract BRegisteredSerializer[] getSortedSerializers();

  private BSerializer getBuiltInSerializer(int typeId) throws BException {
    if (bmodel == BBinaryModel.JSON) {
      if (typeId == TYPEID_LIST) return JSerializer_12.instance;
      if (typeId == TYPEID_MAP) return JSerializer_13.instance;
      if (typeId == TYPEID_SET) return JSerializer_14.instance;
      if (typeId == TYPEID_EXCEPTION) return JSerializer_20.instance;
      if (typeId == TYPEID_STREAM) return JSerializer_15.instance;
      if (typeId == TYPEID_VALUECLASS) return JSerializer_22.instance;
    }
    else {
      if (typeId == TYPEID_LIST) return BSerializer_12.instance;
      if (typeId == TYPEID_MAP) return BSerializer_13.instance;
      if (typeId == TYPEID_SET) return BSerializer_14.instance;
      if (typeId == TYPEID_EXCEPTION) return BSerializer_20.instance;
      if (typeId == TYPEID_STREAM) return BSerializer_15.instance;
      if (typeId == TYPEID_HTTP_REQUEST) return BSerializer_24.instance;
      if (typeId == TYPEID_VALUECLASS) return BSerializer_22.instance;
    }
    return null;
  }

  public boolean isPointerTypeId(long typeId) {
    if (typeId >= TYPEID_MIN_USER) return true;
    if (typeId == TYPEID_OBJECT) return true;
    if (typeId == TYPEID_HEADER) return true;
    if (typeId == TYPEID_EXCEPTION) return true;
    if (typeId == TYPEID_LIST) return true;
    if (typeId == TYPEID_MAP) return true;
    if (typeId == TYPEID_SET) return true;
    if (typeId == TYPEID_STREAM) return true;
    if (typeId == TYPEID_HTTP_REQUEST) return true;
    return false;
  }

  public boolean replaceSerializer(BSerializer bser) {
    BRegisteredSerializer[] ssers = getSortedSerializers();
    for (BRegisteredSerializer sser : ssers) {
      if (sser.typeId == bser.typeId) {
        sser.instance = bser;
        return true;
      }
    }
    return false;
  }

  public ClassLoader getClassLoader() {
    return classLoader;
  }

  public void setClassLoader(ClassLoader classLoader) {
    this.classLoader = classLoader;
  }
  
}
