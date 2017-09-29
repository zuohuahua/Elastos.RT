package elastos.china.com.eldroidsdk;

/**
 * Created by wanli on 17-9-28.
 */

public class ElDroidOS {
    static {
        System.loadLibrary("Elastos.Runtime");   //defaultConfig.ndk.moduleName
        System.loadLibrary("Elastos.CoreLibrary");   //defaultConfig.ndk.moduleName
        System.loadLibrary("ElastosSimpleLib");   //defaultConfig.ndk.moduleName
    }

    static public native String getElastosString();
}
