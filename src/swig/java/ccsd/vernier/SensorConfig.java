/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package ccsd.vernier;

public class SensorConfig implements 
	org.concord.sensor.SensorConfig
 {
  private long swigCPtr;
  protected boolean swigCMemOwn;

  protected SensorConfig(long cPtr, boolean cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = cPtr;
  }

  protected static long getCPtr(SensorConfig obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      NativeBridgeJNI.delete_SensorConfig(swigCPtr);
    }
    swigCPtr = 0;
  }

	public boolean isConfirmed()
	{
		return getConfirmed() == 1;
	}
	
	public org.concord.framework.data.DataDimension getUnit()
	{
		return new org.concord.sensor.impl.SensorUnit(getUnitStr());
	}

  public void setConfirmed(short value) {
    NativeBridgeJNI.SensorConfig_confirmed_set(swigCPtr, this, value);
  }

  public short getConfirmed() {
    return NativeBridgeJNI.SensorConfig_confirmed_get(swigCPtr, this);
  }

  public void setType(int value) {
    NativeBridgeJNI.SensorConfig_type_set(swigCPtr, this, value);
  }

  public int getType() {
    return NativeBridgeJNI.SensorConfig_type_get(swigCPtr, this);
  }

  public void setStepSize(float value) {
    NativeBridgeJNI.SensorConfig_stepSize_set(swigCPtr, this, value);
  }

  public float getStepSize() {
    return NativeBridgeJNI.SensorConfig_stepSize_get(swigCPtr, this);
  }

  public void setRequiredMax(float value) {
    NativeBridgeJNI.SensorConfig_requiredMax_set(swigCPtr, this, value);
  }

  public float getRequiredMax() {
    return NativeBridgeJNI.SensorConfig_requiredMax_get(swigCPtr, this);
  }

  public void setRequiredMin(float value) {
    NativeBridgeJNI.SensorConfig_requiredMin_set(swigCPtr, this, value);
  }

  public float getRequiredMin() {
    return NativeBridgeJNI.SensorConfig_requiredMin_get(swigCPtr, this);
  }

  public void setPort(int value) {
    NativeBridgeJNI.SensorConfig_port_set(swigCPtr, this, value);
  }

  public int getPort() {
    return NativeBridgeJNI.SensorConfig_port_get(swigCPtr, this);
  }

  public void setPortName(String value) {
    NativeBridgeJNI.SensorConfig_portName_set(swigCPtr, this, value);
  }

  public String getPortName() {
    return NativeBridgeJNI.SensorConfig_portName_get(swigCPtr, this);
  }

  public void setName(String value) {
    NativeBridgeJNI.SensorConfig_name_set(swigCPtr, this, value);
  }

  public String getName() {
    return NativeBridgeJNI.SensorConfig_name_get(swigCPtr, this);
  }

  public void setUnitStr(String value) {
    NativeBridgeJNI.SensorConfig_unitStr_set(swigCPtr, this, value);
  }

  public String getUnitStr() {
    return NativeBridgeJNI.SensorConfig_unitStr_get(swigCPtr, this);
  }

  public void setNumSensorParams(int value) {
    NativeBridgeJNI.SensorConfig_numSensorParams_set(swigCPtr, this, value);
  }

  public int getNumSensorParams() {
    return NativeBridgeJNI.SensorConfig_numSensorParams_get(swigCPtr, this);
  }

  public void setSensorParams(SensorParam value) {
    NativeBridgeJNI.SensorConfig_sensorParams_set(swigCPtr, this, SensorParam.getCPtr(value), value);
  }

  public SensorParam getSensorParams() {
    long cPtr = NativeBridgeJNI.SensorConfig_sensorParams_get(swigCPtr, this);
    return (cPtr == 0) ? null : new SensorParam(cPtr, false);
  }

  public String getSensorParam(String key) {
    return NativeBridgeJNI.SensorConfig_getSensorParam(swigCPtr, this, key);
  }

  public SensorConfig() {
    this(NativeBridgeJNI.new_SensorConfig(), true);
  }

}
