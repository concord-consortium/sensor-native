/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */


#ifdef __cplusplus
template<class T> class SwigValueWrapper {
    T *tt;
public:
    SwigValueWrapper() : tt(0) { }
    SwigValueWrapper(const SwigValueWrapper<T>& rhs) : tt(new T(*rhs.tt)) { }
    SwigValueWrapper(const T& t) : tt(new T(t)) { }
    ~SwigValueWrapper() { delete tt; } 
    SwigValueWrapper& operator=(const T& t) { delete tt; tt = new T(t); return *this; }
    operator T&() const { return *tt; }
    T *operator&() { return tt; }
private:
    SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
};
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC)
#   if (__SUNPRO_CC <= 0x560)
#     define SWIGTEMPLATEDISAMBIGUATOR template
#   else
#     define SWIGTEMPLATEDISAMBIGUATOR 
#   endif
# else
#   define SWIGTEMPLATEDISAMBIGUATOR 
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__)) 
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__)) 
# else
#   define SWIGUNUSED 
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif


/* Fix for jlong on some versions of gcc on Windows */
#if defined(__GNUC__) && !defined(__INTELC__)
  typedef long long __int64;
#endif

/* Fix for jlong on 64-bit x86 Solaris */
#if defined(__x86_64)
# ifdef _LP64
#   undef _LP64
# endif
#endif

#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" } };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  jenv->ExceptionClear();
  excep = jenv->FindClass(except_ptr->java_exception);
  if (excep)
    jenv->ThrowNew(excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else


#include "CCSensorDevice.h"

SWIGINTERN char *SensorConfig_getSensorParam(SensorConfig *self,char *key){
		int i;
		for(i=0; i < self->numSensorParams; i++) {
			SensorParam * param = (self->sensorParams) + i;
			if(!strcmp(param->key, key)) {
				return param->value;
			}
		}
		
		return NULL;
	}
SWIGINTERN SensorConfig *ExperimentConfig_getSensorConfig(ExperimentConfig *self,int i){
		return (self->sensorConfigArray) + i;
	}
SWIGINTERN void ExperimentConfig_createSensorConfigArray(ExperimentConfig *self,int size){
		self->sensorConfigArray = (SensorConfig*)malloc(sizeof(SensorConfig)*size);
	}
SWIGINTERN void ExperimentConfig_setSensorConfig(ExperimentConfig *self,SensorConfig *sConfig,int i){
		self->sensorConfigArray[i] = *sConfig;
	}


ExperimentConfig *getCurrentConfigHelper(SENSOR_DEVICE_HANDLE hDevice)
{
	ExperimentConfig *currentConfig;
	int err = SensDev_getCurrentConfig(hDevice, &currentConfig);
	if(err) {
		return 0;  // NULL
	}
	return currentConfig;
}

ExperimentConfig *configureHelper(SENSOR_DEVICE_HANDLE hDevice, ExperimentConfig *request)
{
	ExperimentConfig *response;
	response = NULL;
	int err = SensDev_configure(hDevice, request,&response);
	if(err) {
		return 0;  // NULL
	}
	return response;	
}



static float *new_floatArray(int nelements) { 
  return new float[nelements]; 
}

static void delete_floatArray(float *ary) { 
  delete [] ary; 
}

static float floatArray_getitem(float *ary, int index) {
    return ary[index];
}
static void floatArray_setitem(float *ary, int index, float value) {
    ary[index] = value;
}


#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorParam_1key_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  SensorParam *arg1 = (SensorParam *) 0 ;
  char *arg2 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorParam **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if (arg1->key) delete [] arg1->key;
    if (arg2) {
      arg1->key = (char *) (new char[strlen((const char *)arg2)+1]);
      strcpy((char *)arg1->key, (const char *)arg2);
    } else {
      arg1->key = 0;
    }
  }
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorParam_1key_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  SensorParam *arg1 = (SensorParam *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorParam **)&jarg1; 
  result = (char *) ((arg1)->key);
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorParam_1value_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  SensorParam *arg1 = (SensorParam *) 0 ;
  char *arg2 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorParam **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if (arg1->value) delete [] arg1->value;
    if (arg2) {
      arg1->value = (char *) (new char[strlen((const char *)arg2)+1]);
      strcpy((char *)arg1->value, (const char *)arg2);
    } else {
      arg1->value = 0;
    }
  }
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorParam_1value_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  SensorParam *arg1 = (SensorParam *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorParam **)&jarg1; 
  result = (char *) ((arg1)->value);
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_ccsd_vernier_NativeBridgeJNI_new_1SensorParam(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  SensorParam *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (SensorParam *)new SensorParam();
  *(SensorParam **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_delete_1SensorParam(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  SensorParam *arg1 = (SensorParam *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(SensorParam **)&jarg1; 
  delete arg1;
  
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1confirmed_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jshort jarg2) {
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  unsigned char arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  arg2 = (unsigned char)jarg2; 
  if (arg1) (arg1)->confirmed = arg2;
  
}


SWIGEXPORT jshort JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1confirmed_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jshort jresult = 0 ;
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  unsigned char result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  result = (unsigned char) ((arg1)->confirmed);
  jresult = (jshort)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1type_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->type = arg2;
  
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1type_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  result = (int) ((arg1)->type);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1stepSize_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jfloat jarg2) {
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  float arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  arg2 = (float)jarg2; 
  if (arg1) (arg1)->stepSize = arg2;
  
}


SWIGEXPORT jfloat JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1stepSize_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jfloat jresult = 0 ;
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  float result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  result = (float) ((arg1)->stepSize);
  jresult = (jfloat)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1requiredMax_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jfloat jarg2) {
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  float arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  arg2 = (float)jarg2; 
  if (arg1) (arg1)->requiredMax = arg2;
  
}


SWIGEXPORT jfloat JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1requiredMax_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jfloat jresult = 0 ;
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  float result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  result = (float) ((arg1)->requiredMax);
  jresult = (jfloat)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1requiredMin_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jfloat jarg2) {
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  float arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  arg2 = (float)jarg2; 
  if (arg1) (arg1)->requiredMin = arg2;
  
}


