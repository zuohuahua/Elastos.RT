
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

    private native void native_CHelloJava();
    private native void native_CHelloJava_Destroy();

    public CHelloJava() {
        native_CHelloJava();
        //TODO: Add your code here
    }

    // invoke destroy to release car object
    public void destroy() {
        native_CHelloJava_Destroy();
    }


    public String Hello() {
        //TODO: Add your code here
        return "NULL";
    }


}
