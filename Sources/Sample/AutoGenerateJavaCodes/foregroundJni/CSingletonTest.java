
package org.elastos.Elastos.AutoGenerateJavaCodes;

//TODO : Modify the package and the final user will call this class' method.
public class CSingletonTest {
    private native long native_CSingletonTest();
    private native void native_CSingletonTest_Destroy(long carobj);

    private static class CSingletonTestHelper {
        private static final CSingletonTest INSTANCE = new CSingletonTest();
    }

    public static CSingletonTest getInstance() {
        return CSingletonTestHelper.INSTANCE;
    }

    private CSingletonTest() {
        mCarObj = native_CSingletonTest();
        //TODO: Add your code here
    }

    public long getCarObject() {
        return mCarObj;
    }

    // invoke destroy to release car object
    public void destroy() {
        native_CSingletonTest_Destroy(mCarObj);
    }


    public void SetInt2(
        /* [in] */ int value)
    {
        native_CSingletonTest_ITestCar2_SetInt2(mCarObj, value);
    }

    private native void native_CSingletonTest_ITestCar2_SetInt2(long carobj, int value);

    public String Update(
        /* [in] */ String value1,
        /* [in] */ String value2,
        /* [in] */ String value3)
    {
        return native_CSingletonTest_ITestCar2_Update(mCarObj, value1, value2, value3);
    }

    private native String native_CSingletonTest_ITestCar2_Update(long carobj, String value1, String value2, String value3);

    public void Test1(
        /* [in] */ String name,
        /* [in] */ int[] array)
    {
        native_CSingletonTest_ITestCar2_Test1(mCarObj, name, array);
    }

    private native void native_CSingletonTest_ITestCar2_Test1(long carobj, String name, int[] array);

    public void Test2(
        /* [in] */ String[] strArray,
        /* [in] */ int[] intArray)
    {
        native_CSingletonTest_ITestCar2_Test2(mCarObj, strArray, intArray);
    }

    private native void native_CSingletonTest_ITestCar2_Test2(long carobj, String[] strArray, int[] intArray);

    public String[] Test3(
        /* [in] */ int i)
    {
        return native_CSingletonTest_ITestCar2_Test3(mCarObj, i);
    }

    private native String[] native_CSingletonTest_ITestCar2_Test3(long carobj, int i);

    public void Test4()
    {
        native_CSingletonTest_ITestCar2_Test4(mCarObj);
    }

    private native void native_CSingletonTest_ITestCar2_Test4(long carobj);

    public String Test5()
    {
        return native_CSingletonTest_ITestCar2_Test5(mCarObj);
    }

    private native String native_CSingletonTest_ITestCar2_Test5(long carobj);

    public float[] Test6(
        /* [in] */ int i,
        /* [in] */ String str)
    {
        return native_CSingletonTest_ITestCar2_Test6(mCarObj, i, str);
    }

    private native float[] native_CSingletonTest_ITestCar2_Test6(long carobj, int i, String str);


}
