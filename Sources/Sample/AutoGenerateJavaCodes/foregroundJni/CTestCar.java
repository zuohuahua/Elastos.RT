
package org.elastos.Elastos.AutoGenerateJavaCodes;

//TODO : Modify the package and the final user will call this class' method.
public class CTestCar {
    static {
        System.loadLibrary("Elastos.Runtime");
        System.loadLibrary("Elastos.CoreLibrary");
        System.loadLibrary("Elastos.AutoGenerateJavaCodes");
        //TODO : Your jni so, please fill it.
        System.loadLibrary("Your_Jni");
    }

    private native void native_CTestCar(double[] dArray, String[] sArray);
    private native void native_CTestCar(IServiceManager sm, ICarrier carrier);
    private native void native_CTestCar_Destroy();

    public CTestCar(double[] dArray, String[] sArray) {
        native_CTestCar(dArray, sArray);
        //TODO: Add your code here
    }

    public CTestCar(IServiceManager sm, ICarrier carrier) {
        native_CTestCar(sm, carrier);
        //TODO: Add your code here
    }

    // invoke destroy to release car object
    public void destroy() {
        native_CTestCar_Destroy();
    }


    public void SetInt(
        /* [in] */ int value)
    {
        native_CTestCar_ITestCar_SetInt(value);
    }

    private native void native_CTestCar_ITestCar_SetInt(int value);

    public int GetInt()
    {
        return native_CTestCar_ITestCar_GetInt();
    }

    private native int native_CTestCar_ITestCar_GetInt();

    public void SetString(
        /* [in] */ String value)
    {
        native_CTestCar_ITestCar_SetString(value);
    }

    private native void native_CTestCar_ITestCar_SetString(String value);

    public String GetString()
    {
        return native_CTestCar_ITestCar_GetString();
    }

    private native String native_CTestCar_ITestCar_GetString();

    public void Normal()
    {
        native_CTestCar_ITestCar_Normal();
    }

    private native void native_CTestCar_ITestCar_Normal();

    public void Test1(
        /* [in] */ int value1,
        /* [in] */ boolean value2,
        /* [in] */ float value3,
        /* [in] */ double value4,
        /* [in] */ long value5,
        /* [in] */ byte value6,
        /* [in] */ char value7,
        /* [in] */ String value8)
    {
        native_CTestCar_ITestCar_Test1(value1, value2, value3, value4, value5, value6, value7, value8);
    }

    private native void native_CTestCar_ITestCar_Test1(int value1, boolean value2, float value3, double value4, long value5, byte value6, char value7, String value8);

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
        /* [in] */ String value10)
    {
        return native_CTestCar_ITestCar_Test2(value1, value2, value3, value4, value5, value6, value7, value8, value9, value10);
    }

    private native int native_CTestCar_ITestCar_Test2(int value1, boolean value2, float value3, double value4, long value5, byte value6, char value7, String value8, String value9, String value10);

    public void Test7(
        /* [in] */ IHelloCar animal)
    {
        native_CTestCar_ITestCar_Test7(animal);
    }

    private native void native_CTestCar_ITestCar_Test7(IHelloCar animal);

    public IHelloCar Test8()
    {
        return native_CTestCar_ITestCar_Test8();
    }

    private native IHelloCar native_CTestCar_ITestCar_Test8();

    public void Test9(
        /* [in] */ ICarrier[] carriers)
    {
        native_CTestCar_ITestCar_Test9(carriers);
    }

    private native void native_CTestCar_ITestCar_Test9(ICarrier[] carriers);

    public ICarrier[] Test10()
    {
        return native_CTestCar_ITestCar_Test10();
    }

    private native ICarrier[] native_CTestCar_ITestCar_Test10();


}
