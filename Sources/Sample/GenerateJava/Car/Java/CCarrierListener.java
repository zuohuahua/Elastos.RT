
package org.elastos.GenerateJava;

import java.util.Calendar;
import java.util.Random;

//this java class will implement the elastos interface.
public class CCarrierListener implements ICarrierListener {
    private static final String CLASS_ID_PREFIX = "org.elastos.GenerateJava.CCarrierListener.";
    private String mClassId;

    private native void native_CCarrierListener();
    private native void native_CCarrierListener_Destroy();

    public CCarrierListener() {
        Random rand = new Random();
        mClassId = CLASS_ID_PREFIX + rand.nextInt() + Calendar.getInstance().getTimeInMillis();
        native_CCarrierListener();
        //TODO: Add your code here
    }

    // invoke destroy to release car object
    public void destroy() {
        native_CCarrierListener_Destroy();
    }

    public String getClassId() {
        return mClassId;
    }


    public void OnIdle() {
        //TODO: Add your code here
    }

    public void OnConnectionChanged(
        /* [in] */ boolean online) {
        //TODO: Add your code here
    }

    public void OnReady() {
        //TODO: Add your code here
    }

    public void OnFriendRequest(
        /* [in] */ String uid,
        /* [in] */ String hello) {
        //TODO: Add your code here
    }

    public void OnFriendConnetionChanged(
        /* [in] */ String uid,
        /* [in] */ boolean online) {
        //TODO: Add your code here
    }

    public boolean OnPortForwardingRequest(
        /* [in] */ String uid,
        /* [in] */ String servicePort) {
        //TODO: Add your code here
        return false;
    }

    public void OnPortForwardingResult(
        /* [in] */ String uid,
        /* [in] */ String localPort,
        /* [in] */ String remotePort,
        /* [in] */ int code) {
        //TODO: Add your code here
    }

    public void OnMessageReceived(
        /* [in] */ String uid,
        /* [in] */ byte[] message) {
        //TODO: Add your code here
    }


}
