
//TODO : Modify the package and the final user will call this class' method.
package elastos.org.xxx;

public class CTestCarUser {
    static {
        System.loadLibrary("Elastos.Runtime");
        System.loadLibrary("Elastos.CoreLibrary");
        System.loadLibrary("Elastos.AutoGenerateJavaCodes");
        //TODO : Your jni so, please fill it.
        System.loadLibrary("Your_Jni");
    }

    private int mCarObj = 0;

    public native int nativeInit();
    public native void nativeDestroy(int carobj);

    public CTestCarUser() {
        mCarObj = nativeInit();
        //TODO: Add your code here
    }

    // invoke destroy to release car object
    public void destroy(){
        nativeDestroy(mCarObj);
    }


    public void SetInt(
        /* [in] */ int value)
    {
        nativeSetInt(mCarObj, value);
    }

    private native void nativeSetInt(int carobj, int value);

    public int GetInt()
    {
        return nativeGetInt(mCarObj);
    }

    private native int nativeGetInt(int carobj);

    public void SetString(
        /* [in] */ String value)
    {
        nativeSetString(mCarObj, value);
    }

    private native void nativeSetString(int carobj, String value);

    public String GetString()
    {
        return nativeGetString(mCarObj);
    }

    private native String nativeGetString(int carobj);

    public void Normal()
    {
        nativeNormal();
    }

    private native void nativeNormal(int carobj);

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
        nativeTest1(mCarObj, value1, value2, value3, value4, value5, value6, value7, value8);
    }

    private native void nativeTest1(int carobj, int value1, boolean value2, float value3, double value4, long value5, byte value6, char value7, String value8);

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
        return nativeTest2(mCarObj, value1, value2, value3, value4, value5, value6, value7, value8, value9, value10);
    }

    private native int nativeTest2(int carobj, int value1, boolean value2, float value3, double value4, long value5, byte value6, char value7, String value8, String value9, String value10);


    public void SetInt2(
        /* [in] */ int value)
    {
        nativeSetInt2(mCarObj, value);
    }

    private native void nativeSetInt2(int carobj, int value);

    public String Update(
        /* [in] */ String value1,
        /* [in] */ String value2,
        /* [in] */ String value3)
    {
        return nativeUpdate(mCarObj, value1, value2, value3);
    }

    private native String nativeUpdate(int carobj, String value1, String value2, String value3);


}
