package elastos.rpc.demo;

import android.util.Log;

public class TestUtils {

    static {
//        System.loadLibrary("log");
//        System.loadLibrary("elacommon");
//        System.loadLibrary("elasession");
//        System.loadLibrary("elacarrier");
//        System.loadLibrary("Elastos.Runtime");
//        System.loadLibrary("Elastos.CoreLibrary");
//        System.loadLibrary("Elastos.RpcDemoClient");
//        System.loadLibrary("eladroidrpc");
    }

    private static native void nativeSendMsg(String msg);
    public static void SendMsg(String msg) {
        Log.d("TestUtils", "SendMsg==============================");
        nativeSendMsg(msg);
    }

    private static native boolean nativeConnect(String ip, boolean isServer);
    public static boolean Connect(String ip, boolean isServer) {
        return nativeConnect(ip, isServer);
    }

    private static native String nativeGetAddress(boolean isSelf);
    public static String GetAddress(boolean isSelf) {
        return nativeGetAddress(isSelf);
    }
    public static String GetAddress() {
        return GetAddress(false);
    }

    private static native String nativeGetFriendUserId();
    public static String GetFriendUserId() {
        return nativeGetFriendUserId();
    }

    private static native void nativeAddFriend(String address, String hello);
    public static void AddFriend(String address, String hello) {
        nativeAddFriend(address, hello);
    }

    public class ElaConnectionStatus {
        public static final int Disconnected = 0;
        public static final int Connected = 1;
    };

    public interface CarrierNodeListener {
        void OnConnectionStatus(
            /* [in] */ int status);

        void OnReady();

        void OnFriendConnection(
        /* [in] */ String friendid,
        /* [in] */ int status);

        void OnFriendRequest(
        /* [in] */ String userid,
        /* [in] */ String hello);

        void OnFreindAdded(
        /* [in] */ String userid);

        void OnFriendMessage(
        /* [in] */ String from,
        /* [in] */ String msg);
    }
}
