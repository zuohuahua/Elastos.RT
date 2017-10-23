
LOCAL_PATH := $(call my-dir)

$(shell cp $(LOCAL_PATH)/elastoslib/Elastos.Runtime.eco $(LOCAL_PATH)/elastoslib/libElastos.Runtime.so)
$(shell cp $(LOCAL_PATH)/elastoslib/Elastos.CoreLibrary.eco $(LOCAL_PATH)/elastoslib/libElastos.CoreLibrary.so)
$(shell cp $(LOCAL_PATH)/elastoslib/Elastos.HelloCarDemo.eco $(LOCAL_PATH)/elastoslib/libElastos.HelloCarDemo.so)

#Elastos.Runtime
include $(CLEAR_VARS)
LOCAL_MODULE    := Elastos.Runtime
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastoslib/libElastos.Runtime.so
# LOCAL_SRC_FILES := Elastos.Runtime.eco
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary
include $(CLEAR_VARS)
LOCAL_MODULE    := Elastos.CoreLibrary
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastoslib/libElastos.CoreLibrary.so
# LOCAL_SRC_FILES := Elastos.CoreLibrary.eco
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.HelloCarDemo
include $(CLEAR_VARS)
LOCAL_MODULE    := Elastos.HelloCarDemo
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastoslib/libElastos.HelloCarDemo.so
# LOCAL_SRC_FILES := Elastos.HelloCarDemo.eco
include $(PREBUILT_SHARED_LIBRARY)

#Elastos.CoreLibrary depend libcrypto.so
include $(CLEAR_VARS)
LOCAL_MODULE    := crypto
LOCAL_SRC_FILES := $(LOCAL_PATH)/elastoslib/libcrypto.so
include $(PREBUILT_SHARED_LIBRARY)


### shared library
include $(CLEAR_VARS)

LOCAL_SRC_FILES := org_elastos_elastosrtsdk_HelloCarDemo.cpp \
      Elastos.CoreLibrary.cpp \
      Elastos.HelloCarDemo.cpp \

LOCAL_C_INCLUDES := $(LOCAL_PATH)/elastos \
      $(LOCAL_PATH)/elastos/elasys

LOCAL_LDLIBS :=-llog
LOCAL_CFLAGS += -std=c++11 -D_GNUC -D_linux -D_UNDEFDLLEXP

LOCAL_MODULE := libElastosSimpleLib

#The elastos eco and lib.
LOCAL_LDFLAGS := $(LOCAL_PATH)/elastoslib/libElastos.Runtime.so \
		$(LOCAL_PATH)/elastoslib/libElastos.CoreLibrary.so \
		$(LOCAL_PATH)/elastoslib/libElastos.HelloCarDemo.so \
		$(LOCAL_PATH)/elastoslib/Elastos.Runtime.lib

include $(BUILD_SHARED_LIBRARY)
