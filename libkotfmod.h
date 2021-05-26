#pragma once

#include <fmod_studio.hpp>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstdio>
#include <cstring>
#include "gmdscallback.h"
#include "framework.h"

#define dllx extern "C" F_EXPORT

class Global {
public:
	static std::size_t SystemLast;
	static std::size_t BankLast;
	static std::size_t EventDescriptionLast;
	static std::size_t EventInstanceLast;
	static std::size_t CoreSystemLast;
	static std::size_t CoreSoundLast;
	static std::size_t CoreChannelGroupLast;
	static std::size_t CoreChannelLast;
	static std::size_t CoreDSPLast;
	static std::unordered_map<std::size_t, FMOD::Studio::System*> Systems;
	static std::unordered_map<std::size_t, FMOD::System*> CoreSystems;
	static std::unordered_map<std::size_t, FMOD::Studio::Bank*> Banks;
	static std::unordered_map<std::size_t, FMOD::Studio::EventDescription*> EventDescriptions;
	static std::unordered_map<std::size_t, FMOD::Studio::EventInstance*> EventInstances;
	static std::unordered_map<std::size_t, FMOD::Sound*> CoreSounds;
	static std::unordered_map<std::size_t, FMOD::ChannelGroup*> CoreChannelGroups;
	static std::unordered_map<std::size_t, FMOD::Channel*> CoreChannels;
	static std::unordered_map<std::size_t, FMOD::DSP*> DSPs;
};

#define LKF_NDK_TAG "yoyo"
#define LKF_LOG_PREFIX "libkotfmod [C++ Trace]: "

#ifndef __ANDROID__
#define LKF_TRACE(...) std::printf(LKF_LOG_PREFIX __VA_ARGS__); std::printf("\n"); std::fflush(stdout);
#else
/* NDK logging */
#include <android/log.h>
#define LKF_TRACE(...) __android_log_print(ANDROID_LOG_INFO, LKF_NDK_TAG, LKF_LOG_PREFIX __VA_ARGS__);
#endif

#define LKF_OK(x) ((x) == FMOD_OK)

// Will be exported to GmxGen as constants.
// Must match with the FMOD_ enum, please don't forget to update it.

/// LKF Core API Init options.
enum eLKF_INIT {
	LKF_INIT_NORMAL = 0,
	LKF_INIT_STREAM_FROM_UPDATE = 1,
	LKF_INIT_MIX_FROM_UPDATE = 2,
	LKF_INIT_3D_RIGHTHANDED = 4,
	LKF_INIT_CHANNEL_LOWPASS = 256,
	LKF_INIT_CHANNEL_DISTANCEFILTER = 512,
	LKF_INIT_PROFILE_ENABLE = 65536,
	LKF_INIT_VOL0_BECOMES_VIRTUAL = 131072,
	LKF_INIT_GEOMETRY_USECLOSEST = 262144,
	LKF_INIT_PREFER_DOLBY_DOWNMIX = 524288,
	LKF_INIT_THREAD_UNSAFE = 1048576,
	LKF_INIT_PROFILE_METER_ALL = 2097152,
	LKF_INIT_MEMORY_TRACKING = 4194304
};

/// LKF Studio API Init options.
enum eLKF_STUDIO_INIT {
	LKF_STUDIO_INIT_NORMAL = 0,
	LKF_STUDIO_INIT_LIVEUPDATE = 1,
	LKF_STUDIO_INIT_ALLOW_MISSING_PLUGINS = 2,
	LKF_STUDIO_INIT_SYNCHRONOUS_UPDATE = 4,
	LKF_STUDIO_INIT_DEFERRED_CALLBACKS = 8,
	LKF_STUDIO_INIT_LOAD_FROM_UPDATE = 16,
	LKF_STUDIO_INIT_MEMORY_TRACKING = 32
};

/// LKF Bank Loading options.
enum eLKF_LOAD_BANK {
	LKF_LOAD_BANK_NORMAL = 0,
	LKF_LOAD_BANK_NONBLOCKING = 1,
	LKF_LOAD_BANK_DECOMPRESS_SAMPLES = 2,
	LKF_LOAD_BANK_UNENCRYPTED = 4
};