SWIGEXPORT jfloat JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1requiredMin_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jfloat jresult = 0 ;
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  float result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  result = (float) ((arg1)->requiredMin);
  jresult = (jfloat)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1port_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->port = arg2;
  
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1port_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  result = (int) ((arg1)->port);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1portName_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  char *arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if (arg2) strncpy((char *)arg1->portName, (const char *)arg2, 64);
    else arg1->portName[0] = 0;
  }
  
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1portName_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  result = (char *)(char *) ((arg1)->portName);
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1name_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  char *arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if (arg2) strncpy((char *)arg1->name, (const char *)arg2, 64);
    else arg1->name[0] = 0;
  }
  
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1name_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  result = (char *)(char *) ((arg1)->name);
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1unitStr_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  char *arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if (arg2) strncpy((char *)arg1->unitStr, (const char *)arg2, 32);
    else arg1->unitStr[0] = 0;
  }
  
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1unitStr_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  result = (char *)(char *) ((arg1)->unitStr);
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1numSensorParams_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->numSensorParams = arg2;
  
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1numSensorParams_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  result = (int) ((arg1)->numSensorParams);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1sensorParams_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  SensorParam *arg2 = (SensorParam *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(SensorConfig **)&jarg1; 
  arg2 = *(SensorParam **)&jarg2; 
  if (arg1) (arg1)->sensorParams = arg2;
  
}


