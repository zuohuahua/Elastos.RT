
package org.elastos.GenerateJava;

//this java interface define the elastos interface.
public interface ICarrierListener {

    public void OnConnectionChanged(
        /* [in] */ boolean online);

    public void OnReady();

    public void OnFriendRequest(
        /* [in] */ String uid,
        /* [in] */ String hello);

    public void OnFriendConnetionChanged(
        /* [in] */ String uid,
        /* [in] */ boolean online);

}