/// LKF Error codes.
enum eLKF_RESULT {
	LKF_ERR_INVALID_INDEX = -2147483647, // special value only used by LKF, matches INT32_MIN
	LKF_ERR_BADCOMMAND,
	LKF_ERR_CHANNEL_ALLOC,
	LKF_ERR_CHANNEL_STOLEN,
	LKF_ERR_DMA,
	LKF_ERR_DSP_CONNECTION,
	LKF_ERR_DSP_DONTPROCESS,
	LKF_ERR_DSP_FORMAT,
	LKF_ERR_DSP_INUSE,
	LKF_ERR_DSP_NOTFOUND,
	LKF_ERR_DSP_RESERVED,
	LKF_ERR_DSP_SILENCE,
	LKF_ERR_DSP_TYPE,
	LKF_ERR_FILE_BAD,
	LKF_ERR_FILE_COULDNOTSEEK,
	LKF_ERR_FILE_DISKEJECTED,
	LKF_ERR_FILE_EOF,
	LKF_ERR_FILE_ENDOFDATA,
	LKF_ERR_FILE_NOTFOUND,
	LKF_ERR_FORMAT,
	LKF_ERR_HEADER_MISMATCH,
	LKF_ERR_HTTP,
	LKF_ERR_HTTP_ACCESS,
	LKF_ERR_HTTP_PROXY_AUTH,
	LKF_ERR_HTTP_SERVER_ERROR,
	LKF_ERR_HTTP_TIMEOUT,
	LKF_ERR_INITIALIZATION,
	LKF_ERR_INITIALIZED,
	LKF_ERR_INTERNAL,
	LKF_ERR_INVALID_FLOAT,
	LKF_ERR_INVALID_HANDLE,
	LKF_ERR_INVALID_PARAM,
	LKF_ERR_INVALID_POSITION,
	LKF_ERR_INVALID_SPEAKER,
	LKF_ERR_INVALID_SYNCPOINT,
	LKF_ERR_INVALID_THREAD,
	LKF_ERR_INVALID_VECTOR,
	LKF_ERR_MAXAUDIBLE,
	LKF_ERR_MEMORY,
	LKF_ERR_MEMORY_CANTPOINT,
	LKF_ERR_NEEDS3D,
	LKF_ERR_NEEDSHARDWARE,
	LKF_ERR_NET_CONNECT,
	LKF_ERR_NET_SOCKET_ERROR,
	LKF_ERR_NET_URL,
	LKF_ERR_NET_WOULD_BLOCK,
	LKF_ERR_NOTREADY,
	LKF_ERR_OUTPUT_ALLOCATED,
	LKF_ERR_OUTPUT_CREATEBUFFER,
	LKF_ERR_OUTPUT_DRIVERCALL,
	LKF_ERR_OUTPUT_FORMAT,
	LKF_ERR_OUTPUT_INIT,
	LKF_ERR_OUTPUT_NODRIVERS,
	LKF_ERR_PLUGIN,
	LKF_ERR_PLUGIN_MISSING,
	LKF_ERR_PLUGIN_RESOURCE,
	LKF_ERR_PLUGIN_VERSION,
	LKF_ERR_RECORD,
	LKF_ERR_REVERB_CHANNELGROUP,
	LKF_ERR_REVERB_INSTANCE,
	LKF_ERR_SUBSOUNDS,
	LKF_ERR_SUBSOUND_ALLOCATED,
	LKF_ERR_SUBSOUND_CANTMOVE,
	LKF_ERR_TAGNOTFOUND,
	LKF_ERR_TOOMANYCHANNELS,
	LKF_ERR_TRUNCATED,
	LKF_ERR_UNIMPLEMENTED,
	LKF_ERR_UNINITIALIZED,
	LKF_ERR_UNSUPPORTED,
	LKF_ERR_VERSION,
	LKF_ERR_EVENT_ALREADY_LOADED,
	LKF_ERR_EVENT_LIVEUPDATE_BUSY,
	LKF_ERR_EVENT_LIVEUPDATE_MISMATCH,
	LKF_ERR_EVENT_LIVEUPDATE_TIMEOUT,
	LKF_ERR_EVENT_NOTFOUND,
	LKF_ERR_STUDIO_UNINITIALIZED,
	LKF_ERR_STUDIO_NOT_LOADED,
	LKF_ERR_INVALID_STRING,
	LKF_ERR_ALREADY_LOCKED,
	LKF_ERR_NOT_LOCKED,
	LKF_ERR_RECORD_DISCONNECTED,
	LKF_ERR_TOOMANYSAMPLES,
	LKF_ERR_MAX
};

/// LKF Stop Mode.
enum eLKF_STOP_MODE {
	LKF_STOP_ALLOWFADEOUT,
	LKF_STOP_IMMEDIATE
};

/// LKF Event Properties.
enum eLKF_EVENT_PROPERTY {
	LKF_EVENT_PROPERTY_CHANNELPRIORITY,
	LKF_EVENT_PROPERTY_SCHEDULE_DELAY,
	LKF_EVENT_PROPERTY_SCHEDULE_LOOKAHEAD,
	LKF_EVENT_PROPERTY_MINIMUM_DISTANCE,
	LKF_EVENT_PROPERTY_MAXIMUM_DISTANCE,
	LKF_EVENT_PROPERTY_COOLDOWN,
	LKF_EVENT_PROPERTY_MAX
};

/// LKF Playback State.
enum eLKF_PLAYBACK_STATE {
	LKF_PLAYBACK_PLAYING,
	LKF_PLAYBACK_SUSTAINING,
	LKF_PLAYBACK_STOPPED,
	LKF_PLAYBACK_STARTING,
	LKF_PLAYBACK_STOPPING
};

/// LKF Loading State.
enum eLKF_LOADING_STATE {
	LKF_LOADING_STATE_UNLOADING,
	LKF_LOADING_STATE_UNLOADED,
	LKF_LOADING_STATE_LOADING,
	LKF_LOADING_STATE_LOADED,
	LKF_LOADING_STATE_ERROR
};

/// LKF Studio System Callback Type.
enum eLKF_STUDIO_SYSTEM_CALLBACK {
	LKF_SYSTEM_CALLBACK_PREUPDATE = 1,
	LKF_SYSTEM_CALLBACK_POSTUPDATE = 2,
	LKF_SYSTEM_CALLBACK_BANK_UNLOAD = 4,
	LKF_SYSTEM_CALLBACK_LIVEUPDATE_CONNECTED = 8,
	LKF_SYSTEM_CALLBACK_LIVEUPDATE_DISCONNECTED = 16
};

/// LKF Studio EventInstance Callback Type.
enum eLKF_STUDIO_EVINST_CALLBACK {
	LKF_EVENT_CALLBACK_CREATED = 1,
	LKF_EVENT_CALLBACK_DESTROYED = 2,
	LKF_EVENT_CALLBACK_STARTING = 4,
	LKF_EVENT_CALLBACK_STARTED = 8,
	LKF_EVENT_CALLBACK_RESTARTED = 16,
	LKF_EVENT_CALLBACK_STOPPED = 32,
	LKF_EVENT_CALLBACK_START_FAILED = 64,
	LKF_EVENT_CALLBACK_CREATE_PROGRAMMER_SOUND = 128,
	LKF_EVENT_CALLBACK_DESTROY_PROGRAMMER_SOUND = 256,
	LKF_EVENT_CALLBACK_PLUGIN_CREATED = 512,
	LKF_EVENT_CALLBACK_PLUGIN_DESTROYED = 1024,
	LKF_EVENT_CALLBACK_TIMELINE_MARKER = 2048,
	LKF_EVENT_CALLBACK_TIMELINE_BEAT = 4096,
	LKF_EVENT_CALLBACK_SOUND_PLAYED = 8192,
	LKF_EVENT_CALLBACK_SOUND_STOPPED = 16384,
	LKF_EVENT_CALLBACK_REAL_TO_VIRTUAL = 32768,
	LKF_EVENT_CALLBACK_VIRTUAL_TO_REAL = 65536,
	LKF_EVENT_CALLBACK_START_EVENT_COMMAND = 131072
};

