
package org.elastos.GenerateJava;

//this java class will implement the elastos interface.
public class CHelloJava implements IHelloJava {
    static {
        System.loadLibrary("Elastos.Runtime");
        System.loadLibrary("Elastos.CoreLibrary");
        System.loadLibrary("GenerateJava");
        //TODO : Your jni so, please fill it.
        System.loadLibrary("Your_Jni");
    }

    private long mCarObj = 0;

    private native long native_CHelloJava();
    private native void native_CHelloJava_Destroy(long carobj);

    public CHelloJava() {
        mCarObj = native_CHelloJava();
        //TODO: Add your code here
    }

    public long getCarObject() {
        return mCarObj;
    }

    // invoke destroy to release car object
    public void destroy() {
        native_CHelloJava_Destroy(mCarObj);
    }


    public String Hello() {
        //TODO: Add your code here
        return "NULL";
    }


}
