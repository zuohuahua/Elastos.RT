
#include <jni.h>
#include<android/log.h>

//For Elastos
#include <elastos/core/Object.h>
#include "Elastos.RpcDemoClient.Export.h"
//#include "CarrierNodeListener.h"

#define TAG "Elastos_RPC_Log" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

using Elastos::Core::Object;
using Elastos::RpcDemoClient::CRpcDemoClient;
using Elastos::RpcDemoClient::IRpcDemoClient;
using Elastos::RpcDemoClient::ElaConnectionStatus;
using Elastos::RpcDemoClient::ICarrierNodeListener;
using Elastos::RpcDemoClient::ElaConnectionStatus_Connected;

#define JNIREG_CLASS "elastos/rpc/demo/TestUtils"
#define JNIREG_CLASS_CARRIER "elastos/rpc/demo/MainActivity"

class CarrierNodeListener
    : public Object
    , public ICarrierNodeListener
{
public:
    CAR_INTERFACE_DECL()

    CarrierNodeListener(
        /* [in] */ JNIEnv* env,
        /* [in] */ jobject jobj);

    ~CarrierNodeListener();

    CARAPI OnConnectionStatus(
        /* [in] */ ElaConnectionStatus status);

    CARAPI OnReady();

    CARAPI OnFriendConnection(
        /* [in] */ const String& friendid,
        /* [in] */ ElaConnectionStatus status);

    CARAPI OnFriendRequest(
        /* [in] */ const String& userid,
        /* [in] */ const String& hello);

    CARAPI OnFreindAdded(
        /* [in] */ const String& userid);

    CARAPI OnFriendMessage(
        /* [in] */ const String& from,
        /* [in] */ const String& msg);

private:
    JNIEnv* GetEnv();
    void Detach();

private:
    JavaVM* mVM;
    jobject mObj;
};

static AutoPtr<IRpcDemoClient> sRpcDemoClient;
static AutoPtr<CarrierNodeListener> sCarrierNodeListener;
static jstring JNICALL nativeGetAddress(JNIEnv *env, jobject jobj, jboolean isSelf)
{
    if (sRpcDemoClient == NULL) {
        return env->NewStringUTF("nativeGetAddress NULL");
    }

    String address;
    sRpcDemoClient->GetAddress(isSelf, &address);
    LOGD("nativeGetAddress===================address=[%s]", address.string());
    return env->NewStringUTF(address.string());
}

static jboolean JNICALL nativeConnect(JNIEnv *env, jobject jobj, jstring jip, jboolean isServer)
{
    const char* ip;
    ip = env->GetStringUTFChars(jip, NULL);
    if (sRpcDemoClient == NULL) {
        CRpcDemoClient::New((IRpcDemoClient**)&sRpcDemoClient);
    }
    assert(sRpcDemoClient != NULL);

    Boolean succeed = FALSE;
    sRpcDemoClient->Connect(String(ip), isServer ? TRUE : FALSE, &succeed);
    return (jboolean)succeed;
}

static jstring JNICALL nativeGetHelloCarString(JNIEnv *env, jobject jobj)
{
    return env->NewStringUTF(NULL);
}

static void JNICALL nativeAddFriend(JNIEnv *env, jobject jobj, jstring jAddress, jstring jHello)
{
    const char* address;
    address = env->GetStringUTFChars(jAddress, NULL);
    const char* hello;
    hello = env->GetStringUTFChars(jHello, NULL);
    LOGD("nativeAddFriend===================address=[%s]", address);
    assert(sRpcDemoClient != NULL);

    sRpcDemoClient->AddFriend(String(address),String(hello));
}

static void JNICALL nativeSendMsg(JNIEnv *env, jobject jobj, jstring jmsg)
{
    LOGD("nativeSetMsg===================");
    const char* msg;
    msg = env->GetStringUTFChars(jmsg, NULL);
    assert(sRpcDemoClient != NULL);

    sRpcDemoClient->SendMsg(String(msg));
}

static jstring JNICALL nativeGetFriendUserId(JNIEnv *env, jobject jobj)
{
    if (sRpcDemoClient == NULL) {
        return env->NewStringUTF("nativeGetFriendUserId NULL");
    }

    String userid;
    sRpcDemoClient->GetUserId(&userid);
    LOGD("nativeGetFriendUserId===================userid=[%s]", userid.string());
    return env->NewStringUTF(userid.string());
}

static void JNICALL nativeInitRpcClient(JNIEnv *env, jobject jobj)
{
    if (sRpcDemoClient == NULL) {
        CRpcDemoClient::New((IRpcDemoClient**)&sRpcDemoClient);
    }

    sCarrierNodeListener = new CarrierNodeListener(env, jobj);
    sRpcDemoClient->SetCarrierNodeListener(sCarrierNodeListener);
}

static const JNINativeMethod gMethods[] = {
    {"nativeConnect", "(Ljava/lang/String;Z)Z", (void*)nativeConnect},
    {"nativeGetAddress", "(Z)Ljava/lang/String;", (void*)nativeGetAddress},
    {"nativeGetFriendUserId", "()Ljava/lang/String;", (void*)nativeGetFriendUserId},
    {"nativeSendMsg", "(Ljava/lang/String;)V", (void*)nativeSendMsg},
    {"nativeAddFriend", "(Ljava/lang/String;Ljava/lang/String;)V", (void*)nativeAddFriend},
};

