
package org.elastos.GenerateJava;

import java.util.Calendar;
import java.util.Random;

//this java class will implement the elastos interface.
public class CHelloJava implements IHelloJava {
    static {
        System.loadLibrary("Elastos.Runtime");
        System.loadLibrary("Elastos.CoreLibrary");
        System.loadLibrary("GenerateJava");
    }

    private static final String CLASS_ID_PREFIX = "org.elastos.GenerateJava.CHelloJava.";
    private String mClassId;

    private native void native_CHelloJava();
    private native void native_CHelloJava_Destroy();

    public CHelloJava() {
        Random rand = new Random();
        mClassId = CLASS_ID_PREFIX + rand.nextInt() + Calendar.getInstance().getTimeInMillis();
        native_CHelloJava();
        //TODO: Add your code here
    }

    // invoke destroy to release car object
    public void destroy() {
        native_CHelloJava_Destroy();
    }

    public String getClassId() {
        return mClassId;
    }


    public String Hello() {
        //TODO: Add your code here
        return "NULL";
    }


}