/// LKF Core System Speaker Parameters.
enum eLKF_CORE_SYSTEM_SPEAKERMODE {
	LKF_SPEAKERMODE_DEFAULT,
	LKF_SPEAKERMODE_RAW,
	LKF_SPEAKERMODE_MONO,
	LKF_SPEAKERMODE_STEREO,
	LKF_SPEAKERMODE_QUAD,
	LKF_SPEAKERMODE_SURROUND,
	LKF_SPEAKERMODE_5POINT1,
	LKF_SPEAKERMODE_7POINT1,
	LKF_SPEAKERMODE_7POINT1POINT4
};

/// LKF Core Sound Mode.
enum eLKF_MODE_CORE_SOUND {
	LKF_MODE_DEFAULT = 0,
	LKF_MODE_LOOP_OFF = 1,
	LKF_MODE_LOOP_NORMAL = 2,
	LKF_MODE_LOOP_BIDI = 4,
	LKF_MODE_2D = 8,
	LKF_MODE_3D = 16,
	LKF_MODE_CREATESTREAM = 128,
	LKF_MODE_CREATESAMPLE = 256,
	LKF_MODE_CREATECOMPRESSEDSAMPLE = 512,
	LKF_MODE_OPENUSER = 1024,
	LKF_MODE_OPENMEMORY = 2048,
	LKF_MODE_OPENMEMORY_POINT = 268435456,
	LKF_MODE_OPENRAW = 4096,
	LKF_MODE_OPENONLY = 8192,
	LKF_MODE_ACCURATETIME = 16384,
	LKF_MODE_MPEGSEARCH = 32768,
	LKF_MODE_NONBLOCKING = 65536,
	LKF_MODE_UNIQUE = 131072,
	LKF_MODE_3D_HEADRELATIVE = 262144,
	LKF_MODE_3D_WORLDRELATIVE = 524288,
	LKF_MODE_3D_INVERSEROLLOFF = 1048576,
	LKF_MODE_3D_LINEARROLLOFF = 2097152,
	LKF_MODE_3D_LINEARSQUAREROLLOFF = 4194304,
	LKF_MODE_3D_INVERSETAPEREDROLLOFF = 8388608,
	LKF_MODE_3D_CUSTOMROLLOFF = 67108864,
	LKF_MODE_3D_IGNOREGEOMETRY = 1073741824,
	LKF_MODE_IGNORETAGS = 33554432,
	LKF_MODE_LOWMEM = 134217728,
	LKF_MODE_VIRTUAL_PLAYFROMSTART = 0x80000000
};

/// LKF Core System Speaker.
enum eLKF_CORE_SPEAKER {
	LKF_SPEAKER_NONE = -1,
	LKF_SPEAKER_FRONT_LEFT = 0,
	LKF_SPEAKER_FRONT_RIGHT,
	LKF_SPEAKER_FRONT_CENTER,
	LKF_SPEAKER_LOW_FREQUENCY,
	LKF_SPEAKER_SURROUND_LEFT,
	LKF_SPEAKER_SURROUND_RIGHT,
	LKF_SPEAKER_BACK_LEFT,
	LKF_SPEAKER_BACK_RIGHT,
	LKF_SPEAKER_TOP_FRONT_LEFT,
	LKF_SPEAKER_TOP_FRONT_RIGHT,
	LKF_SPEAKER_TOP_BACK_LEFT,
	LKF_SPEAKER_TOP_BACK_RIGHT,
	LKF_SPEAKER_MAX
};

/// LKF Core System Output type.
enum eLKF_CORE_SYSTEM_OUTPUTTYPE {
	LKF_OUTPUTTYPE_AUTODETECT,
	LKF_OUTPUTTYPE_UNKNOWN,
	LKF_OUTPUTTYPE_NOSOUND,
	LKF_OUTPUTTYPE_WAVWRITER,
	LKF_OUTPUTTYPE_NOSOUND_NRT,
	LKF_OUTPUTTYPE_WAVWRITER_NRT,
	LKF_OUTPUTTYPE_WASAPI,
	LKF_OUTPUTTYPE_ASIO,
	LKF_OUTPUTTYPE_PULSEAUDIO,
	LKF_OUTPUTTYPE_ALSA,
	LKF_OUTPUTTYPE_COREAUDIO,
	LKF_OUTPUTTYPE_AUDIOTRACK,
	LKF_OUTPUTTYPE_OPENSL,
	LKF_OUTPUTTYPE_AUDIOOUT,
	LKF_OUTPUTTYPE_AUDIO3D,
	LKF_OUTPUTTYPE_WEBAUDIO,
	LKF_OUTPUTTYPE_NNAUDIO,
	LKF_OUTPUTTYPE_WINSONIC,
	LKF_OUTPUTTYPE_AAUDIO
};

/// LKF Core System Timeuint type.
enum eLKF_CORE_TIMEUNIT {
	LKF_TIMEUNIT_MS = 1,
	LKF_TIMEUNIT_PCM = 2,
	LKF_TIMEUNIT_PCMBYTES = 4,
	LKF_TIMEUNIT_RAWBYTES = 8,
	LKF_TIMEUNIT_PCMFRACTION = 16,
	LKF_TIMEUNIT_MODORDER = 256,
	LKF_TIMEUNIT_MODROW = 512,
	LKF_TIMEUNIT_MODPATTERN = 1024
};

