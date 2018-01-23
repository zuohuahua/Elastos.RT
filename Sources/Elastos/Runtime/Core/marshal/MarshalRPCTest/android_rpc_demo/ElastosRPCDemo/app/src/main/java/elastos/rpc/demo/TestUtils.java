package elastos.rpc.demo;

public class TestUtils {

    static {
        System.loadLibrary("Elastos.Runtime");
        System.loadLibrary("Elastos.CoreLibrary");
        System.loadLibrary("Elastos.RpcDemoClient");
        System.loadLibrary("eladroidrpc");
    }

    private static native boolean nativeConnect(String ip, boolean isServer);
    private static native String nativeGetTag();
    private static native boolean nativeSetTag(String tag);

    public static boolean Connect(String ip, boolean isServer) {
        return nativeConnect(ip, isServer);
    }

    public static String GetTag() {
        return nativeGetTag();
    }

    public static boolean SetTag(String tag) {
        return nativeSetTag(tag);
    }
}
