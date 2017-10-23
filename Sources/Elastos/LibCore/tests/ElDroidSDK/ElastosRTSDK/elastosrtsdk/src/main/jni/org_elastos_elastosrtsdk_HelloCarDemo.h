
/* Header for class org_elastos_elastosrtsdk_HelloCarDemo */
#ifndef _Included_org_elastos_elastosrtsdk_HelloCarDemo
#define _Included_org_elastos_elastosrtsdk_HelloCarDemo

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Class:     org_elastos_elastosrtsdk_HelloCarDemo
 * Method:    nativeCreateElastosHelloCar
 * Signature: ()Ljava/lang/Long;
 */
JNIEXPORT jlong JNICALL Java_org_elastos_elastosrtsdk_HelloCarDemo_nativeCreateElastosHelloCar
        (JNIEnv *, jobject);

/*
 * Class:     org_elastos_elastosrtsdk_HelloCarDemo
 * Method:    nativeFinalize
 * Signature: (J)V;
 */
JNIEXPORT void JNICALL Java_org_elastos_elastosrtsdk_HelloCarDemo_nativeFinalize
        (JNIEnv *, jobject, jlong jproxy);

/*
 * Class:     org_elastos_elastosrtsdk_HelloCarDemo
 * Method:    nativeHelloCar
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_org_elastos_elastosrtsdk_HelloCarDemo_nativeHelloCar
        (JNIEnv *, jobject, jlong jproxy);


#ifdef __cplusplus
}
#endif
#endif
