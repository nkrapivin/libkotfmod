#ifdef __ANDROID__
/* add your includes here... */
#include "libkotfmod.h"
extern "C" {
#include <jni.h>
	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1internal_1init
	(JNIEnv* jniEnv, jobject jniThis) {
		jdouble __return__{ lkf_internal_init() };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1internal_1final
	(JNIEnv* jniEnv, jobject jniThis) {
		jdouble __return__{ lkf_internal_final() };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1is_1present
	(JNIEnv* jniEnv, jobject jniThis) {
		jdouble __return__{ lkf_is_present() };
		return __return__;
	}

	JNIEXPORT jstring JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_RegisterCallbacks
	(JNIEnv* jniEnv, jobject jniThis, jobject please, jobject dont, jobject call, jobject it) {
		void* _raw_please{ reinterpret_cast<void*>(jniEnv->GetDirectBufferAddress(please)) };
		void* _raw_dont{ reinterpret_cast<void*>(jniEnv->GetDirectBufferAddress(dont)) };
		void* _raw_call{ reinterpret_cast<void*>(jniEnv->GetDirectBufferAddress(call)) };
		void* _raw_it{ reinterpret_cast<void*>(jniEnv->GetDirectBufferAddress(it)) };
		jstring __return__{ jniEnv->NewStringUTF(RegisterCallbacks(_raw_please, _raw_dont, _raw_call, _raw_it)) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1are_1callbacks_1registered
	(JNIEnv* jniEnv, jobject jniThis) {
		jdouble __return__{ lkf_are_callbacks_registered() };
		return __return__;
	}

	JNIEXPORT jstring JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1enum_1result_1reflection
	(JNIEnv* jniEnv, jobject jniThis, jdouble value) {
		jstring __return__{ jniEnv->NewStringUTF(lkf_enum_result_reflection(value)) };
		return __return__;
	}

	JNIEXPORT jstring JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1enum_1event_1instance_1callback_1reflection
	(JNIEnv* jniEnv, jobject jniThis, jdouble value) {
		jstring __return__{ jniEnv->NewStringUTF(lkf_enum_event_instance_callback_reflection(value)) };
		return __return__;
	}

	JNIEXPORT jstring JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1enum_1system_1callback_1reflection
	(JNIEnv* jniEnv, jobject jniThis, jdouble value) {
		jstring __return__{ jniEnv->NewStringUTF(lkf_enum_system_callback_reflection(value)) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1get_1api_1version
	(JNIEnv* jniEnv, jobject jniThis) {
		jdouble __return__{ lkf_get_api_version() };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1create
	(JNIEnv* jniEnv, jobject jniThis) {
		jdouble __return__{ lkf_system_create() };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1update
	(JNIEnv* jniEnv, jobject jniThis, jdouble system) {
		jdouble __return__{ lkf_system_update(system) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1exists
	(JNIEnv* jniEnv, jobject jniThis, jdouble system) {
		jdouble __return__{ lkf_system_exists(system) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1initialize
	(JNIEnv* jniEnv, jobject jniThis, jdouble system, jdouble maxchannels, jdouble studioflags, jdouble flags) {
		jdouble __return__{ lkf_system_initialize(system, maxchannels, studioflags, flags) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1loadBankFile
	(JNIEnv* jniEnv, jobject jniThis, jdouble system, jstring filename, jdouble flags) {
		jboolean _isCopy{ JNI_FALSE };
		const char* _cstr_filename{ jniEnv->GetStringUTFChars(filename, &_isCopy) };
		jdouble __return__{ lkf_system_loadBankFile(system, _cstr_filename, flags) };
		jniEnv->ReleaseStringUTFChars(filename, _cstr_filename);
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1getEvent
	(JNIEnv* jniEnv, jobject jniThis, jdouble system, jstring path) {
		jboolean _isCopy{ JNI_FALSE };
		const char* _cstr_path{ jniEnv->GetStringUTFChars(path, &_isCopy) };
		jdouble __return__{ lkf_system_getEvent(system, _cstr_path) };
		jniEnv->ReleaseStringUTFChars(path, _cstr_path);
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1unloadAll
	(JNIEnv* jniEnv, jobject jniThis, jdouble system) {
		jdouble __return__{ lkf_system_unloadAll(system) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1setListenerAttributes
	(JNIEnv* jniEnv, jobject jniThis, jdouble system, jdouble listener, jobject attributes, jobject attenuationposition) {
		const FMOD_3D_ATTRIBUTES* _raw_attributes{ reinterpret_cast<const FMOD_3D_ATTRIBUTES*>(const_cast<const void*>(jniEnv->GetDirectBufferAddress(attributes))) };
		const FMOD_VECTOR* _raw_attenuationposition{ reinterpret_cast<const FMOD_VECTOR*>(const_cast<const void*>(jniEnv->GetDirectBufferAddress(attenuationposition))) };
		jdouble __return__{ lkf_system_setListenerAttributes(system, listener, _raw_attributes, _raw_attenuationposition) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1release
	(JNIEnv* jniEnv, jobject jniThis, jdouble system) {
		jdouble __return__{ lkf_system_release(system) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1flushCommands
	(JNIEnv* jniEnv, jobject jniThis, jdouble system) {
		jdouble __return__{ lkf_system_flushCommands(system) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1flushSampleLoading
	(JNIEnv* jniEnv, jobject jniThis, jdouble system) {
		jdouble __return__{ lkf_system_flushSampleLoading(system) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1getCPUUsage
	(JNIEnv* jniEnv, jobject jniThis, jdouble system, jobject retmem) {
		FMOD_STUDIO_CPU_USAGE* _raw_retmem{ reinterpret_cast<FMOD_STUDIO_CPU_USAGE*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_system_getCPUUsage(system, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1getMemoryUsage
	(JNIEnv* jniEnv, jobject jniThis, jdouble system, jobject memoryusage) {
		FMOD_STUDIO_MEMORY_USAGE* _raw_memoryusage{ reinterpret_cast<FMOD_STUDIO_MEMORY_USAGE*>(jniEnv->GetDirectBufferAddress(memoryusage)) };
		jdouble __return__{ lkf_system_getMemoryUsage(system, _raw_memoryusage) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1system_1getCoreSystem
	(JNIEnv* jniEnv, jobject jniThis, jdouble system) {
		jdouble __return__{ lkf_system_getCoreSystem(system) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1bank_1exists
	(JNIEnv* jniEnv, jobject jniThis, jdouble bank) {
		jdouble __return__{ lkf_bank_exists(bank) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1bank_1unload
	(JNIEnv* jniEnv, jobject jniThis, jdouble bank) {
		jdouble __return__{ lkf_bank_unload(bank) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1bank_1loadSampleData
	(JNIEnv* jniEnv, jobject jniThis, jdouble bank) {
		jdouble __return__{ lkf_bank_loadSampleData(bank) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1bank_1unloadSampleData
	(JNIEnv* jniEnv, jobject jniThis, jdouble bank) {
		jdouble __return__{ lkf_bank_unloadSampleData(bank) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1bank_1getLoadingState
	(JNIEnv* jniEnv, jobject jniThis, jdouble bank) {
		jdouble __return__{ lkf_bank_getLoadingState(bank) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1bank_1getSampleLoadingState
	(JNIEnv* jniEnv, jobject jniThis, jdouble bank) {
		jdouble __return__{ lkf_bank_getSampleLoadingState(bank) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventDescription_1exists
	(JNIEnv* jniEnv, jobject jniThis, jdouble evdesc) {
		jdouble __return__{ lkf_eventDescription_exists(evdesc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventDescription_1createInstance
	(JNIEnv* jniEnv, jobject jniThis, jdouble evdesc) {
		jdouble __return__{ lkf_eventDescription_createInstance(evdesc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventDescription_1loadSampleData
	(JNIEnv* jniEnv, jobject jniThis, jdouble evdesc) {
		jdouble __return__{ lkf_eventDescription_loadSampleData(evdesc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventDescription_1unloadSampleData
	(JNIEnv* jniEnv, jobject jniThis, jdouble evdesc) {
		jdouble __return__{ lkf_eventDescription_unloadSampleData(evdesc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventDescription_1releaseAllInstances
	(JNIEnv* jniEnv, jobject jniThis, jdouble evdesc) {
		jdouble __return__{ lkf_eventDescription_releaseAllInstances(evdesc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventDescription_1getSampleLoadingState
	(JNIEnv* jniEnv, jobject jniThis, jdouble evdesc) {
		jdouble __return__{ lkf_eventDescription_getSampleLoadingState(evdesc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventDescription_1isSnapshot
	(JNIEnv* jniEnv, jobject jniThis, jdouble evdesc) {
		jdouble __return__{ lkf_eventDescription_isSnapshot(evdesc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventDescription_1isOneshot
	(JNIEnv* jniEnv, jobject jniThis, jdouble evdesc) {
		jdouble __return__{ lkf_eventDescription_isOneshot(evdesc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventDescription_1isStream
	(JNIEnv* jniEnv, jobject jniThis, jdouble evdesc) {
		jdouble __return__{ lkf_eventDescription_isStream(evdesc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventDescription_1is3D
	(JNIEnv* jniEnv, jobject jniThis, jdouble evdesc) {
		jdouble __return__{ lkf_eventDescription_is3D(evdesc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventDescription_1isDopplerEnabled
	(JNIEnv* jniEnv, jobject jniThis, jdouble evdesc) {
		jdouble __return__{ lkf_eventDescription_isDopplerEnabled(evdesc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventDescription_1hasCue
	(JNIEnv* jniEnv, jobject jniThis, jdouble evdesc) {
		jdouble __return__{ lkf_eventDescription_hasCue(evdesc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1exists
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst) {
		jdouble __return__{ lkf_eventInstance_exists(evinst) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1start
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst) {
		jdouble __return__{ lkf_eventInstance_start(evinst) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1stop
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jdouble stopmode) {
		jdouble __return__{ lkf_eventInstance_stop(evinst, stopmode) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1setParameterByName
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jstring name, jdouble value, jdouble ignoreseekspeed) {
		jboolean _isCopy{ JNI_FALSE };
		const char* _cstr_name{ jniEnv->GetStringUTFChars(name, &_isCopy) };
		jdouble __return__{ lkf_eventInstance_setParameterByName(evinst, _cstr_name, value, ignoreseekspeed) };
		jniEnv->ReleaseStringUTFChars(name, _cstr_name);
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1getParameterByName
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jstring name, jobject retmem) {
		jboolean _isCopy{ JNI_FALSE };
		const char* _cstr_name{ jniEnv->GetStringUTFChars(name, &_isCopy) };
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_eventInstance_getParameterByName(evinst, _cstr_name, _raw_retmem) };
		jniEnv->ReleaseStringUTFChars(name, _cstr_name);
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1set3DAttributes
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jobject attributes) {
		const FMOD_3D_ATTRIBUTES* _raw_attributes{ reinterpret_cast<const FMOD_3D_ATTRIBUTES*>(const_cast<const void*>(jniEnv->GetDirectBufferAddress(attributes))) };
		jdouble __return__{ lkf_eventInstance_set3DAttributes(evinst, _raw_attributes) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1get3DAttributes
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jobject retattr) {
		FMOD_3D_ATTRIBUTES* _raw_retattr{ reinterpret_cast<FMOD_3D_ATTRIBUTES*>(jniEnv->GetDirectBufferAddress(retattr)) };
		jdouble __return__{ lkf_eventInstance_get3DAttributes(evinst, _raw_retattr) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1setVolume
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jdouble volume) {
		jdouble __return__{ lkf_eventInstance_setVolume(evinst, volume) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1getVolume
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_eventInstance_getVolume(evinst, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1setPitch
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jdouble pitch) {
		jdouble __return__{ lkf_eventInstance_setPitch(evinst, pitch) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1getPitch
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_eventInstance_getPitch(evinst, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1release
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst) {
		jdouble __return__{ lkf_eventInstance_release(evinst) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1triggerCue
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst) {
		jdouble __return__{ lkf_eventInstance_triggerCue(evinst) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1getPaused
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst) {
		jdouble __return__{ lkf_eventInstance_getPaused(evinst) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1setPaused
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jdouble paused) {
		jdouble __return__{ lkf_eventInstance_setPaused(evinst, paused) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1setReverbLevel
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jdouble index, jdouble level) {
		jdouble __return__{ lkf_eventInstance_setReverbLevel(evinst, index, level) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1getReverbLevel
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jdouble index) {
		jdouble __return__{ lkf_eventInstance_getReverbLevel(evinst, index) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1setTimelinePosition
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jdouble position) {
		jdouble __return__{ lkf_eventInstance_setTimelinePosition(evinst, position) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1getTimelinePosition
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst) {
		jdouble __return__{ lkf_eventInstance_getTimelinePosition(evinst) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1setListenerMask
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst, jdouble mask) {
		jdouble __return__{ lkf_eventInstance_setListenerMask(evinst, mask) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1getListenerMask
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst) {
		jdouble __return__{ lkf_eventInstance_getListenerMask(evinst) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1getDescription
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst) {
		jdouble __return__{ lkf_eventInstance_getDescription(evinst) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1eventInstance_1isVirtual
	(JNIEnv* jniEnv, jobject jniThis, jdouble evinst) {
		jdouble __return__{ lkf_eventInstance_isVirtual(evinst) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1exists
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_exists(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1setSoftwareFormat
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble samplerate, jdouble speakermode, jdouble numrawspeakers) {
		jdouble __return__{ lkf_coreSystem_setSoftwareFormat(csys, samplerate, speakermode, numrawspeakers) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1create
	(JNIEnv* jniEnv, jobject jniThis) {
		jdouble __return__{ lkf_coreSystem_create() };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1init
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble maxchannels, jdouble initflags) {
		jdouble __return__{ lkf_coreSystem_init(csys, maxchannels, initflags) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1update
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_update(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1close
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_close(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1release
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_release(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1setOutput
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble output) {
		jdouble __return__{ lkf_coreSystem_setOutput(csys, output) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getOutput
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_getOutput(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1setSoftwareChannels
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble numsoftwarechannels) {
		jdouble __return__{ lkf_coreSystem_setSoftwareChannels(csys, numsoftwarechannels) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getSoftwareChannels
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_getSoftwareChannels(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getSoftwareFormat
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jobject retmem) {
		int* _raw_retmem{ reinterpret_cast<int*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSystem_getSoftwareFormat(csys, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1setDSPBufferSize
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble bufferlen, jdouble numbuffers) {
		jdouble __return__{ lkf_coreSystem_setDSPBufferSize(csys, bufferlen, numbuffers) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getDSPBufferSize
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jobject retmem) {
		int* _raw_retmem{ reinterpret_cast<int*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSystem_getDSPBufferSize(csys, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1setPluginPath
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jstring path) {
		jboolean _isCopy{ JNI_FALSE };
		const char* _cstr_path{ jniEnv->GetStringUTFChars(path, &_isCopy) };
		jdouble __return__{ lkf_coreSystem_setPluginPath(csys, _cstr_path) };
		jniEnv->ReleaseStringUTFChars(path, _cstr_path);
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1loadPlugin
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jstring name, jdouble priority) {
		jboolean _isCopy{ JNI_FALSE };
		const char* _cstr_name{ jniEnv->GetStringUTFChars(name, &_isCopy) };
		jdouble __return__{ lkf_coreSystem_loadPlugin(csys, _cstr_name, priority) };
		jniEnv->ReleaseStringUTFChars(name, _cstr_name);
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1unloadPlugin
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble handle) {
		jdouble __return__{ lkf_coreSystem_unloadPlugin(csys, handle) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1setOutputByPlugin
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble handle) {
		jdouble __return__{ lkf_coreSystem_setOutputByPlugin(csys, handle) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getOutputByPlugin
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_getOutputByPlugin(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1setSpeakerPosition
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble speaker, jdouble x, jdouble y, jdouble active) {
		jdouble __return__{ lkf_coreSystem_setSpeakerPosition(csys, speaker, x, y, active) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getSpeakerPosition
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble speaker, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSystem_getSpeakerPosition(csys, speaker, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1setStreamBufferSize
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble filebuffersize, jdouble filebuffersizetype) {
		jdouble __return__{ lkf_coreSystem_setStreamBufferSize(csys, filebuffersize, filebuffersizetype) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getStreamBufferSize
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jobject retmem) {
		unsigned int* _raw_retmem{ reinterpret_cast<unsigned int*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSystem_getStreamBufferSize(csys, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1set3DSettings
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble dopplerscale, jdouble distancefactor, jdouble rolloffscale) {
		jdouble __return__{ lkf_coreSystem_set3DSettings(csys, dopplerscale, distancefactor, rolloffscale) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1get3DSettings
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSystem_get3DSettings(csys, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1set3DNumListeners
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble num) {
		jdouble __return__{ lkf_coreSystem_set3DNumListeners(csys, num) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1get3DNumListeners
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_get3DNumListeners(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1set3DListenerAttributes
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble listener, jobject vecs) {
		const FMOD_VECTOR* _raw_vecs{ reinterpret_cast<const FMOD_VECTOR*>(const_cast<const void*>(jniEnv->GetDirectBufferAddress(vecs))) };
		jdouble __return__{ lkf_coreSystem_set3DListenerAttributes(csys, listener, _raw_vecs) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1get3DListenerAttributes
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble listener, jobject retmem) {
		FMOD_VECTOR* _raw_retmem{ reinterpret_cast<FMOD_VECTOR*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSystem_get3DListenerAttributes(csys, listener, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1mixerSuspend
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_mixerSuspend(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1mixerResume
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_mixerResume(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getVersion
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_getVersion(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getOutputHandle
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_getOutputHandle(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getChannelsPlaying
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jobject retmem) {
		int* _raw_retmem{ reinterpret_cast<int*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSystem_getChannelsPlaying(csys, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getCPUUsage
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSystem_getCPUUsage(csys, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getCPUUsageEx
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSystem_getCPUUsageEx(csys, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getFileUsage
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jobject retmem) {
		long long* _raw_retmem{ reinterpret_cast<long long*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSystem_getFileUsage(csys, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1lockDSP
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_lockDSP(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1unlockDSP
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_unlockDSP(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1setNetworkProxy
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jstring proxy) {
		jboolean _isCopy{ JNI_FALSE };
		const char* _cstr_proxy{ jniEnv->GetStringUTFChars(proxy, &_isCopy) };
		jdouble __return__{ lkf_coreSystem_setNetworkProxy(csys, _cstr_proxy) };
		jniEnv->ReleaseStringUTFChars(proxy, _cstr_proxy);
		return __return__;
	}

	JNIEXPORT jstring JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getNetworkProxy
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jstring __return__{ jniEnv->NewStringUTF(lkf_coreSystem_getNetworkProxy(csys)) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1setNetworkTimeout
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble timeout) {
		jdouble __return__{ lkf_coreSystem_setNetworkTimeout(csys, timeout) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getNetworkTimeout
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_getNetworkTimeout(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1createSound
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jstring name, jdouble mode) {
		jboolean _isCopy{ JNI_FALSE };
		const char* _cstr_name{ jniEnv->GetStringUTFChars(name, &_isCopy) };
		jdouble __return__{ lkf_coreSystem_createSound(csys, _cstr_name, mode) };
		jniEnv->ReleaseStringUTFChars(name, _cstr_name);
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1createChannelGroup
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jstring name) {
		jboolean _isCopy{ JNI_FALSE };
		const char* _cstr_name{ jniEnv->GetStringUTFChars(name, &_isCopy) };
		jdouble __return__{ lkf_coreSystem_createChannelGroup(csys, _cstr_name) };
		jniEnv->ReleaseStringUTFChars(name, _cstr_name);
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1getMasterChannelGroup
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys) {
		jdouble __return__{ lkf_coreSystem_getMasterChannelGroup(csys) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1playSound
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble csnd, jdouble cgrp, jdouble paused) {
		jdouble __return__{ lkf_coreSystem_playSound(csys, csnd, cgrp, paused) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSystem_1createDSPByType
	(JNIEnv* jniEnv, jobject jniThis, jdouble csys, jdouble type) {
		jdouble __return__{ lkf_coreSystem_createDSPByType(csys, type) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSound_1exists
	(JNIEnv* jniEnv, jobject jniThis, jdouble csnd) {
		jdouble __return__{ lkf_coreSound_exists(csnd) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSound_1setDefaults
	(JNIEnv* jniEnv, jobject jniThis, jdouble csnd, jdouble freq, jdouble pri) {
		jdouble __return__{ lkf_coreSound_setDefaults(csnd, freq, pri) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSound_1getDefaults
	(JNIEnv* jniEnv, jobject jniThis, jdouble csnd, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSound_getDefaults(csnd, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSound_1set3DMinMaxDistance
	(JNIEnv* jniEnv, jobject jniThis, jdouble csnd, jdouble dmin, jdouble dmax) {
		jdouble __return__{ lkf_coreSound_set3DMinMaxDistance(csnd, dmin, dmax) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSound_1get3DMinMaxDistance
	(JNIEnv* jniEnv, jobject jniThis, jdouble csnd, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSound_get3DMinMaxDistance(csnd, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSound_1set3DConeSettings
	(JNIEnv* jniEnv, jobject jniThis, jdouble csnd, jdouble insideconeangle, jdouble outsideconeangle, jdouble outsidevolume) {
		jdouble __return__{ lkf_coreSound_set3DConeSettings(csnd, insideconeangle, outsideconeangle, outsidevolume) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreSound_1get3DConeSettings
	(JNIEnv* jniEnv, jobject jniThis, jdouble csnd, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreSound_get3DConeSettings(csnd, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1exists
	(JNIEnv* jniEnv, jobject jniThis, jdouble cchg) {
		jdouble __return__{ lkf_coreChannelGroup_exists(cchg) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1stop
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_stop(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setPaused
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble paused) {
		jdouble __return__{ lkf_coreChannelGroup_setPaused(cc, paused) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getPaused
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getPaused(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setVolume
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble volume) {
		jdouble __return__{ lkf_coreChannelGroup_setVolume(cc, volume) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getVolume
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getVolume(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setVolumeRamp
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble ramp) {
		jdouble __return__{ lkf_coreChannelGroup_setVolumeRamp(cc, ramp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getVolumeRamp
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getVolumeRamp(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getAudibility
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getAudibility(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setPitch
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble pitch) {
		jdouble __return__{ lkf_coreChannelGroup_setPitch(cc, pitch) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getPitch
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getPitch(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setMute
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble mute) {
		jdouble __return__{ lkf_coreChannelGroup_setMute(cc, mute) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getMute
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getMute(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setReverbProperties
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble instance, jdouble wet) {
		jdouble __return__{ lkf_coreChannelGroup_setReverbProperties(cc, instance, wet) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getReverbProperties
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble instance) {
		jdouble __return__{ lkf_coreChannelGroup_getReverbProperties(cc, instance) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setLowPassGain
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble gain) {
		jdouble __return__{ lkf_coreChannelGroup_setLowPassGain(cc, gain) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getLowPassGain
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getLowPassGain(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setMode
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble mode) {
		jdouble __return__{ lkf_coreChannelGroup_setMode(cc, mode) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getMode
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getMode(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1isPlaying
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_isPlaying(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setPan
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble pan) {
		jdouble __return__{ lkf_coreChannelGroup_setPan(cc, pan) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setMixLevelsOutput
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble frontleft, jdouble frontright, jdouble center, jdouble lfe, jdouble surroundleft, jdouble surroundright, jdouble backleft, jdouble backright) {
		jdouble __return__{ lkf_coreChannelGroup_setMixLevelsOutput(cc, frontleft, frontright, center, lfe, surroundleft, surroundright, backleft, backright) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getDSPClock
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		unsigned long long* _raw_retmem{ reinterpret_cast<unsigned long long*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannelGroup_getDSPClock(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setDelay
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble clock_start, jdouble clock_end, jdouble stopchan) {
		jdouble __return__{ lkf_coreChannelGroup_setDelay(cc, clock_start, clock_end, stopchan) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getDelay
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		unsigned long long* _raw_retmem{ reinterpret_cast<unsigned long long*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannelGroup_getDelay(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1addFadePoint
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble clock, jdouble volume) {
		jdouble __return__{ lkf_coreChannelGroup_addFadePoint(cc, clock, volume) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setFadePointRamp
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble clock, jdouble volume) {
		jdouble __return__{ lkf_coreChannelGroup_setFadePointRamp(cc, clock, volume) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1removeFadePoints
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble clock_start, jdouble clock_end) {
		jdouble __return__{ lkf_coreChannelGroup_removeFadePoints(cc, clock_start, clock_end) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getSystemObject
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getSystemObject(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1set3DAttributes
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject vecs) {
		const FMOD_VECTOR* _raw_vecs{ reinterpret_cast<const FMOD_VECTOR*>(const_cast<const void*>(jniEnv->GetDirectBufferAddress(vecs))) };
		jdouble __return__{ lkf_coreChannelGroup_set3DAttributes(cc, _raw_vecs) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1get3DAttributes
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		FMOD_VECTOR* _raw_retmem{ reinterpret_cast<FMOD_VECTOR*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannelGroup_get3DAttributes(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1set3DMinMaxDistance
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble dmin, jdouble dmax) {
		jdouble __return__{ lkf_coreChannelGroup_set3DMinMaxDistance(cc, dmin, dmax) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1get3DMinMaxDistance
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannelGroup_get3DMinMaxDistance(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1set3DConeSettings
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble insideconeangle, jdouble outsideconeangle, jdouble outsidevolume) {
		jdouble __return__{ lkf_coreChannelGroup_set3DConeSettings(cc, insideconeangle, outsideconeangle, outsidevolume) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1get3DConeSettings
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannelGroup_get3DConeSettings(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1set3DConeOrientation
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject vec) {
		FMOD_VECTOR* _raw_vec{ reinterpret_cast<FMOD_VECTOR*>(jniEnv->GetDirectBufferAddress(vec)) };
		jdouble __return__{ lkf_coreChannelGroup_set3DConeOrientation(cc, _raw_vec) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1set3DOcclusion
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble directocclusion, jdouble reverbocclusion) {
		jdouble __return__{ lkf_coreChannelGroup_set3DOcclusion(cc, directocclusion, reverbocclusion) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1get3DOcclusion
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannelGroup_get3DOcclusion(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1set3DSpread
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble angle) {
		jdouble __return__{ lkf_coreChannelGroup_set3DSpread(cc, angle) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1get3DSpread
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_get3DSpread(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1set3DLevel
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble level) {
		jdouble __return__{ lkf_coreChannelGroup_set3DLevel(cc, level) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1get3DLevel
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_get3DLevel(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1set3DDopplerLevel
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble level) {
		jdouble __return__{ lkf_coreChannelGroup_set3DDopplerLevel(cc, level) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1get3DDopplerLevel
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_get3DDopplerLevel(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1set3DDistanceFilter
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble custom, jdouble customLevel, jdouble centerFreq) {
		jdouble __return__{ lkf_coreChannelGroup_set3DDistanceFilter(cc, custom, customLevel, centerFreq) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1get3DDistanceFilter
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannelGroup_get3DDistanceFilter(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1release
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_release(cc) };
		return __return__;
	}

	JNIEXPORT jstring JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getName
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jstring __return__{ jniEnv->NewStringUTF(lkf_coreChannelGroup_getName(cc)) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getNumChannels
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getNumChannels(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getChannel
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble index) {
		jdouble __return__{ lkf_coreChannelGroup_getChannel(cc, index) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getNumGroups
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getNumGroups(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getGroup
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble index) {
		jdouble __return__{ lkf_coreChannelGroup_getGroup(cc, index) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getParentGroup
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getParentGroup(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getDSP
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble index) {
		jdouble __return__{ lkf_coreChannelGroup_getDSP(cc, index) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1addDSP
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble index, jdouble cdsp) {
		jdouble __return__{ lkf_coreChannelGroup_addDSP(cc, index, cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1removeDSP
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble cdsp) {
		jdouble __return__{ lkf_coreChannelGroup_removeDSP(cc, cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getNumDSPs
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannelGroup_getNumDSPs(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1setDSPIndex
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble cdsp, jdouble index) {
		jdouble __return__{ lkf_coreChannelGroup_setDSPIndex(cc, cdsp, index) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannelGroup_1getDSPIndex
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble cdsp) {
		jdouble __return__{ lkf_coreChannelGroup_getDSPIndex(cc, cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1exists
	(JNIEnv* jniEnv, jobject jniThis, jdouble cchn) {
		jdouble __return__{ lkf_coreChannel_exists(cchn) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1stop
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_stop(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setPaused
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble paused) {
		jdouble __return__{ lkf_coreChannel_setPaused(cc, paused) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getPaused
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_getPaused(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setVolume
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble volume) {
		jdouble __return__{ lkf_coreChannel_setVolume(cc, volume) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getVolume
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_getVolume(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setVolumeRamp
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble ramp) {
		jdouble __return__{ lkf_coreChannel_setVolumeRamp(cc, ramp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getVolumeRamp
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_getVolumeRamp(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getAudibility
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_getAudibility(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setPitch
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble pitch) {
		jdouble __return__{ lkf_coreChannel_setPitch(cc, pitch) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getPitch
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_getPitch(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setMute
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble mute) {
		jdouble __return__{ lkf_coreChannel_setMute(cc, mute) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getMute
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_getMute(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setReverbProperties
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble instance, jdouble wet) {
		jdouble __return__{ lkf_coreChannel_setReverbProperties(cc, instance, wet) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getReverbProperties
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble instance) {
		jdouble __return__{ lkf_coreChannel_getReverbProperties(cc, instance) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setLowPassGain
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble gain) {
		jdouble __return__{ lkf_coreChannel_setLowPassGain(cc, gain) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getLowPassGain
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_getLowPassGain(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setMode
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble mode) {
		jdouble __return__{ lkf_coreChannel_setMode(cc, mode) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getMode
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_getMode(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1isPlaying
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_isPlaying(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setPan
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble pan) {
		jdouble __return__{ lkf_coreChannel_setPan(cc, pan) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setMixLevelsOutput
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble frontleft, jdouble frontright, jdouble center, jdouble lfe, jdouble surroundleft, jdouble surroundright, jdouble backleft, jdouble backright) {
		jdouble __return__{ lkf_coreChannel_setMixLevelsOutput(cc, frontleft, frontright, center, lfe, surroundleft, surroundright, backleft, backright) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getDSPClock
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		unsigned long long* _raw_retmem{ reinterpret_cast<unsigned long long*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannel_getDSPClock(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setDelay
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble clock_start, jdouble clock_end, jdouble stopchan) {
		jdouble __return__{ lkf_coreChannel_setDelay(cc, clock_start, clock_end, stopchan) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getDelay
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		unsigned long long* _raw_retmem{ reinterpret_cast<unsigned long long*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannel_getDelay(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1addFadePoint
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble clock, jdouble volume) {
		jdouble __return__{ lkf_coreChannel_addFadePoint(cc, clock, volume) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setFadePointRamp
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble clock, jdouble volume) {
		jdouble __return__{ lkf_coreChannel_setFadePointRamp(cc, clock, volume) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1removeFadePoints
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble clock_start, jdouble clock_end) {
		jdouble __return__{ lkf_coreChannel_removeFadePoints(cc, clock_start, clock_end) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getSystemObject
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_getSystemObject(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1set3DAttributes
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject vecs) {
		const FMOD_VECTOR* _raw_vecs{ reinterpret_cast<const FMOD_VECTOR*>(const_cast<const void*>(jniEnv->GetDirectBufferAddress(vecs))) };
		jdouble __return__{ lkf_coreChannel_set3DAttributes(cc, _raw_vecs) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1get3DAttributes
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		FMOD_VECTOR* _raw_retmem{ reinterpret_cast<FMOD_VECTOR*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannel_get3DAttributes(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1set3DMinMaxDistance
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble dmin, jdouble dmax) {
		jdouble __return__{ lkf_coreChannel_set3DMinMaxDistance(cc, dmin, dmax) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1get3DMinMaxDistance
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannel_get3DMinMaxDistance(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1set3DConeSettings
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble insideconeangle, jdouble outsideconeangle, jdouble outsidevolume) {
		jdouble __return__{ lkf_coreChannel_set3DConeSettings(cc, insideconeangle, outsideconeangle, outsidevolume) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1get3DConeSettings
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannel_get3DConeSettings(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1set3DConeOrientation
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject vec) {
		FMOD_VECTOR* _raw_vec{ reinterpret_cast<FMOD_VECTOR*>(jniEnv->GetDirectBufferAddress(vec)) };
		jdouble __return__{ lkf_coreChannel_set3DConeOrientation(cc, _raw_vec) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1set3DOcclusion
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble directocclusion, jdouble reverbocclusion) {
		jdouble __return__{ lkf_coreChannel_set3DOcclusion(cc, directocclusion, reverbocclusion) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1get3DOcclusion
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannel_get3DOcclusion(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1set3DSpread
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble angle) {
		jdouble __return__{ lkf_coreChannel_set3DSpread(cc, angle) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1get3DSpread
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_get3DSpread(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1set3DLevel
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble level) {
		jdouble __return__{ lkf_coreChannel_set3DLevel(cc, level) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1get3DLevel
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_get3DLevel(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1set3DDopplerLevel
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble level) {
		jdouble __return__{ lkf_coreChannel_set3DDopplerLevel(cc, level) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1get3DDopplerLevel
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_get3DDopplerLevel(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1set3DDistanceFilter
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble custom, jdouble customLevel, jdouble centerFreq) {
		jdouble __return__{ lkf_coreChannel_set3DDistanceFilter(cc, custom, customLevel, centerFreq) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1get3DDistanceFilter
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreChannel_get3DDistanceFilter(cc, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getDSP
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble index) {
		jdouble __return__{ lkf_coreChannel_getDSP(cc, index) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1addDSP
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble index, jdouble cdsp) {
		jdouble __return__{ lkf_coreChannel_addDSP(cc, index, cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1removeDSP
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble cdsp) {
		jdouble __return__{ lkf_coreChannel_removeDSP(cc, cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getNumDSPs
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc) {
		jdouble __return__{ lkf_coreChannel_getNumDSPs(cc) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1setDSPIndex
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble cdsp, jdouble index) {
		jdouble __return__{ lkf_coreChannel_setDSPIndex(cc, cdsp, index) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreChannel_1getDSPIndex
	(JNIEnv* jniEnv, jobject jniThis, jdouble cc, jdouble cdsp) {
		jdouble __return__{ lkf_coreChannel_getDSPIndex(cc, cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1exists
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp) {
		jdouble __return__{ lkf_coreDSP_exists(cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1release
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp) {
		jdouble __return__{ lkf_coreDSP_release(cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1getSystemObject
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp) {
		jdouble __return__{ lkf_coreDSP_getSystemObject(cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1setActive
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp, jdouble active) {
		jdouble __return__{ lkf_coreDSP_setActive(cdsp, active) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1getActive
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp) {
		jdouble __return__{ lkf_coreDSP_getActive(cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1setBypass
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp, jdouble bypass) {
		jdouble __return__{ lkf_coreDSP_setBypass(cdsp, bypass) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1getBypass
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp) {
		jdouble __return__{ lkf_coreDSP_getBypass(cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1setWetDryMix
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp, jdouble prewet, jdouble postwet, jdouble dry) {
		jdouble __return__{ lkf_coreDSP_setWetDryMix(cdsp, prewet, postwet, dry) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1getWetDryMix
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp, jobject retmem) {
		float* _raw_retmem{ reinterpret_cast<float*>(jniEnv->GetDirectBufferAddress(retmem)) };
		jdouble __return__{ lkf_coreDSP_getWetDryMix(cdsp, _raw_retmem) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1reset
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp) {
		jdouble __return__{ lkf_coreDSP_reset(cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1setParameterFloat
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp, jdouble index, jdouble value) {
		jdouble __return__{ lkf_coreDSP_setParameterFloat(cdsp, index, value) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1setParameterInt
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp, jdouble index, jdouble value) {
		jdouble __return__{ lkf_coreDSP_setParameterInt(cdsp, index, value) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1setParameterBool
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp, jdouble index, jdouble value) {
		jdouble __return__{ lkf_coreDSP_setParameterBool(cdsp, index, value) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1setParameterData
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp, jdouble index, jstring value, jdouble length) {
		jboolean _isCopy{ JNI_FALSE };
		const char* _cstr_value{ jniEnv->GetStringUTFChars(value, &_isCopy) };
		jdouble __return__{ lkf_coreDSP_setParameterData(cdsp, index, _cstr_value, length) };
		jniEnv->ReleaseStringUTFChars(value, _cstr_value);
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1getType
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp) {
		jdouble __return__{ lkf_coreDSP_getType(cdsp) };
		return __return__;
	}

	JNIEXPORT jdouble JNICALL Java_com_nkrapivindev_libkotfmod_LKFNative_lkf_1coreDSP_1getIdle
	(JNIEnv* jniEnv, jobject jniThis, jdouble cdsp) {
		jdouble __return__{ lkf_coreDSP_getIdle(cdsp) };
		return __return__;
	}

}
#endif /* __ANDROID__ */
