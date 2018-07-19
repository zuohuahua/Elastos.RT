
package org.elastos.Elastos.AutoGenerateJavaCodes;

import java.util.Calendar;
import java.util.Random;

//TODO : Modify the package and the final user will call this class' method.
public class CSingletonTest {
    private static final String CLASS_ID_PREFIX = "org.elastos.Elastos.AutoGenerateJavaCodes.CSingletonTest.";
    private String mClassId;

    private native void native_CSingletonTest();
    private native void native_CSingletonTest_Destroy();

    private static class CSingletonTestHelper {
        private static final CSingletonTest INSTANCE = new CSingletonTest();
    }

    public static CSingletonTest getInstance() {
        return CSingletonTestHelper.INSTANCE;
    }

    private CSingletonTest() {
        Random rand = new Random();
        mClassId = CLASS_ID_PREFIX + rand.nextInt() + Calendar.getInstance().getTimeInMillis();
        native_CSingletonTest();
        //TODO: Add your code here
    }

    // invoke destroy to release car object
    public void destroy() {
        native_CSingletonTest_Destroy();
    }

    public String getClassId() {
        return mClassId;
    }


    public void SetInt2(
        /* [in] */ int value)
    {
        native_CSingletonTest_ITestCar2_SetInt2(value);
    }

    private native void native_CSingletonTest_ITestCar2_SetInt2(int value);

    public String Update(
        /* [in] */ String value1,
        /* [in] */ String value2,
        /* [in] */ String value3)
    {
        return native_CSingletonTest_ITestCar2_Update(value1, value2, value3);
    }

    private native String native_CSingletonTest_ITestCar2_Update(String value1, String value2, String value3);

    public void Test1(
        /* [in] */ String name,
        /* [in] */ int[] array)
    {
        native_CSingletonTest_ITestCar2_Test1(name, array);
    }

    private native void native_CSingletonTest_ITestCar2_Test1(String name, int[] array);

    public void Test2(
        /* [in] */ String[] strArray,
        /* [in] */ int[] intArray)
    {
        native_CSingletonTest_ITestCar2_Test2(strArray, intArray);
    }

    private native void native_CSingletonTest_ITestCar2_Test2(String[] strArray, int[] intArray);

    public String[] Test3(
        /* [in] */ int i)
    {
        return native_CSingletonTest_ITestCar2_Test3(i);
    }

    private native String[] native_CSingletonTest_ITestCar2_Test3(int i);

    public void Test4()
    {
        native_CSingletonTest_ITestCar2_Test4();
    }

    private native void native_CSingletonTest_ITestCar2_Test4();

    public String Test5()
    {
        return native_CSingletonTest_ITestCar2_Test5();
    }

    private native String native_CSingletonTest_ITestCar2_Test5();

    public float[] Test6(
        /* [in] */ int i,
        /* [in] */ String str)
    {
        return native_CSingletonTest_ITestCar2_Test6(i, str);
    }

    private native float[] native_CSingletonTest_ITestCar2_Test6(int i, String str);


}