static void JNICALL nativeInitCarrierNodeListener(JNIEnv *env, jobject jobj)
{
    LOGD("nativeInitCarrierNodeListener===================env=====[%p]", env);
    // sCarrierNodeListener = new CarrierNodeListener(env, jobj);
}

static const JNINativeMethod gCarrierMethods[] = {
    {"nativeInitCarrierNodeListener", "()V", (void*)nativeInitCarrierNodeListener},
    {"nativeInitRpcClient", "()V", (void*)nativeInitRpcClient},
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved){
    JNIEnv * env;
    jclass cls;
    jint result = -1;
    if(vm->GetEnv((void **)&env,JNI_VERSION_1_6) != JNI_OK){
        return JNI_ERR;
    }

    //TestUtils
    cls = env->FindClass(JNIREG_CLASS);
    env->RegisterNatives(cls, gMethods, sizeof(gMethods)/sizeof(JNINativeMethod));

    //Listener
    jclass cls2 = env->FindClass(JNIREG_CLASS_CARRIER);
    env->RegisterNatives(cls2, gCarrierMethods, sizeof(gCarrierMethods)/sizeof(JNINativeMethod));
    return JNI_VERSION_1_6;
}


using Elastos::RpcDemoClient::EIID_ICarrierNodeListener;
CAR_INTERFACE_IMPL(CarrierNodeListener, Object, ICarrierNodeListener)
CarrierNodeListener::CarrierNodeListener(
    /* [in] */ JNIEnv* env,
    /* [in] */ jobject jobj)
{
    mObj = env->NewGlobalRef(jobj);
    env->GetJavaVM(&mVM);
}

CarrierNodeListener::~CarrierNodeListener()
{
    if (mObj) {
        GetEnv()->DeleteGlobalRef(mObj);
    }
}

JNIEnv* CarrierNodeListener::GetEnv()
{
    JNIEnv* env;
    assert(mVM != NULL);
    mVM->AttachCurrentThread(&env, NULL);
    return env;
}

void CarrierNodeListener::Detach()
{
    assert(mVM != NULL);
    mVM->DetachCurrentThread();
}

ECode CarrierNodeListener::OnConnectionStatus(
    /* [in] */ ElaConnectionStatus status)
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d]", __FUNCTION__, __LINE__);
    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnConnectionStatus","(I)V");
    Int32 sta = 0;
    if (status == ElaConnectionStatus_Connected) {
        sta = 1;
    }
    env->CallVoidMethod(mObj, methodId, sta);

    Detach();
    return NOERROR;
}

ECode CarrierNodeListener::OnReady()
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d], pid=[%d]", __FUNCTION__, __LINE__, gettid());

    assert(mObj != NULL);
    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnReady","()V");
    env->CallVoidMethod(mObj, methodId);
    Detach();
    return NOERROR;
}

ECode CarrierNodeListener::OnFriendConnection(
    /* [in] */ const String& friendid,
    /* [in] */ ElaConnectionStatus status)
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d]", __FUNCTION__, __LINE__);

    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnFriendConnection","(Ljava/lang/String;I)V");
    jstring userid = env->NewStringUTF(friendid.string());
    Int32 sta = 0;
    if (status == ElaConnectionStatus_Connected) {
        sta = 1;
    }
    env->CallVoidMethod(mObj, methodId, userid, sta);
    Detach();
    return NOERROR;
}

ECode CarrierNodeListener::OnFriendRequest(
    /* [in] */ const String& userid,
    /* [in] */ const String& hello)
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d], userid=[%s], hello=[%s]",
        __FUNCTION__, __LINE__, userid.string(), hello.string());

    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnFriendRequest","(Ljava/lang/String;Ljava/lang/String;)V");
    jstring jUserid = env->NewStringUTF(userid.string());
    jstring jHello = env->NewStringUTF(hello.string());
    env->CallVoidMethod(mObj, methodId, jUserid, jHello);
    Detach();

    return NOERROR;
}

ECode CarrierNodeListener::OnFreindAdded(
    /* [in] */ const String& userid)
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d], userid=[%s]",
        __FUNCTION__, __LINE__, userid.string());

    JNIEnv* env = GetEnv();

    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnFreindAdded","(Ljava/lang/String;)V");
    jstring jUserid = env->NewStringUTF(userid.string());
    env->CallVoidMethod(mObj, methodId, jUserid);

    Detach();
    return NOERROR;
}

ECode CarrierNodeListener::OnFriendMessage(
    /* [in] */ const String& from,
    /* [in] */ const String& msg)
{
    LOGD("CarrierNodeListener==================func=[%s], line=[%d], from=[%s], msg=[%s]",
        __FUNCTION__, __LINE__, from.string(), msg.string());

    JNIEnv* env = GetEnv();
    jclass clazz = env->GetObjectClass(mObj);
    jmethodID methodId = env->GetMethodID(clazz,"OnFriendMessage","(Ljava/lang/String;Ljava/lang/String;)V");
    jstring jFrom = env->NewStringUTF(from.string());
    jstring jMsg = env->NewStringUTF(msg.string());
    env->CallVoidMethod(mObj, methodId, jFrom, jMsg);

    Detach();
    return NOERROR;
}