SWIGEXPORT jlong JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1sensorParams_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  SensorParam *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  result = (SensorParam *) ((arg1)->sensorParams);
  *(SensorParam **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensorConfig_1getSensorParam(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  jstring jresult = 0 ;
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  char *arg2 = (char *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(SensorConfig **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return 0;
  }
  result = (char *)SensorConfig_getSensorParam(arg1,arg2);
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_ccsd_vernier_NativeBridgeJNI_new_1SensorConfig(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  SensorConfig *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (SensorConfig *)new SensorConfig();
  *(SensorConfig **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_delete_1SensorConfig(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  SensorConfig *arg1 = (SensorConfig *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(SensorConfig **)&jarg1; 
  delete arg1;
  
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1valid_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jshort jarg2) {
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  unsigned char arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  arg2 = (unsigned char)jarg2; 
  if (arg1) (arg1)->valid = arg2;
  
}


SWIGEXPORT jshort JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1valid_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jshort jresult = 0 ;
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  unsigned char result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  result = (unsigned char) ((arg1)->valid);
  jresult = (jshort)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1invalidReason_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  char *arg2 = (char *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if (arg1->invalidReason) delete [] arg1->invalidReason;
    if (arg2) {
      arg1->invalidReason = (char *) (new char[strlen((const char *)arg2)+1]);
      strcpy((char *)arg1->invalidReason, (const char *)arg2);
    } else {
      arg1->invalidReason = 0;
    }
  }
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1invalidReason_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  result = (char *) ((arg1)->invalidReason);
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1period_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jfloat jarg2) {
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  float arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  arg2 = (float)jarg2; 
  if (arg1) (arg1)->period = arg2;
  
}


SWIGEXPORT jfloat JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1period_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jfloat jresult = 0 ;
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  float result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  result = (float) ((arg1)->period);
  jresult = (jfloat)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1exactPeriodUChar_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jshort jarg2) {
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  unsigned char arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  arg2 = (unsigned char)jarg2; 
  if (arg1) (arg1)->exactPeriod = arg2;
  
}


SWIGEXPORT jshort JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1exactPeriodUChar_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jshort jresult = 0 ;
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  unsigned char result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  result = (unsigned char) ((arg1)->exactPeriod);
  jresult = (jshort)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1numberOfSamples_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  long arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  arg2 = (long)jarg2; 
  if (arg1) (arg1)->numberOfSamples = arg2;
  
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1numberOfSamples_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  long result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  result = (long) ((arg1)->numberOfSamples);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1dataReadPeriod_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jfloat jarg2) {
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  float arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  arg2 = (float)jarg2; 
  if (arg1) (arg1)->dataReadPeriod = arg2;
  
}


SWIGEXPORT jfloat JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1dataReadPeriod_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jfloat jresult = 0 ;
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  float result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  result = (float) ((arg1)->dataReadPeriod);
  jresult = (jfloat)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1deviceName_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  char *arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return ;
  }
  {
    if (arg2) strncpy((char *)arg1->deviceName, (const char *)arg2, 64);
    else arg1->deviceName[0] = 0;
  }
  
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
}


SWIGEXPORT jstring JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1deviceName_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  result = (char *)(char *) ((arg1)->deviceName);
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1numSensorConfigs_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  arg2 = (int)jarg2; 
  if (arg1) (arg1)->numSensorConfigs = arg2;
  
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1numSensorConfigs_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jint jresult = 0 ;
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  result = (int) ((arg1)->numSensorConfigs);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1sensorConfigArray_1set(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_) {
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  SensorConfig *arg2 = (SensorConfig *) 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  arg2 = *(SensorConfig **)&jarg2; 
  if (arg1) (arg1)->sensorConfigArray = arg2;
  
}


SWIGEXPORT jlong JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1sensorConfigArray_1get(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  SensorConfig *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  result = (SensorConfig *) ((arg1)->sensorConfigArray);
  *(SensorConfig **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1getSensorConfig(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  jlong jresult = 0 ;
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  int arg2 ;
  SensorConfig *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  arg2 = (int)jarg2; 
  result = (SensorConfig *)ExperimentConfig_getSensorConfig(arg1,arg2);
  *(SensorConfig **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1createSensorConfigArray(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jint jarg2) {
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  int arg2 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  arg2 = (int)jarg2; 
  ExperimentConfig_createSensorConfigArray(arg1,arg2);
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_ExperimentConfig_1setSensorConfig(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jobject jarg2_, jint jarg3) {
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  SensorConfig *arg2 = (SensorConfig *) 0 ;
  int arg3 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  (void)jarg2_;
  arg1 = *(ExperimentConfig **)&jarg1; 
  arg2 = *(SensorConfig **)&jarg2; 
  arg3 = (int)jarg3; 
  ExperimentConfig_setSensorConfig(arg1,arg2,arg3);
}


SWIGEXPORT jlong JNICALL Java_ccsd_vernier_NativeBridgeJNI_new_1ExperimentConfig(JNIEnv *jenv, jclass jcls) {
  jlong jresult = 0 ;
  ExperimentConfig *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (ExperimentConfig *)new ExperimentConfig();
  *(ExperimentConfig **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_delete_1ExperimentConfig(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  ExperimentConfig *arg1 = (ExperimentConfig *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(ExperimentConfig **)&jarg1; 
  delete arg1;
  
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_QUANTITY_1UNKNOWN_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  QuantityType result;
  
  (void)jenv;
  (void)jcls;
  result = (QuantityType)QUANTITY_UNKNOWN;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensDev_1open(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  jlong jresult = 0 ;
  char *arg1 = (char *) 0 ;
  SENSOR_DEVICE_HANDLE result;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return 0;
  }
  result = (SENSOR_DEVICE_HANDLE)SensDev_open(arg1);
  *(SENSOR_DEVICE_HANDLE *)&jresult = result; 
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensDev_1close(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
  result = (int)SensDev_close(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensDev_1isAttached(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
  result = (int)SensDev_isAttached(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensDev_1configure(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jobject jarg2_, jlong jarg3) {
  jint jresult = 0 ;
  SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
  ExperimentConfig *arg2 = (ExperimentConfig *) 0 ;
  ExperimentConfig **arg3 = (ExperimentConfig **) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
  arg2 = *(ExperimentConfig **)&jarg2; 
  arg3 = *(ExperimentConfig ***)&jarg3; 
  result = (int)SensDev_configure(arg1,arg2,arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensDev_1canDetectSensors(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
  result = (int)SensDev_canDetectSensors(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensDev_1getCurrentConfig(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
  ExperimentConfig **arg2 = (ExperimentConfig **) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
  arg2 = *(ExperimentConfig ***)&jarg2; 
  result = (int)SensDev_getCurrentConfig(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensDev_1start(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
  result = (int)SensDev_start(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensDev_1stop(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
  result = (int)SensDev_stop(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_ccsd_vernier_NativeBridgeJNI_SensDev_1read(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3, jint jarg4) {
  jint jresult = 0 ;
  SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
  float *arg2 = (float *) 0 ;
  float *arg3 = (float *) 0 ;
  int arg4 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
  arg2 = *(float **)&jarg2; 
  arg3 = *(float **)&jarg3; 
  arg4 = (int)jarg4; 
  result = (int)SensDev_read(arg1,arg2,arg3,arg4);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_ccsd_vernier_NativeBridgeJNI_getCurrentConfigHelper(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jlong jresult = 0 ;
  SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
  ExperimentConfig *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
  result = (ExperimentConfig *)getCurrentConfigHelper(arg1);
  *(ExperimentConfig **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_ccsd_vernier_NativeBridgeJNI_configureHelper(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jobject jarg2_) {
  jlong jresult = 0 ;
  SENSOR_DEVICE_HANDLE arg1 = (SENSOR_DEVICE_HANDLE) 0 ;
  ExperimentConfig *arg2 = (ExperimentConfig *) 0 ;
  ExperimentConfig *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg2_;
  arg1 = *(SENSOR_DEVICE_HANDLE *)&jarg1; 
  arg2 = *(ExperimentConfig **)&jarg2; 
  result = (ExperimentConfig *)configureHelper(arg1,arg2);
  *(ExperimentConfig **)&jresult = result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_ccsd_vernier_NativeBridgeJNI_new_1floatArray(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jlong jresult = 0 ;
  int arg1 ;
  float *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  result = (float *)new_floatArray(arg1);
  *(float **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_delete_1floatArray(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  float *arg1 = (float *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(float **)&jarg1; 
  delete_floatArray(arg1);
}


SWIGEXPORT jfloat JNICALL Java_ccsd_vernier_NativeBridgeJNI_floatArray_1getitem(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
  jfloat jresult = 0 ;
  float *arg1 = (float *) 0 ;
  int arg2 ;
  float result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(float **)&jarg1; 
  arg2 = (int)jarg2; 
  result = (float)floatArray_getitem(arg1,arg2);
  jresult = (jfloat)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_ccsd_vernier_NativeBridgeJNI_floatArray_1setitem(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2, jfloat jarg3) {
  float *arg1 = (float *) 0 ;
  int arg2 ;
  float arg3 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(float **)&jarg1; 
  arg2 = (int)jarg2; 
  arg3 = (float)jarg3; 
  floatArray_setitem(arg1,arg2,arg3);
}


#ifdef __cplusplus
}
#endif

