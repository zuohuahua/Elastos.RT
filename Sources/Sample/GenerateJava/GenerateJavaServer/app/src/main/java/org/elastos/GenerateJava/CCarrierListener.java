
package org.elastos.GenerateJava;

import android.os.Bundle;
import android.os.Message;

import org.elastos.generatejavaserver.MainActivity;

//this java class will implement the elastos interface.
public class CCarrierListener implements ICarrierListener {
    private long mCarObj = 0;
    private MainActivity mActivity;

    private native long native_CCarrierListener();
    private native void native_CCarrierListener_Destroy(long carobj);

    public CCarrierListener(MainActivity activity) {
        mCarObj = native_CCarrierListener();
        mActivity = activity;
    }

    public long getCarObject() {
        return mCarObj;
    }

    // invoke destroy to release car object
    public void destroy() {
        native_CCarrierListener_Destroy(mCarObj);
        mActivity = null;
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


}
