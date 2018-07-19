
package org.elastos.GenerateJava;

import android.os.Bundle;
import android.os.Message;

import org.elastos.generatejavaclient.MainActivity;

import java.util.Calendar;
import java.util.Random;

//this java class will implement the elastos interface.
public class CCarrierListener implements ICarrierListener {
    private MainActivity mActivity;

    private static final String CLASS_ID_PREFIX = "org.elastos.GenerateJava.CCarrierListener.";
    private String mClassId;

    private native void native_CCarrierListener();
    private native void native_CCarrierListener_Destroy();

    public CCarrierListener(MainActivity activity) {
        Random rand = new Random();
        mClassId = CLASS_ID_PREFIX + rand.nextInt() + Calendar.getInstance().getTimeInMillis();
        native_CCarrierListener();
        mActivity = activity;
    }

    // invoke destroy to release car object
    public void destroy() {
        native_CCarrierListener_Destroy();
        mActivity = null;
    }

    public String getClassId() {
        return mClassId;
    }


    public void OnIdle() {
        //TODO: Add your code here
    }

    public void OnConnectionChanged(
        /* [in] */ boolean online) {
        Message msg = new Message();
        msg.what = MainActivity.MSG_CONNECT_CHANGED;
        Bundle bundle = new Bundle();
        bundle.putBoolean("connection", online);
        msg.setData(bundle);
        mActivity.mHandler.sendMessage(msg);

    }

    public void OnReady() {
        //TODO: Add your code here
    }

    public void OnFriendRequest(
        /* [in] */ String uid,
        /* [in] */ String hello) {
        Message msg = new Message();
        msg.what = MainActivity.MSG_FRIEND_REQUEST;
        Bundle bundle = new Bundle();
        bundle.putString("friendUid", uid);
        bundle.putString("friendHello", hello);
        msg.setData(bundle);
        mActivity.mHandler.sendMessage(msg);
    }

    public void OnFriendConnetionChanged(
        /* [in] */ String uid,
        /* [in] */ boolean online) {
        Message msg = new Message();
        msg.what = MainActivity.MSG_FRIEND_CHANGED;
        Bundle bundle = new Bundle();
        bundle.putString("friendUid", uid);
        bundle.putBoolean("friendOnline", online);
        msg.setData(bundle);
        mActivity.mHandler.sendMessage(msg);
    }

    public boolean OnPortForwardingRequest(
            /* [in] */ String uid,
            /* [in] */ String servicePort) {
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
