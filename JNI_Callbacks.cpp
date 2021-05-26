#ifdef __ANDROID__
#include "libkotfmod.h"

extern "C" {
#include <jni.h>
	static JavaVM* g_JavaVM{ nullptr };
	static jclass g_RunnerJNILib{ nullptr };
	static jclass g_String{ nullptr };
	static jmethodID g_CreateAsynEventWithDSMap{ nullptr };
	static jmethodID g_jCreateDsMap{ nullptr };
	static jmethodID g_DsMapAddDouble{ nullptr };
	static jmethodID g_DsMapAddString{ nullptr };

	// TODO: figure out thread safety.
	// doesn't quite work the same way between Core API and Studio API.
	//static JNIEnv* thrJNIEnv{ nullptr };

	void JNI_CreateAsynEventWithDSMap
	(int dsmapindex, int event_index) {
		if (g_RunnerJNILib && g_CreateAsynEventWithDSMap) {
			JNIEnv* thrJNIEnv{ nullptr };
			while (g_JavaVM->AttachCurrentThread(&thrJNIEnv, nullptr) != JNI_OK);
			thrJNIEnv->CallStaticVoidMethod(g_RunnerJNILib, g_CreateAsynEventWithDSMap, static_cast<jint>(dsmapindex), static_cast<jint>(event_index));
			//g_JavaVM->DetachCurrentThread();
		}
	}

	int JNI_CreateDsMap
	(int _num, ...) {
		va_list args;
		va_start(args, _num);
		int ret{ -1 };

		if (g_RunnerJNILib && g_String && g_jCreateDsMap) {
			JNIEnv* thrJNIEnv{ nullptr };
			while (g_JavaVM->AttachCurrentThread(&thrJNIEnv, nullptr) != JNI_OK);

			jobjectArray keys{ thrJNIEnv->NewObjectArray(_num, g_String, nullptr) };
			jobjectArray svals{ thrJNIEnv->NewObjectArray(_num, g_String, nullptr) };
			jdoubleArray sdoublevals{ thrJNIEnv->NewDoubleArray(_num) };

			// variadic args.
			for (int _i = 0; _i < _num; _i++) {
				const char* name{ va_arg(args, char*) };
				double dblval{ va_arg(args, double) };
				const char* strval{ va_arg(args, char*) };

				thrJNIEnv->SetObjectArrayElement(keys, _i, thrJNIEnv->NewStringUTF(name));

				if (strval == nullptr) {
					jdouble jdblval[1] = { static_cast<jdouble>(dblval) };
					thrJNIEnv->SetDoubleArrayRegion(sdoublevals, _i, 1, jdblval);
				}
				else {
					thrJNIEnv->SetObjectArrayElement(svals, _i, thrJNIEnv->NewStringUTF(strval));
				}
			}

			jint jret{ thrJNIEnv->CallStaticIntMethod(g_RunnerJNILib, g_jCreateDsMap, keys, svals, sdoublevals) };
			//g_JavaVM->DetachCurrentThread();
			ret = static_cast<int>(jret);
		}

		va_end(args);
		return ret;
	}

	bool JNI_DsMapAddD
	(int _index, const char* _pKey, double _value) {
		if (g_RunnerJNILib && g_DsMapAddDouble) {
			JNIEnv* thrJNIEnv{ nullptr };
			while (g_JavaVM->AttachCurrentThread(&thrJNIEnv, nullptr) != JNI_OK);
			thrJNIEnv->CallStaticVoidMethod(g_RunnerJNILib, g_DsMapAddDouble, static_cast<jint>(_index), thrJNIEnv->NewStringUTF(_pKey), static_cast<jdouble>(_value));
			//g_JavaVM->DetachCurrentThread();
			return true;
		}
		
		return false;
	}

	bool JNI_DsMapAddS
	(int _index, const char* _pKey, const char* _pValue) {
		if (g_RunnerJNILib && g_DsMapAddString) {
			JNIEnv* thrJNIEnv{ nullptr };
			while (g_JavaVM->AttachCurrentThread(&thrJNIEnv, nullptr) != JNI_OK);
			thrJNIEnv->CallStaticVoidMethod(g_RunnerJNILib, g_DsMapAddString, static_cast<jint>(_index), thrJNIEnv->NewStringUTF(_pKey), thrJNIEnv->NewStringUTF(_pValue));
			//g_JavaVM->DetachCurrentThread();
			return true;
		}
		
		return false;
	}

	JNIEXPORT jint JNI_OnLoad
	(JavaVM* vm, void* reserved) {
		LKF_TRACE("Hello from OnLoad!");
		g_JavaVM = vm;
		JNIEnv* thrJNIEnv{ nullptr };
		if (g_JavaVM->GetEnv(reinterpret_cast<void**>(&thrJNIEnv), JNI_VERSION_1_6) != JNI_OK) {
	    	return JNI_ERR;
		}

		// cache class references.
		g_RunnerJNILib = reinterpret_cast<jclass>(thrJNIEnv->NewGlobalRef(thrJNIEnv->FindClass("com/yoyogames/runner/RunnerJNILib")));
		g_String = reinterpret_cast<jclass>(thrJNIEnv->NewGlobalRef(thrJNIEnv->FindClass("java/lang/String")));
		// static method ids are not cachable.
		g_CreateAsynEventWithDSMap = thrJNIEnv->GetStaticMethodID(g_RunnerJNILib, "CreateAsynEventWithDSMap", "(II)V");
		g_jCreateDsMap = thrJNIEnv->GetStaticMethodID(g_RunnerJNILib, "jCreateDsMap", "([Ljava/lang/String;[Ljava/lang/String;[D)I");
		g_DsMapAddDouble = thrJNIEnv->GetStaticMethodID(g_RunnerJNILib, "DsMapAddDouble", "(ILjava/lang/String;D)V");
		g_DsMapAddString = thrJNIEnv->GetStaticMethodID(g_RunnerJNILib, "DsMapAddString", "(ILjava/lang/String;Ljava/lang/String;)V");

		// then ping the callback registrar.
		RegisterCallbacks(
			reinterpret_cast<void*>(JNI_CreateAsynEventWithDSMap),
			reinterpret_cast<void*>(JNI_CreateDsMap),
			reinterpret_cast<void*>(JNI_DsMapAddD),
			reinterpret_cast<void*>(JNI_DsMapAddS)
		);

		// we're done, please use the highest JNI version.
		return JNI_VERSION_1_6;
	}

	JNIEXPORT void JNI_OnUnload
	(JavaVM* vm, void* reserved) {
		LKF_TRACE("Goodbye from OnUnload!");

		g_JavaVM = vm;
		JNIEnv* thrJNIEnv{ nullptr };
		if (g_JavaVM->GetEnv(reinterpret_cast<void**>(&thrJNIEnv), JNI_VERSION_1_6) != JNI_OK) {
		//if (false) {
			LKF_TRACE("Failed to get the JNIEnv in OnUnload. :(");
	    	return;
		}

		// free the globalrefs.
		if (g_RunnerJNILib) thrJNIEnv->DeleteGlobalRef(g_RunnerJNILib);
		if (g_String) thrJNIEnv->DeleteGlobalRef(g_String);
	}
}
#endif /* __ANDROID__ */
