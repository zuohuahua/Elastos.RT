
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

    public static void InitRegClassPath(String regClassPath)
    {
        nativeInit(regClassPath);
    }

    private static native void nativeInit(String regClassPath);

    public static void SetInt(
        /* [in] */ int value)
    {
        nativeSetInt(value);
    }

    private static native void nativeSetInt(int value);

    public static int GetInt()
    {
        return nativeGetInt();
    }

    private static native int nativeGetInt();

    public static void SetString(
        /* [in] */ String value)
    {
        nativeSetString(value);
    }

    private static native void nativeSetString(String value);

    public static String GetString()
    {
        return nativeGetString();
    }

    private static native String nativeGetString();

    public static void Normal()
    {
        nativeNormal();
    }

    private static native void nativeNormal();

    public static void Test1(
        /* [in] */ int value1,
        /* [in] */ boolean value2,
        /* [in] */ float value3,
        /* [in] */ double value4,
        /* [in] */ long value5,
        /* [in] */ byte value6,
        /* [in] */ char value7,
        /* [in] */ String value8)
    {
        nativeTest1(value1, value2, value3, value4, value5, value6, value7, value8);
    }

    private static native void nativeTest1(int value1, boolean value2, float value3, double value4, long value5, byte value6, char value7, String value8);

    public static int Test2(
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
        return nativeTest2(value1, value2, value3, value4, value5, value6, value7, value8, value9, value10);
    }

    private static native int nativeTest2(int value1, boolean value2, float value3, double value4, long value5, byte value6, char value7, String value8, String value9, String value10);


    public static void SetInt2(
        /* [in] */ int value)
    {
        nativeSetInt2(value);
    }

    private static native void nativeSetInt2(int value);

    public static String Update(
        /* [in] */ String value1,
        /* [in] */ String value2,
        /* [in] */ String value3)
    {
        return nativeUpdate(value1, value2, value3);
    }

    private static native String nativeUpdate(String value1, String value2, String value3);


}