/// LKF Core DSP type.
enum eLKF_CORE_DSP_TYPE {
	LKF_DSP_TYPE_UNKNOWN,
	LKF_DSP_TYPE_MIXER,
	LKF_DSP_TYPE_OSCILLATOR,
	LKF_DSP_TYPE_LOWPASS,
	LKF_DSP_TYPE_ITLOWPASS,
	LKF_DSP_TYPE_HIGHPASS,
	LKF_DSP_TYPE_ECHO,
	LKF_DSP_TYPE_FADER,
	LKF_DSP_TYPE_FLANGE,
	LKF_DSP_TYPE_DISTORTION,
	LKF_DSP_TYPE_NORMALIZE,
	LKF_DSP_TYPE_LIMITER,
	LKF_DSP_TYPE_PARAMEQ,
	LKF_DSP_TYPE_PITCHSHIFT,
	LKF_DSP_TYPE_CHORUS,
	LKF_DSP_TYPE_VSTPLUGIN,
	LKF_DSP_TYPE_WINAMPPLUGIN,
	LKF_DSP_TYPE_ITECHO,
	LKF_DSP_TYPE_COMPRESSOR,
	LKF_DSP_TYPE_SFXREVERB,
	LKF_DSP_TYPE_LOWPASS_SIMPLE,
	LKF_DSP_TYPE_DELAY,
	LKF_DSP_TYPE_TREMOLO,
	LKF_DSP_TYPE_LADSPAPLUGIN,
	LKF_DSP_TYPE_SEND,
	LKF_DSP_TYPE_RETURN,
	LKF_DSP_TYPE_HIGHPASS_SIMPLE,
	LKF_DSP_TYPE_PAN,
	LKF_DSP_TYPE_THREE_EQ,
	LKF_DSP_TYPE_FFT,
	LKF_DSP_TYPE_LOUDNESS_METER,
	LKF_DSP_TYPE_ENVELOPEFOLLOWER,
	LKF_DSP_TYPE_CONVOLUTIONREVERB,
	LKF_DSP_TYPE_CHANNELMIX,
	LKF_DSP_TYPE_TRANSCEIVER,
	LKF_DSP_TYPE_OBJECTPAN,
	LKF_DSP_TYPE_MULTIBAND_EQ
};

/// LKF Core ChannelControl type.
enum eLKF_CORE_CHANNELCONTROL_TYPE {
	LKF_CHANNELCONTROL_CHANNEL,
	LKF_CHANNELCONTROL_CHANNELGROUP
};

/// LKF Core ChannelControl callback type.
enum eLKF_CORE_CHANNELCONTROL_CALLBACK_TYPE {
	LKF_CHANNELCONTROL_CALLBACK_END,
	LKF_CHANNELCONTROL_CALLBACK_VIRTUALVOICE,
	LKF_CHANNELCONTROL_CALLBACK_SYNCPOINT,
	LKF_CHANNELCONTROL_CALLBACK_OCCLUSION
};

/// LKF Core System callback type.
enum eLKF_CORE_SYSTEM_CALLBACK {
	LKF_SYSTEM_CALLBACK_DEVICELISTCHANGED = 1,
	LKF_SYSTEM_CALLBACK_DEVICELOST = 2,
	LKF_SYSTEM_CALLBACK_MEMORYALLOCATIONFAILED = 4,
	LKF_SYSTEM_CALLBACK_THREADCREATED = 8,
	LKF_SYSTEM_CALLBACK_BADDSPCONNECTION = 16,
	LKF_SYSTEM_CALLBACK_PREMIX = 32,
	LKF_SYSTEM_CALLBACK_POSTMIX = 64,
	LKF_SYSTEM_CALLBACK_ERROR = 128,
	LKF_SYSTEM_CALLBACK_MIDMIX = 256,
	LKF_SYSTEM_CALLBACK_THREADDESTROYED = 512,
	LKF_SYSTEM_CALLBACK_RECORDLISTCHANGED = 4096,
	LKF_SYSTEM_CALLBACK_BUFFEREDNOMIX = 8192,
	LKF_SYSTEM_CALLBACK_DEVICEREINITIALIZE = 16384,
	LKF_SYSTEM_CALLBACK_OUTPUTUNDERRUN = 32768
};

FMOD_RESULT F_CALL lkf_coreSystem_callback(FMOD_SYSTEM* system, FMOD_SYSTEM_CALLBACK_TYPE type, void* commanddata1, void* commanddata2, void* userdata);
FMOD_RESULT F_CALL lkf_coreChannelControl_callback(FMOD_CHANNELCONTROL* channelcontrol, FMOD_CHANNELCONTROL_TYPE controltype, FMOD_CHANNELCONTROL_CALLBACK_TYPE callbacktype, void* commanddata1, void* commanddata2);
FMOD_RESULT F_CALLBACK lkf_studio_event_callback(FMOD_STUDIO_EVENT_CALLBACK_TYPE type, FMOD_STUDIO_EVENTINSTANCE* event, void* parameters);
FMOD_RESULT F_CALLBACK lkf_studio_system_callback(FMOD_STUDIO_SYSTEM* system, FMOD_STUDIO_SYSTEM_CALLBACK_TYPE type, void* commanddata, void* userdata);

template<typename T> std::size_t lkf_T_indexOf(const std::unordered_map<std::size_t, T>& map, const T& item) {
	for (const std::pair<std::size_t, T>& p : map) {
		if (p.second == item) {
			return p.first;
		}
	}

	return SIZE_MAX;
}

template<typename T> void lkf_T_pop_back_smart(std::unordered_map<std::size_t, T>& map, std::size_t index, std::size_t& lastind) {
	if (map.find(index) == map.end()) {
		LKF_TRACE("WHAT THE HELL?! [%zu]!", index);
	}

	map.erase(index);
	if (index == (lastind - 1)) {
		lastind--;
	}

	LKF_TRACE("Erased item [%zu].", index);
}

template<typename T> std::size_t lkf_T_push_back_smart(std::unordered_map<std::size_t, T>& map, const T& item, std::size_t& lastind) {
	std::size_t supposed{ lkf_T_indexOf(map, item) };
	if (supposed != SIZE_MAX) {
		LKF_TRACE("Wtf, a duplicate in the map?!");
		return supposed;
	}

	for (std::size_t i{ 0 }; i < lastind; i++) {
		if (map.find(i) == map.end()) {
			LKF_TRACE("Reusing index [%zu].", i);
			map[i] = item;
			return i;
		}
	}

	std::size_t myind{ lastind };
	lastind++;
	LKF_TRACE("Registering new index [%zu].", myind);
	map[myind] = item;

	return myind;
}

inline double lkf_err_code(const FMOD_RESULT fr) {
	return static_cast<double>(LKF_ERR_INVALID_INDEX + fr);
}

// [libkotfmod API]: Internal initialization stuff, see libkotfmod.cpp

