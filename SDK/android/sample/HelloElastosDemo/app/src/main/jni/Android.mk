
LOCAL_PATH := $(call my-dir)

#Elastos.Runtime
include $(CLEAR_VARS)
LOCAL_MODULE    := Elastos.Runtime
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libElastos.Runtime.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary
include $(CLEAR_VARS)
LOCAL_MODULE    := Elastos.CoreLibrary
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libElastos.CoreLibrary.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.HelloCarDemo
include $(CLEAR_VARS)
LOCAL_MODULE    := Elastos.HelloCarDemo
LOCAL_SRC_FILES := $(LOCAL_PATH)/Elastos.HelloCarDemo/libElastos.HelloCarDemo.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary depend libcrypto.so
include $(CLEAR_VARS)
LOCAL_MODULE    := crypto
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libcrypto.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary depend libicuuc.so
include $(CLEAR_VARS)
LOCAL_MODULE    := icuuc
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libicuuc.so
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary depend libstlport.so
include $(CLEAR_VARS)
LOCAL_MODULE    := stlport
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastos/libs/libstlport.so
include $(PREBUILT_SHARED_LIBRARY)

### shared library
include $(CLEAR_VARS)
LOCAL_SRC_FILES := elastos_testthirdlib.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/elastos/include \
      $(LOCAL_PATH)/elastos/include/elasys \
      $(LOCAL_PATH)/Elastos.HelloCarDemo

LOCAL_CFLAGS += -std=c++11 -D_GNUC -D_linux -D_UNDEFDLLEXP -fvisibility=hidden

LOCAL_MODULE := testThirdLib

#The elastos eco and lib.
LOCAL_LDFLAGS := $(LOCAL_PATH)/elastos/libs/libElastos.Runtime.so \
		$(LOCAL_PATH)/elastos/libs/libElastos.CoreLibrary.so \
		$(LOCAL_PATH)/Elastos.HelloCarDemo/libElastos.HelloCarDemo.so \
		$(LOCAL_PATH)/elastos/libs/Elastos.Runtime.lib

#LOCAL_LDFLAGS := $(LOCAL_PATH)/elastoslib/Elastos.Runtime.eco \
#		$(LOCAL_PATH)/elastoslib/Elastos.CoreLibrary.eco \
#		$(LOCAL_PATH)/elastoslib/Elastos.HelloCarDemo.eco \
#		$(LOCAL_PATH)/elastoslib/Elastos.Runtime.lib

include $(BUILD_SHARED_LIBRARY)
