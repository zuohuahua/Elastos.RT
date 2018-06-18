
package org.elastos.Elastos.AutoGenerateJavaCodes;

//this java class will implement the elastos interface.
public class CTestCar implements ITestCar, ITestCar2 {
    static {
        System.loadLibrary("Elastos.Runtime");
        System.loadLibrary("Elastos.CoreLibrary");
        System.loadLibrary("Elastos.AutoGenerateJavaCodes");
        //TODO : Your jni so, please fill it.
        System.loadLibrary("Your_Jni");
    }

    private long mCarObj = 0;

    private native long nativeInit();
    private native void nativeDestroy(long carobj);

    public CTestCar() {
        mCarObj = nativeInit();
        //TODO: Add your code here
    }

    public long getCarObject() {
        return mCarObj;
    }

    // invoke destroy to release car object
    public void destroy() {
        nativeDestroy(mCarObj);
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


    public void SetInt2(
        /* [in] */ int value) {
        //TODO: Add your code here
    }

    public String Update(
        /* [in] */ String value1,
        /* [in] */ String value2,
        /* [in] */ String value3) {
        //TODO: Add your code here
        return "NULL";
    }


}
