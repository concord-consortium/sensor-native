package ccsd.pseudo;

/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version: 1.3.21
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class NativeBridge implements NativeBridgeConstants {
  public static SWIGTYPE_p_void SensDev_open(String configString) {
    long cPtr = NativeBridgeJNI.SensDev_open(configString);
    return (cPtr == 0) ? null : new SWIGTYPE_p_void(cPtr, false);
  }

  public static int SensDev_close(SWIGTYPE_p_void hDevice) {
    return NativeBridgeJNI.SensDev_close(SWIGTYPE_p_void.getCPtr(hDevice));
  }

  public static int SensDev_isAttached(SWIGTYPE_p_void hDevice) {
    return NativeBridgeJNI.SensDev_isAttached(SWIGTYPE_p_void.getCPtr(hDevice));
  }

  public static int SensDev_configure(SWIGTYPE_p_void hDevice, ExperimentConfig request, SWIGTYPE_p_p_ExperimentConfig response) {
    return NativeBridgeJNI.SensDev_configure(SWIGTYPE_p_void.getCPtr(hDevice), ExperimentConfig.getCPtr(request), SWIGTYPE_p_p_ExperimentConfig.getCPtr(response));
  }

  public static int SensDev_canDetectSensors(SWIGTYPE_p_void hDevice) {
    return NativeBridgeJNI.SensDev_canDetectSensors(SWIGTYPE_p_void.getCPtr(hDevice));
  }

  public static int SensDev_getCurrentConfig(SWIGTYPE_p_void hDevice, SWIGTYPE_p_p_ExperimentConfig current) {
    return NativeBridgeJNI.SensDev_getCurrentConfig(SWIGTYPE_p_void.getCPtr(hDevice), SWIGTYPE_p_p_ExperimentConfig.getCPtr(current));
  }

  public static int SensDev_start(SWIGTYPE_p_void hDevice) {
    return NativeBridgeJNI.SensDev_start(SWIGTYPE_p_void.getCPtr(hDevice));
  }

  public static int SensDev_stop(SWIGTYPE_p_void hDevice) {
    return NativeBridgeJNI.SensDev_stop(SWIGTYPE_p_void.getCPtr(hDevice));
  }

  public static int SensDev_read(SWIGTYPE_p_void hDevice, SWIGTYPE_p_float samples, SWIGTYPE_p_float timestamps, int length) {
    return NativeBridgeJNI.SensDev_read(SWIGTYPE_p_void.getCPtr(hDevice), SWIGTYPE_p_float.getCPtr(samples), SWIGTYPE_p_float.getCPtr(timestamps), length);
  }

  public static ExperimentConfig getCurrentConfigHelper(SWIGTYPE_p_void hDevice) {
    long cPtr = NativeBridgeJNI.getCurrentConfigHelper(SWIGTYPE_p_void.getCPtr(hDevice));
    return (cPtr == 0) ? null : new ExperimentConfig(cPtr, false);
  }

  public static ExperimentConfig configureHelper(SWIGTYPE_p_void hDevice, ExperimentConfig request) {
    long cPtr = NativeBridgeJNI.configureHelper(SWIGTYPE_p_void.getCPtr(hDevice), ExperimentConfig.getCPtr(request));
    return (cPtr == 0) ? null : new ExperimentConfig(cPtr, false);
  }

  public static SWIGTYPE_p_float new_floatArray(int nelements) {
    long cPtr = NativeBridgeJNI.new_floatArray(nelements);
    return (cPtr == 0) ? null : new SWIGTYPE_p_float(cPtr, false);
  }

  public static void delete_floatArray(SWIGTYPE_p_float ary) {
    NativeBridgeJNI.delete_floatArray(SWIGTYPE_p_float.getCPtr(ary));
  }

  public static float floatArray_getitem(SWIGTYPE_p_float ary, int index) {
    return NativeBridgeJNI.floatArray_getitem(SWIGTYPE_p_float.getCPtr(ary), index);
  }

  public static void floatArray_setitem(SWIGTYPE_p_float ary, int index, float value) {
    NativeBridgeJNI.floatArray_setitem(SWIGTYPE_p_float.getCPtr(ary), index, value);
  }

}
