package org.elastos.runtime.sample.helloelastos;

/**
 * Created by wanli on 17-10-25.
 */

public class TestUtils {

    static {
        System.loadLibrary("Elastos.Runtime");
        System.loadLibrary("Elastos.CoreLibrary");
        System.loadLibrary("Elastos.HelloCarDemo");
        System.loadLibrary("testThirdLib");
    }

    private static native String nativeGetTestString();

    private static native String nativeGetHelloCarString();

    public String getTestString() {
        return nativeGetTestString();
    }

    public String getHelloCarString() {
        return nativeGetHelloCarString();
    }
}
