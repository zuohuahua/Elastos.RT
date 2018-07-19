
package org.elastos.Elastos.AutoGenerateJavaCodes;

import java.util.Calendar;
import java.util.Random;

//this java class will implement the elastos interface.
public class CTestCar implements ITestCar {
    static {
        System.loadLibrary("Elastos.Runtime");
        System.loadLibrary("Elastos.CoreLibrary");
        System.loadLibrary("Elastos.AutoGenerateJavaCodes");
        //TODO : Your jni so, please fill it.
        System.loadLibrary("Your_Jni");
    }

    private static final String CLASS_ID_PREFIX = "org.elastos.Elastos.AutoGenerateJavaCodes.CTestCar.";
    private String mClassId;

    private native void native_CTestCar(double[] dArray, String[] sArray);
    private native void native_CTestCar(IServiceManager sm, ICarrier carrier);
    private native void native_CTestCar_Destroy();

    public CTestCar(double[] dArray, String[] sArray) {
        Random rand = new Random();
        mClassId = CLASS_ID_PREFIX + rand.nextInt() + Calendar.getInstance().getTimeInMillis();
        native_CTestCar(dArray, sArray);
        //TODO: Add your code here
    }

    public CTestCar(IServiceManager sm, ICarrier carrier) {
        Random rand = new Random();
        mClassId = CLASS_ID_PREFIX + rand.nextInt() + Calendar.getInstance().getTimeInMillis();
        native_CTestCar(sm, carrier);
        //TODO: Add your code here
    }

    // invoke destroy to release car object
    public void destroy() {
        native_CTestCar_Destroy();
    }

    public String getClassId() {
        return mClassId;
    }


    public void SetInt(
        /* [in] */ int value) {
        //TODO: Add your code here
    }

    public int GetInt() {
        //TODO: Add your code here
        return 0;
    }

    public void SetString(
        /* [in] */ String value) {
        //TODO: Add your code here
    }

    public String GetString() {
        //TODO: Add your code here
        return "NULL";
    }

    public void Normal() {
        //TODO: Add your code here
    }

    public void Test1(
        /* [in] */ int value1,
        /* [in] */ boolean value2,
        /* [in] */ float value3,
        /* [in] */ double value4,
        /* [in] */ long value5,
        /* [in] */ byte value6,
        /* [in] */ char value7,
        /* [in] */ String value8) {
        //TODO: Add your code here
    }

    public int Test2(
        /* [in] */ int value1,
        /* [in] */ boolean value2,
        /* [in] */ float value3,
        /* [in] */ double value4,
        /* [in] */ long value5,
        /* [in] */ byte value6,
        /* [in] */ char value7,
        /* [in] */ String value8,
        /* [in] */ String value9,
        /* [in] */ String value10) {
        //TODO: Add your code here
        return 0;
    }

    public void Test7(
        /* [in] */ IHelloCar animal) {
        //TODO: Add your code here
    }

    public IHelloCar Test8() {
        //TODO: Add your code here
        return null;
    }

    public void Test9(
        /* [in] */ ICarrier[] carriers) {
        //TODO: Add your code here
    }

    public ICarrier[] Test10() {
        //TODO: Add your code here
        return null;
    }


}