///->number : Init function. DO NOT CALL.
dllx double lkf_internal_init();
///->number : Finalization function. DO NOT CALL.
dllx double lkf_internal_final();
///->number : Returns true if the DLL was loaded correctly.
dllx double lkf_is_present();
///->string : Do. Not. Call.
dllx char* RegisterCallbacks(void* please, void* dont, void* call, void* it);
///->number : Returns true if the callback stuff was registered fine.
dllx double lkf_are_callbacks_registered();
///->string : Turns an error code into a string!
dllx const char* lkf_enum_result_reflection(double value);
///->string : Turns an event instance callback type into a string!
dllx const char* lkf_enum_event_instance_callback_reflection(double value);
///->string : Turns a system callback type into a string!
dllx const char* lkf_enum_system_callback_reflection(double value);
///->number : Returns the FMOD api version.
dllx double lkf_get_api_version();

// [Studio API]: FMOD::Studio::System, see libkotfmod_System.cpp

///->number : Creates a new instance of the Studio System.
dllx double lkf_system_create();
///->number : MUST BE CALLED EVERY FRAME!
dllx double lkf_system_update(double system);
///->number : Checks if passed System index is valid. (doesn't mean the System's state is valid!)
dllx double lkf_system_exists(double system);
///->number : Initializes an instance of the System.
dllx double lkf_system_initialize(double system, double maxchannels, double studioflags, double flags);
///->number : Loads a Bank from file path.
dllx double lkf_system_loadBankFile(double system, const char* filename, double flags);
///->number : Creates an EventInstance by asset path.
dllx double lkf_system_getEvent(double system, const char* path);
///->number : Unloads all banks.
dllx double lkf_system_unloadAll(double system);
///->number : 
dllx double lkf_system_setListenerAttributes(double system, double listener, const FMOD_3D_ATTRIBUTES* attributes, const FMOD_VECTOR* attenuationposition);
///->number : 
dllx double lkf_system_release(double system);
///->number : 
dllx double lkf_system_flushCommands(double system);
///->number : 
dllx double lkf_system_flushSampleLoading(double system);
///->number : 
dllx double lkf_system_getCPUUsage(double system, FMOD_STUDIO_CPU_USAGE* retmem);
///->number : 
dllx double lkf_system_getMemoryUsage(double system, FMOD_STUDIO_MEMORY_USAGE* memoryusage);
///->number : 
dllx double lkf_system_getCoreSystem(double system);

// [Studio API]: FMOD::Studio::Bank, see libkotfmod_Bank.cpp

///->number : 
dllx double lkf_bank_exists(double bank);
///->number : 
dllx double lkf_bank_unload(double bank);
///->number : 
dllx double lkf_bank_loadSampleData(double bank);
///->number : 
dllx double lkf_bank_unloadSampleData(double bank);
///->number : 
dllx double lkf_bank_getLoadingState(double bank);
///->number : 
dllx double lkf_bank_getSampleLoadingState(double bank);

// [Studio API]: FMOD::Studio::EventDescription, see libkotfmod_EventDescription.cpp

///->number : 
dllx double lkf_eventDescription_exists(double evdesc);
///->number : 
dllx double lkf_eventDescription_createInstance(double evdesc);
///->number : 
dllx double lkf_eventDescription_loadSampleData(double evdesc);
///->number : 
dllx double lkf_eventDescription_unloadSampleData(double evdesc);
///->number : 
dllx double lkf_eventDescription_releaseAllInstances(double evdesc);
///->number : 
dllx double lkf_eventDescription_getSampleLoadingState(double evdesc);
///->number : 
dllx double lkf_eventDescription_isSnapshot(double evdesc);
///->number : 
dllx double lkf_eventDescription_isOneshot(double evdesc);
///->number : 
dllx double lkf_eventDescription_isStream(double evdesc);
///->number : 
dllx double lkf_eventDescription_is3D(double evdesc);
///->number : 
dllx double lkf_eventDescription_isDopplerEnabled(double evdesc);
///->number : 
dllx double lkf_eventDescription_hasCue(double evdesc);

// [Studio API]: FMOD::Studio::EventInstance, see libkotfmod_EventInstance.cpp

///->number : 
dllx double lkf_eventInstance_exists(double evinst);
///->number : 
dllx double lkf_eventInstance_start(double evinst);
///->number : 
dllx double lkf_eventInstance_stop(double evinst, double stopmode);
///->number : 
dllx double lkf_eventInstance_setParameterByName(double evinst, const char* name, double value, double ignoreseekspeed);
///->number : 
dllx double lkf_eventInstance_getParameterByName(double evinst, const char* name, float* retmem);
///->number : 
dllx double lkf_eventInstance_set3DAttributes(double evinst, const FMOD_3D_ATTRIBUTES* attributes);
///->number : 
dllx double lkf_eventInstance_get3DAttributes(double evinst, FMOD_3D_ATTRIBUTES* retattr);
///->number : 
dllx double lkf_eventInstance_setVolume(double evinst, double volume);
///->number : 
dllx double lkf_eventInstance_getVolume(double evinst, float* retmem);
///->number : 
dllx double lkf_eventInstance_setPitch(double evinst, double pitch);
///->number : 
dllx double lkf_eventInstance_getPitch(double evinst, float* retmem);
///->number : 
dllx double lkf_eventInstance_release(double evinst);
///->number : 
dllx double lkf_eventInstance_triggerCue(double evinst);
///->number : 
dllx double lkf_eventInstance_getPaused(double evinst);
///->number : 
dllx double lkf_eventInstance_setPaused(double evinst, double paused);
///->number : 
dllx double lkf_eventInstance_setReverbLevel(double evinst, double index, double level);
///->number : 
dllx double lkf_eventInstance_getReverbLevel(double evinst, double index);
///->number : 
dllx double lkf_eventInstance_setTimelinePosition(double evinst, double position);
///->number : 
dllx double lkf_eventInstance_getTimelinePosition(double evinst);
///->number : 
dllx double lkf_eventInstance_setListenerMask(double evinst, double mask);
///->number : 
dllx double lkf_eventInstance_getListenerMask(double evinst);
///->number : 
dllx double lkf_eventInstance_getDescription(double evinst);
///->number : 
dllx double lkf_eventInstance_isVirtual(double evinst);

