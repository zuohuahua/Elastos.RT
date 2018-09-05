
package org.elastos.GenerateJava;

//this java interface define the elastos interface.
public interface ICarrierListener {

    public void OnIdle();

    public void OnConnectionChanged(
        /* [in] */ boolean online);

    public void OnReady();

    public void OnFriendRequest(
        /* [in] */ String uid,
        /* [in] */ String hello);

    public void OnFriendConnectionChanged(
        /* [in] */ String uid,
        /* [in] */ boolean online);

    public boolean OnPortForwardingRequest(
        /* [in] */ String uid,
        /* [in] */ String servicePort);

    public void OnPortForwardingResult(
        /* [in] */ String uid,
        /* [in] */ String localPort,
        /* [in] */ String remotePort,
        /* [in] */ int code);

    public void OnMessageReceived(
        /* [in] */ String uid,
        /* [in] */ byte[] message);

}

