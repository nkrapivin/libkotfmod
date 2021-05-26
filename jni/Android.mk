# libkotfmod Library makefile.
LOCAL_PATH := $(call my-dir)

#
# FMOD Shared Library
#
include $(CLEAR_VARS)

LOCAL_MODULE            := fmod
LOCAL_SRC_FILES         := ../fmodstudioapi20109android/api/core/lib/$(TARGET_ARCH_ABI)/libfmod.so
LOCAL_EXPORT_C_INCLUDES := ../fmodstudioapi20109android/api/core/inc


include $(PREBUILT_SHARED_LIBRARY)

#
# FMOD Shared Library
#
include $(CLEAR_VARS)

LOCAL_MODULE            := fmodstudio
LOCAL_SRC_FILES         := ../fmodstudioapi20109android/api/studio/lib/$(TARGET_ARCH_ABI)/libfmodstudio.so
LOCAL_EXPORT_C_INCLUDES := ../fmodstudioapi20109android/api/studio/inc


include $(PREBUILT_SHARED_LIBRARY)

#
# libkotfmod JNI Library
#
include $(CLEAR_VARS)

LOCAL_MODULE    := kotfmod
LOCAL_SRC_FILES := ../libkotfmod_Main.cpp ../libkotfmod_Bank.cpp ../libkotfmod_CoreCallbacks.cpp ../libkotfmod_CoreChannel.cpp ../libkotfmod_CoreChannelGroup.cpp ../libkotfmod_CoreDSP.cpp ../libkotfmod_CoreSound.cpp ../libkotfmod_CoreSystem.cpp ../libkotfmod_EventDescription.cpp ../libkotfmod_EventInstance.cpp ../libkotfmod_Reflection.cpp ../libkotfmod_RegisterCallbacks.cpp ../libkotfmod_StudioCallback.cpp ../libkotfmod_System.cpp ../JNI_Callbacks.cpp ../JNI_LKFNative.cpp
LOCAL_SHARED_LIBRARIES  := fmod fmodstudio
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../fmodstudioapi20109android/api/core/inc $(LOCAL_PATH)/../fmodstudioapi20109android/api/studio/inc

# logging
LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)