// [Core API]: FMOD::System, see libkotfmod_CoreSystem.cpp

///->number : 
dllx double lkf_coreSystem_exists(double csys);
///->number : 
dllx double lkf_coreSystem_setSoftwareFormat(double csys, double samplerate, double speakermode, double numrawspeakers);

// TODO: add this to JNI, since nik is a dumb dungo buffon he'll probably forget to do this
// and the android build will crash with an UnsatisfiedLinkError exception.

///->number : 
dllx double lkf_coreSystem_create();
///->number : 
dllx double lkf_coreSystem_init(double csys, double maxchannels, double initflags);
///->number : 
dllx double lkf_coreSystem_update(double csys);
///->number : 
dllx double lkf_coreSystem_close(double csys);
///->number : 
dllx double lkf_coreSystem_release(double csys);
///->number : 
dllx double lkf_coreSystem_setOutput(double csys, double output);
///->number : 
dllx double lkf_coreSystem_getOutput(double csys);
///->number : 
dllx double lkf_coreSystem_setSoftwareChannels(double csys, double numsoftwarechannels);
///->number : 
dllx double lkf_coreSystem_getSoftwareChannels(double csys);
///->number : 
dllx double lkf_coreSystem_getSoftwareFormat(double csys, int* retmem);
///->number : 
dllx double lkf_coreSystem_setDSPBufferSize(double csys, double bufferlen, double numbuffers);
///->number : 
dllx double lkf_coreSystem_getDSPBufferSize(double csys, int* retmem);
///->number : 
dllx double lkf_coreSystem_setPluginPath(double csys, const char* path);
///->number : 
dllx double lkf_coreSystem_loadPlugin(double csys, const char* name, double priority);
///->number : 
dllx double lkf_coreSystem_unloadPlugin(double csys, double handle);
///->number : 
dllx double lkf_coreSystem_setOutputByPlugin(double csys, double handle);
///->number : 
dllx double lkf_coreSystem_getOutputByPlugin(double csys);
///->number : 
dllx double lkf_coreSystem_setSpeakerPosition(double csys, double speaker, double x, double y, double active);
///->number : 
dllx double lkf_coreSystem_getSpeakerPosition(double csys, double speaker, float* retmem);
///->number : 
dllx double lkf_coreSystem_setStreamBufferSize(double csys, double filebuffersize, double filebuffersizetype);
///->number : 
dllx double lkf_coreSystem_getStreamBufferSize(double csys, unsigned int* retmem);
///->number : 
dllx double lkf_coreSystem_set3DSettings(double csys, double dopplerscale, double distancefactor, double rolloffscale);
///->number : 
dllx double lkf_coreSystem_get3DSettings(double csys, float* retmem);
///->number : 
dllx double lkf_coreSystem_set3DNumListeners(double csys, double num);
///->number : 
dllx double lkf_coreSystem_get3DNumListeners(double csys);
///->number : 
dllx double lkf_coreSystem_set3DListenerAttributes(double csys, double listener, const FMOD_VECTOR* vecs);
///->number : 
dllx double lkf_coreSystem_get3DListenerAttributes(double csys, double listener, FMOD_VECTOR* retmem);
///->number : 
dllx double lkf_coreSystem_mixerSuspend(double csys);
///->number : 
dllx double lkf_coreSystem_mixerResume(double csys);
///->number : 
dllx double lkf_coreSystem_getVersion(double csys);
///->number : 
dllx double lkf_coreSystem_getOutputHandle(double csys);
///->number : 
dllx double lkf_coreSystem_getChannelsPlaying(double csys, int* retmem);
///->number : 
dllx double lkf_coreSystem_getCPUUsage(double csys, float* retmem);
///->number : 
dllx double lkf_coreSystem_getCPUUsageEx(double csys, float* retmem);
///->number : 
dllx double lkf_coreSystem_getFileUsage(double csys, long long* retmem);
///->number : 
dllx double lkf_coreSystem_lockDSP(double csys);
///->number : 
dllx double lkf_coreSystem_unlockDSP(double csys);
///->number : 
dllx double lkf_coreSystem_setNetworkProxy(double csys, const char* proxy);
///->string : 
dllx const char* lkf_coreSystem_getNetworkProxy(double csys);
///->number : 
dllx double lkf_coreSystem_setNetworkTimeout(double csys, double timeout);
///->number : 
dllx double lkf_coreSystem_getNetworkTimeout(double csys);
///->number : 
dllx double lkf_coreSystem_createSound(double csys, const char* name, double mode);
///->number : 
dllx double lkf_coreSystem_createChannelGroup(double csys, const char* name);
///->number : 
dllx double lkf_coreSystem_getMasterChannelGroup(double csys);
///->number : 
dllx double lkf_coreSystem_playSound(double csys, double csnd, double cgrp, double paused);
///->number : 
dllx double lkf_coreSystem_createDSPByType(double csys, double type);

// [Core API]: FMOD::Sound, see libkotfmod_CoreSound.cpp

///->number : 
dllx double lkf_coreSound_exists(double csnd);
///->number : 
dllx double lkf_coreSound_setDefaults(double csnd, double freq, double pri);
///->number : 
dllx double lkf_coreSound_getDefaults(double csnd, float* retmem);
///->number : 
dllx double lkf_coreSound_set3DMinMaxDistance(double csnd, double dmin, double dmax);
///->number : 
dllx double lkf_coreSound_get3DMinMaxDistance(double csnd, float* retmem);
///->number : 
dllx double lkf_coreSound_set3DConeSettings(double csnd, double insideconeangle, double outsideconeangle, double outsidevolume);
///->number : 
dllx double lkf_coreSound_get3DConeSettings(double csnd, float* retmem);

// [Core API]: FMOD::ChannelGroup, see libkotfmod_CoreChannelGroup.cpp

