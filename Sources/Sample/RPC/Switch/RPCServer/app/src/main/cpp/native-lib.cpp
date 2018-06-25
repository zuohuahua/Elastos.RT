#include <jni.h>
#include <string>
#include <android/log.h>
#include <ela_session.h>
#include "elastos.h"
#include "elapi.h"
#include "ElastosCore.h"
#include "CCarrierListener.h"
#include "CSwitchListener.h"
#include "elastos/utility/etl/HashMap.h"
#include "Switch.h"

ICarrier* gCarrier = NULL;
IServiceManager* gServiceManager = NULL;

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved){
    ela_session_jni_onload(vm, reserved);
    return JNI_VERSION_1_6;
}


extern "C" JNIEXPORT void JNICALL Java_com_elastos_rpcserver_MainActivity_startCarrier(
        JNIEnv *env,
        jobject jobj,
        jstring path) {

        ECode ec = (ECode) _CCarrier_GetInstance(&gCarrier);
        if (FAILED(ec)) return;

        CCarrierListener* listener = new CCarrierListener(env, jobj);
        gCarrier->AddCarrierNodeListener(ICarrierListener::Probe(listener));

        const char* nativeString = env->GetStringUTFChars(path, nullptr);
        gCarrier->Start(String(nativeString));
        env->ReleaseStringUTFChars(path, nativeString);
}

extern "C" JNIEXPORT void JNICALL Java_com_elastos_rpcserver_MainActivity_stopCarrier(
        JNIEnv *env,
        jobject jobj) {
    if (gCarrier == NULL) return;

    gCarrier->Stop();
    gCarrier->Release();
    gCarrier = NULL;
}

extern "C" JNIEXPORT jint JNICALL Java_com_elastos_rpcserver_MainActivity_addFriend(
        JNIEnv *env,
        jobject jobj,
        jstring uid) {
    if (gCarrier == NULL) return -1;

    const char* nativeString = env->GetStringUTFChars(uid, nullptr);
    ECode ec = gCarrier->AddFriend(String(nativeString), String("hello"));
    env->ReleaseStringUTFChars(uid, nativeString);
    return ec;
}

extern "C" JNIEXPORT jint JNICALL Java_com_elastos_rpcserver_MainActivity_deleteFriend(
        JNIEnv *env,
        jobject jobj,
        jstring uid) {
    if (gCarrier == NULL) return -1;

    const char* nativeString = env->GetStringUTFChars(uid, nullptr);
    IFriend* pFriend;
    ECode ec = gCarrier->GetFriend(String(nativeString), &pFriend);
    if (FAILED(ec)) {
        env->ReleaseStringUTFChars(uid, nativeString);
        return ec;
    }

    ec = gCarrier->RemoveFriend(pFriend);
    pFriend->Release();
    env->ReleaseStringUTFChars(uid, nativeString);
    return ec;
}

extern "C" JNIEXPORT jobject JNICALL Java_com_elastos_rpcserver_MainActivity_getFriendList(
        JNIEnv *env,
        jobject jobj) {
    if (gCarrier == NULL) return NULL;

    ArrayOf<IFriend*>* friends = NULL;
    ECode ec = gCarrier->GetFriends(&friends);
    if (FAILED(ec) || friends == NULL) return NULL;

    jclass cls_ArrayList = env->FindClass("java/util/ArrayList");
    jmethodID construct = env->GetMethodID(cls_ArrayList, "<init>", "()V");
    jobject obj_ArrayList = env->NewObject(cls_ArrayList, construct,"");
    jmethodID arrayList_add = env->GetMethodID(cls_ArrayList, "add", "(Ljava/lang/Object;)Z");

    jclass cls_friend = env->FindClass("com/elastos/rpcserver/Friend");
    //none argument construct function
    jmethodID construct_user = env->GetMethodID(cls_friend, "<init>", "(Ljava/lang/String;Z)V");

    for (int i = 0; i < friends->GetLength(); i++) {
        IFriend* iFriend = (*friends)[i];

        String uid;
        iFriend->GetUid(&uid);
        Boolean online;
        iFriend->IsOnline(&online);
        jobject obj_friend = env->NewObject(cls_friend, construct_user, env->NewStringUTF(uid.string()), online);
        env->CallBooleanMethod(obj_ArrayList, arrayList_add, obj_friend);
    }

    friends->Release();

    return obj_ArrayList;
}


extern "C" JNIEXPORT jint JNICALL Java_com_elastos_rpcserver_MainActivity_acceptFriend(
        JNIEnv *env,
        jobject jobj,
        jstring uid) {
    if (gCarrier == NULL) return -1;

    const char* nativeString = env->GetStringUTFChars(uid, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "JNI", "accept friend %s", nativeString);
    ECode ec = gCarrier->AccpetFriendRequest(String(nativeString));
    env->ReleaseStringUTFChars(uid, nativeString);
    return ec;
}

extern "C" JNIEXPORT jstring JNICALL Java_com_elastos_rpcserver_MainActivity_getAddress(
        JNIEnv *env,
        jobject jobj) {
    if (gCarrier == NULL) return env->NewStringUTF("");

    String address;
    gCarrier->GetAddress(&address);
    return env->NewStringUTF(address.string());
}

extern "C" JNIEXPORT void JNICALL Java_com_elastos_rpcserver_MainActivity_startServiceManager(
        JNIEnv *env,
        jobject jobj) {
    if (gCarrier == NULL) return;
    if (gServiceManager != NULL) {
        return;
    }

    _CServiceManager_AcquireInstance(&gServiceManager);
}

extern "C" JNIEXPORT void JNICALL Java_com_elastos_rpcserver_MainActivity_stopServiceManager(
        JNIEnv *env,
        jobject jobj) {
    if (gServiceManager) {
        gServiceManager->Release();
        gServiceManager = NULL;
    }
}

extern "C" JNIEXPORT jint JNICALL Java_com_elastos_rpcserver_MainActivity_addService(
        JNIEnv *env,
        jobject jobj,
        jstring name) {
    if (gServiceManager == NULL) {
        __android_log_print(ANDROID_LOG_DEBUG, "JNI", "service manager not init");
        return -1;
    }

    ISwitch* pSwitch;
    ECode ec = CSwitch::New(&pSwitch);
    if (FAILED(ec)) return ec;

    CSwitchListener* listener = new CSwitchListener(env, jobj);
    pSwitch->SetSwitchListener(ISwitchListener::Probe(listener));

    const char* nativeString = env->GetStringUTFChars(name, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "JNI", "add service %s", nativeString);
    ec = gServiceManager->AddService(String(nativeString), pSwitch);
    env->ReleaseStringUTFChars(name, nativeString);
    pSwitch->Release();
    return ec;
}



