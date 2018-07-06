
#include <jni.h>
#include <string>
#include <android/log.h>
#include "elastos.h"
#include "elastos/core/Object.h"
#include "elapi.h"
#include "ElastosCore.h"
#include "elastos/utility/etl/HashMap.h"
#include "GenerateJava.h"

ICarrier* gCarrier = NULL;
IServiceManager* gServiceManager = NULL;

Elastos::Utility::Etl::HashMap<String, IHelloJava*> gInterfaces;

extern "C" JNIEXPORT void JNICALL Java_org_elastos_generatejavaclient_MainActivity_startCarrier(
        JNIEnv *env,
        jobject jobj,
        jstring path,
        jobject jlistener) {

    ECode ec = (ECode) _CCarrier_GetInstance(&gCarrier);
    if (FAILED(ec)) return;

    jclass _clazz = env->GetObjectClass(jlistener);
    jmethodID _methodId = env->GetMethodID(_clazz, "getCarObject", "()J");
    jlong _carobj = env->CallLongMethod(jlistener, _methodId);

    gCarrier->AddCarrierNodeListener(ICarrierListener::Probe((IInterface*)_carobj));

    const char* nativeString = env->GetStringUTFChars(path, nullptr);
    gCarrier->Start(String(nativeString));
    env->ReleaseStringUTFChars(path, nativeString);
}

extern "C" JNIEXPORT void JNICALL Java_org_elastos_generatejavaclient_MainActivity_stopCarrier(
        JNIEnv *env,
        jobject jobj) {
    if (gCarrier == NULL) return;

    gCarrier->Stop();
    gCarrier->Release();
    gCarrier = NULL;
}

extern "C" JNIEXPORT jint JNICALL Java_org_elastos_generatejavaclient_MainActivity_addFriend(
        JNIEnv *env,
        jobject jobj,
        jstring uid) {
    if (gCarrier == NULL) return -1;

    const char* nativeString = env->GetStringUTFChars(uid, nullptr);
    String friendId;
    ECode ec = gCarrier->AddFriend(String(nativeString), String("hello"), &friendId);
    env->ReleaseStringUTFChars(uid, nativeString);
    return ec;
}


extern "C" JNIEXPORT jint JNICALL Java_org_elastos_generatejavaclient_MainActivity_deleteFriend(
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

extern "C" JNIEXPORT jobject JNICALL Java_org_elastos_generatejavaclient_MainActivity_getFriendList(
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

    jclass cls_friend = env->FindClass("org/elastos/generatejavaclient/Friend");
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


extern "C" JNIEXPORT jint JNICALL Java_org_elastos_generatejavaclient_MainActivity_acceptFriend(
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

extern "C" JNIEXPORT jstring JNICALL Java_org_elastos_generatejavaclient_MainActivity_getAddress(
        JNIEnv *env,
        jobject jobj) {
    if (gCarrier == NULL) return env->NewStringUTF("");

    String address;
    gCarrier->GetAddress(&address);
    return env->NewStringUTF(address.string());
}

extern "C" JNIEXPORT void JNICALL Java_org_elastos_generatejavaclient_MainActivity_startServiceManager(
        JNIEnv *env,
        jobject jobj) {
    if (gCarrier == NULL) return;
    if (gServiceManager != NULL) {
        return;
    }

    _CServiceManager_AcquireInstance(&gServiceManager);
}

extern "C" JNIEXPORT void JNICALL Java_org_elastos_generatejavaclient_MainActivity_stopServiceManager(
        JNIEnv *env,
        jobject jobj) {
    if (gServiceManager) {
        gServiceManager->Release();
        gServiceManager = NULL;
    }
}

extern "C" JNIEXPORT jint JNICALL Java_org_elastos_generatejavaclient_MainActivity_getService(
        JNIEnv *env,
        jobject jobj,
        jstring uid,
        jstring name) {
    if (gServiceManager == NULL) return -1;

    IInterface* pInterface;
    const char* uidstr = env->GetStringUTFChars(uid, nullptr);
    const char* namestr = env->GetStringUTFChars(name, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "GenerateJava", "==== get service %s", namestr);

    ECode ec = gServiceManager->GetService(String(uidstr), String(namestr), &pInterface);
    env->ReleaseStringUTFChars(name, namestr);
    if (FAILED(ec)) {
        __android_log_print(ANDROID_LOG_DEBUG, "GenerateJava", "==== get service %s failed ec:%x", namestr, ec);
        env->ReleaseStringUTFChars(uid, uidstr);
        return ec;
    }

    IHelloJava* helloJava = IHelloJava::Probe(pInterface);
    if (helloJava == NULL) {
        __android_log_print(ANDROID_LOG_DEBUG, "GenerateJava", "=== probe ISwitch failed");
        env->ReleaseStringUTFChars(uid, uidstr);
        pInterface->Release();
        return -1;
    }

    gInterfaces[String(uidstr)] = helloJava;
    env->ReleaseStringUTFChars(uid, uidstr);
    return NOERROR;
}

extern "C" JNIEXPORT jstring JNICALL Java_org_elastos_generatejavaclient_MainActivity_hello(
        JNIEnv *env,
        jobject jobj,
        jstring uid) {
    if (gServiceManager == NULL) return nullptr;

    const char* uidstr = env->GetStringUTFChars(uid, nullptr);
    IHelloJava* helloJava = gInterfaces[String(uidstr)];
    if (helloJava == NULL) {
        env->ReleaseStringUTFChars(uid, uidstr);
        return nullptr;
    }

    String str;
    ECode ec = helloJava->Hello(&str);
    env->ReleaseStringUTFChars(uid, uidstr);
    return env->NewStringUTF(str.string());
}