///->number : 
dllx double lkf_coreChannelGroup_exists(double cchg);
///->number : 
dllx double lkf_coreChannelGroup_stop(double cc);
///->number : 
dllx double lkf_coreChannelGroup_setPaused(double cc, double paused);
///->number : 
dllx double lkf_coreChannelGroup_getPaused(double cc);
///->number : 
dllx double lkf_coreChannelGroup_setVolume(double cc, double volume);
///->number : 
dllx double lkf_coreChannelGroup_getVolume(double cc);
///->number : 
dllx double lkf_coreChannelGroup_setVolumeRamp(double cc, double ramp);
///->number : 
dllx double lkf_coreChannelGroup_getVolumeRamp(double cc);
///->number : 
dllx double lkf_coreChannelGroup_getAudibility(double cc);
///->number : 
dllx double lkf_coreChannelGroup_setPitch(double cc, double pitch);
///->number : 
dllx double lkf_coreChannelGroup_getPitch(double cc);
///->number : 
dllx double lkf_coreChannelGroup_setMute(double cc, double mute);
///->number : 
dllx double lkf_coreChannelGroup_getMute(double cc);
///->number : 
dllx double lkf_coreChannelGroup_setReverbProperties(double cc, double instance, double wet);
///->number : 
dllx double lkf_coreChannelGroup_getReverbProperties(double cc, double instance);
///->number : 
dllx double lkf_coreChannelGroup_setLowPassGain(double cc, double gain);
///->number : 
dllx double lkf_coreChannelGroup_getLowPassGain(double cc);
///->number : 
dllx double lkf_coreChannelGroup_setMode(double cc, double mode);
///->number : 
dllx double lkf_coreChannelGroup_getMode(double cc);
///->number : 
dllx double lkf_coreChannelGroup_isPlaying(double cc);
///->number : 
dllx double lkf_coreChannelGroup_setPan(double cc, double pan);
///->number : 
dllx double lkf_coreChannelGroup_setMixLevelsOutput(double cc, double frontleft, double frontright, double center, double lfe, double surroundleft, double surroundright, double backleft, double backright);
///->number : 
dllx double lkf_coreChannelGroup_getDSPClock(double cc, unsigned long long* retmem);
///->number : 
dllx double lkf_coreChannelGroup_setDelay(double cc, double clock_start, double clock_end, double stopchan);
///->number : 
dllx double lkf_coreChannelGroup_getDelay(double cc, unsigned long long* retmem);
///->number : 
dllx double lkf_coreChannelGroup_addFadePoint(double cc, double clock, double volume);
///->number : 
dllx double lkf_coreChannelGroup_setFadePointRamp(double cc, double clock, double volume);
///->number : 
dllx double lkf_coreChannelGroup_removeFadePoints(double cc, double clock_start, double clock_end);
///->number : 
dllx double lkf_coreChannelGroup_getSystemObject(double cc);
///->number : 
dllx double lkf_coreChannelGroup_set3DAttributes(double cc, const FMOD_VECTOR* vecs);
///->number : 
dllx double lkf_coreChannelGroup_get3DAttributes(double cc, FMOD_VECTOR* retmem);
///->number : 
dllx double lkf_coreChannelGroup_set3DMinMaxDistance(double cc, double dmin, double dmax);
///->number : 
dllx double lkf_coreChannelGroup_get3DMinMaxDistance(double cc, float* retmem);
///->number : 
dllx double lkf_coreChannelGroup_set3DConeSettings(double cc, double insideconeangle, double outsideconeangle, double outsidevolume);
///->number : 
dllx double lkf_coreChannelGroup_get3DConeSettings(double cc, float* retmem);
///->number : 
dllx double lkf_coreChannelGroup_set3DConeOrientation(double cc, FMOD_VECTOR* vec);
///->number : 
dllx double lkf_coreChannelGroup_set3DOcclusion(double cc, double directocclusion, double reverbocclusion);
///->number : 
dllx double lkf_coreChannelGroup_get3DOcclusion(double cc, float* retmem);
///->number : 
dllx double lkf_coreChannelGroup_set3DSpread(double cc, double angle);
///->number : 
dllx double lkf_coreChannelGroup_get3DSpread(double cc);
///->number : 
dllx double lkf_coreChannelGroup_set3DLevel(double cc, double level);
///->number : 
dllx double lkf_coreChannelGroup_get3DLevel(double cc);
///->number : 
dllx double lkf_coreChannelGroup_set3DDopplerLevel(double cc, double level);
///->number : 
dllx double lkf_coreChannelGroup_get3DDopplerLevel(double cc);
///->number : 
dllx double lkf_coreChannelGroup_set3DDistanceFilter(double cc, double custom, double customLevel, double centerFreq);
///->number : 
dllx double lkf_coreChannelGroup_get3DDistanceFilter(double cc, float* retmem);
///->number : 
dllx double lkf_coreChannelGroup_release(double cc);
///->string : 
dllx const char* lkf_coreChannelGroup_getName(double cc);
///->number : 
dllx double lkf_coreChannelGroup_getNumChannels(double cc);
///->number : 
dllx double lkf_coreChannelGroup_getChannel(double cc, double index);
///->number : 
dllx double lkf_coreChannelGroup_getNumGroups(double cc);
///->number : 
dllx double lkf_coreChannelGroup_getGroup(double cc, double index);
///->number : 
dllx double lkf_coreChannelGroup_getParentGroup(double cc);
///->number : 
dllx double lkf_coreChannelGroup_getDSP(double cc, double index);
///->number : 
dllx double lkf_coreChannelGroup_addDSP(double cc, double index, double cdsp);
///->number : 
dllx double lkf_coreChannelGroup_removeDSP(double cc, double cdsp);
///->number : 
dllx double lkf_coreChannelGroup_getNumDSPs(double cc);
///->number : 
dllx double lkf_coreChannelGroup_setDSPIndex(double cc, double cdsp, double index);
///->number : 
dllx double lkf_coreChannelGroup_getDSPIndex(double cc, double cdsp);

// [Core API]: FMOD::Channel, see libkotfmod_CoreChannel.cpp

