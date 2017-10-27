package org.elastos.elastosrtsdk;

/**
 * Created by wanli on 17-9-28.
 */

public class HelloCarDemo {
    static {
        System.loadLibrary("Elastos.Runtime");
        System.loadLibrary("Elastos.CoreLibrary");
        System.loadLibrary("Elastos.HelloCarDemo");
        System.loadLibrary("HelloCar");
    }

    public HelloCarDemo() {
        mNativeProxy = nativeCreateElastosHelloCar();
    }

    protected void finalize() throws Throwable {
        if (mNativeProxy != 0) {
            nativeFinalize(mNativeProxy);
            mNativeProxy = 0;
        }
    }

    public String hello() {
    	return nativeHelloCar(mNativeProxy);
    }

	private static native long nativeCreateElastosHelloCar();
	private static native void nativeFinalize(long nativeProxy);
    private static native String nativeHelloCar(long nativeProxy);

    private long mNativeProxy;
}