///->number : 
dllx double lkf_coreChannel_exists(double cchn);
///->number : 
dllx double lkf_coreChannel_stop(double cc);
///->number : 
dllx double lkf_coreChannel_setPaused(double cc, double paused);
///->number : 
dllx double lkf_coreChannel_getPaused(double cc);
///->number : 
dllx double lkf_coreChannel_setVolume(double cc, double volume);
///->number : 
dllx double lkf_coreChannel_getVolume(double cc);
///->number : 
dllx double lkf_coreChannel_setVolumeRamp(double cc, double ramp);
///->number : 
dllx double lkf_coreChannel_getVolumeRamp(double cc);
///->number : 
dllx double lkf_coreChannel_getAudibility(double cc);
///->number : 
dllx double lkf_coreChannel_setPitch(double cc, double pitch);
///->number : 
dllx double lkf_coreChannel_getPitch(double cc);
///->number : 
dllx double lkf_coreChannel_setMute(double cc, double mute);
///->number : 
dllx double lkf_coreChannel_getMute(double cc);
///->number : 
dllx double lkf_coreChannel_setReverbProperties(double cc, double instance, double wet);
///->number : 
dllx double lkf_coreChannel_getReverbProperties(double cc, double instance);
///->number : 
dllx double lkf_coreChannel_setLowPassGain(double cc, double gain);
///->number : 
dllx double lkf_coreChannel_getLowPassGain(double cc);
///->number : 
dllx double lkf_coreChannel_setMode(double cc, double mode);
///->number : 
dllx double lkf_coreChannel_getMode(double cc);
///->number : 
dllx double lkf_coreChannel_isPlaying(double cc);
///->number : 
dllx double lkf_coreChannel_setPan(double cc, double pan);
///->number : 
dllx double lkf_coreChannel_setMixLevelsOutput(double cc, double frontleft, double frontright, double center, double lfe, double surroundleft, double surroundright, double backleft, double backright);
///->number : 
dllx double lkf_coreChannel_getDSPClock(double cc, unsigned long long* retmem);
///->number : 
dllx double lkf_coreChannel_setDelay(double cc, double clock_start, double clock_end, double stopchan);
///->number : 
dllx double lkf_coreChannel_getDelay(double cc, unsigned long long* retmem);
///->number : 
dllx double lkf_coreChannel_addFadePoint(double cc, double clock, double volume);
///->number : 
dllx double lkf_coreChannel_setFadePointRamp(double cc, double clock, double volume);
///->number : 
dllx double lkf_coreChannel_removeFadePoints(double cc, double clock_start, double clock_end);
///->number : 
dllx double lkf_coreChannel_getSystemObject(double cc);
///->number : 
dllx double lkf_coreChannel_set3DAttributes(double cc, const FMOD_VECTOR* vecs);
///->number : 
dllx double lkf_coreChannel_get3DAttributes(double cc, FMOD_VECTOR* retmem);
///->number : 
dllx double lkf_coreChannel_set3DMinMaxDistance(double cc, double dmin, double dmax);
///->number : 
dllx double lkf_coreChannel_get3DMinMaxDistance(double cc, float* retmem);
///->number : 
dllx double lkf_coreChannel_set3DConeSettings(double cc, double insideconeangle, double outsideconeangle, double outsidevolume);
///->number : 
dllx double lkf_coreChannel_get3DConeSettings(double cc, float* retmem);
///->number : 
dllx double lkf_coreChannel_set3DConeOrientation(double cc, FMOD_VECTOR* vec);
///->number : 
dllx double lkf_coreChannel_set3DOcclusion(double cc, double directocclusion, double reverbocclusion);
///->number : 
dllx double lkf_coreChannel_get3DOcclusion(double cc, float* retmem);
///->number : 
dllx double lkf_coreChannel_set3DSpread(double cc, double angle);
///->number : 
dllx double lkf_coreChannel_get3DSpread(double cc);
///->number : 
dllx double lkf_coreChannel_set3DLevel(double cc, double level);
///->number : 
dllx double lkf_coreChannel_get3DLevel(double cc);
///->number : 
dllx double lkf_coreChannel_set3DDopplerLevel(double cc, double level);
///->number : 
dllx double lkf_coreChannel_get3DDopplerLevel(double cc);
///->number : 
dllx double lkf_coreChannel_set3DDistanceFilter(double cc, double custom, double customLevel, double centerFreq);
///->number : 
dllx double lkf_coreChannel_get3DDistanceFilter(double cc, float* retmem);
///->number : 
dllx double lkf_coreChannel_getDSP(double cc, double index);
///->number : 
dllx double lkf_coreChannel_addDSP(double cc, double index, double cdsp);
///->number : 
dllx double lkf_coreChannel_removeDSP(double cc, double cdsp);
///->number : 
dllx double lkf_coreChannel_getNumDSPs(double cc);
///->number : 
dllx double lkf_coreChannel_setDSPIndex(double cc, double cdsp, double index);
///->number : 
dllx double lkf_coreChannel_getDSPIndex(double cc, double cdsp);



// [Core API]: FMOD::DSP, see libkotfmod_CoreDSP.cpp

///->number : 
dllx double lkf_coreDSP_exists(double cdsp);
///->number : 
dllx double lkf_coreDSP_release(double cdsp);
///->number : 
dllx double lkf_coreDSP_getSystemObject(double cdsp);
///->number : 
dllx double lkf_coreDSP_setActive(double cdsp, double active);
///->number : 
dllx double lkf_coreDSP_getActive(double cdsp);
///->number : 
dllx double lkf_coreDSP_setBypass(double cdsp, double bypass);
///->number : 
dllx double lkf_coreDSP_getBypass(double cdsp);
///->number : 
dllx double lkf_coreDSP_setWetDryMix(double cdsp, double prewet, double postwet, double dry);
///->number : 
dllx double lkf_coreDSP_getWetDryMix(double cdsp, float* retmem);
///->number : 
dllx double lkf_coreDSP_reset(double cdsp);
///->number : 
dllx double lkf_coreDSP_setParameterFloat(double cdsp, double index, double value);
///->number : 
dllx double lkf_coreDSP_setParameterInt(double cdsp, double index, double value);
///->number : 
dllx double lkf_coreDSP_setParameterBool(double cdsp, double index, double value);
///->number : 
dllx double lkf_coreDSP_setParameterData(double cdsp, double index, const char* value, double length);
///->number : 
dllx double lkf_coreDSP_getType(double cdsp);
///->number : 
dllx double lkf_coreDSP_getIdle(double cdsp);
