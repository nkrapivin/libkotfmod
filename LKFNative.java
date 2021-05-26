package com.nkrapivindev.libkotfmod;

// add your imports here...
import java.nio.ByteBuffer;
import java.lang.String;

public class LKFNative {
	public LKFNative() {
		System.loadLibrary("your-library-here");
	}

	public native double lkf_internal_init();
	public native double lkf_internal_final();
	public native double lkf_is_present();
	public native String RegisterCallbacks(ByteBuffer please, ByteBuffer dont, ByteBuffer call, ByteBuffer it);
	public native double lkf_are_callbacks_registered();
	public native String lkf_enum_result_reflection(double value);
	public native String lkf_enum_event_instance_callback_reflection(double value);
	public native String lkf_enum_system_callback_reflection(double value);
	public native double lkf_get_api_version();
	public native double lkf_system_create();
	public native double lkf_system_update(double system);
	public native double lkf_system_exists(double system);
	public native double lkf_system_initialize(double system, double maxchannels, double studioflags, double flags);
	public native double lkf_system_loadBankFile(double system, String filename, double flags);
	public native double lkf_system_getEvent(double system, String path);
	public native double lkf_system_unloadAll(double system);
	public native double lkf_system_setListenerAttributes(double system, double listener, ByteBuffer attributes, ByteBuffer attenuationposition);
	public native double lkf_system_release(double system);
	public native double lkf_system_flushCommands(double system);
	public native double lkf_system_flushSampleLoading(double system);
	public native double lkf_system_getCPUUsage(double system, ByteBuffer retmem);
	public native double lkf_system_getMemoryUsage(double system, ByteBuffer memoryusage);
	public native double lkf_system_getCoreSystem(double system);
	public native double lkf_bank_exists(double bank);
	public native double lkf_bank_unload(double bank);
	public native double lkf_bank_loadSampleData(double bank);
	public native double lkf_bank_unloadSampleData(double bank);
	public native double lkf_bank_getLoadingState(double bank);
	public native double lkf_bank_getSampleLoadingState(double bank);
	public native double lkf_eventDescription_exists(double evdesc);
	public native double lkf_eventDescription_createInstance(double evdesc);
	public native double lkf_eventDescription_loadSampleData(double evdesc);
	public native double lkf_eventDescription_unloadSampleData(double evdesc);
	public native double lkf_eventDescription_releaseAllInstances(double evdesc);
	public native double lkf_eventDescription_getSampleLoadingState(double evdesc);
	public native double lkf_eventDescription_isSnapshot(double evdesc);
	public native double lkf_eventDescription_isOneshot(double evdesc);
	public native double lkf_eventDescription_isStream(double evdesc);
	public native double lkf_eventDescription_is3D(double evdesc);
	public native double lkf_eventDescription_isDopplerEnabled(double evdesc);
	public native double lkf_eventDescription_hasCue(double evdesc);
	public native double lkf_eventInstance_exists(double evinst);
	public native double lkf_eventInstance_start(double evinst);
	public native double lkf_eventInstance_stop(double evinst, double stopmode);
	public native double lkf_eventInstance_setParameterByName(double evinst, String name, double value, double ignoreseekspeed);
	public native double lkf_eventInstance_getParameterByName(double evinst, String name, ByteBuffer retmem);
	public native double lkf_eventInstance_set3DAttributes(double evinst, ByteBuffer attributes);
	public native double lkf_eventInstance_get3DAttributes(double evinst, ByteBuffer retattr);
	public native double lkf_eventInstance_setVolume(double evinst, double volume);
	public native double lkf_eventInstance_getVolume(double evinst, ByteBuffer retmem);
	public native double lkf_eventInstance_setPitch(double evinst, double pitch);
	public native double lkf_eventInstance_getPitch(double evinst, ByteBuffer retmem);
	public native double lkf_eventInstance_release(double evinst);
	public native double lkf_eventInstance_triggerCue(double evinst);
	public native double lkf_eventInstance_getPaused(double evinst);
	public native double lkf_eventInstance_setPaused(double evinst, double paused);
	public native double lkf_eventInstance_setReverbLevel(double evinst, double index, double level);
	public native double lkf_eventInstance_getReverbLevel(double evinst, double index);
	public native double lkf_eventInstance_setTimelinePosition(double evinst, double position);
	public native double lkf_eventInstance_getTimelinePosition(double evinst);
	public native double lkf_eventInstance_setListenerMask(double evinst, double mask);
	public native double lkf_eventInstance_getListenerMask(double evinst);
	public native double lkf_eventInstance_getDescription(double evinst);
	public native double lkf_eventInstance_isVirtual(double evinst);
	public native double lkf_coreSystem_exists(double csys);
	public native double lkf_coreSystem_setSoftwareFormat(double csys, double samplerate, double speakermode, double numrawspeakers);
	public native double lkf_coreSystem_create();
	public native double lkf_coreSystem_init(double csys, double maxchannels, double initflags);
	public native double lkf_coreSystem_update(double csys);
	public native double lkf_coreSystem_close(double csys);
	public native double lkf_coreSystem_release(double csys);
	public native double lkf_coreSystem_setOutput(double csys, double output);
	public native double lkf_coreSystem_getOutput(double csys);
	public native double lkf_coreSystem_setSoftwareChannels(double csys, double numsoftwarechannels);
	public native double lkf_coreSystem_getSoftwareChannels(double csys);
	public native double lkf_coreSystem_getSoftwareFormat(double csys, ByteBuffer retmem);
	public native double lkf_coreSystem_setDSPBufferSize(double csys, double bufferlen, double numbuffers);
	public native double lkf_coreSystem_getDSPBufferSize(double csys, ByteBuffer retmem);
	public native double lkf_coreSystem_setPluginPath(double csys, String path);
	public native double lkf_coreSystem_loadPlugin(double csys, String name, double priority);
	public native double lkf_coreSystem_unloadPlugin(double csys, double handle);
	public native double lkf_coreSystem_setOutputByPlugin(double csys, double handle);
	public native double lkf_coreSystem_getOutputByPlugin(double csys);
	public native double lkf_coreSystem_setSpeakerPosition(double csys, double speaker, double x, double y, double active);
	public native double lkf_coreSystem_getSpeakerPosition(double csys, double speaker, ByteBuffer retmem);
	public native double lkf_coreSystem_setStreamBufferSize(double csys, double filebuffersize, double filebuffersizetype);
	public native double lkf_coreSystem_getStreamBufferSize(double csys, ByteBuffer retmem);
	public native double lkf_coreSystem_set3DSettings(double csys, double dopplerscale, double distancefactor, double rolloffscale);
	public native double lkf_coreSystem_get3DSettings(double csys, ByteBuffer retmem);
	public native double lkf_coreSystem_set3DNumListeners(double csys, double num);
	public native double lkf_coreSystem_get3DNumListeners(double csys);
	public native double lkf_coreSystem_set3DListenerAttributes(double csys, double listener, ByteBuffer vecs);
	public native double lkf_coreSystem_get3DListenerAttributes(double csys, double listener, ByteBuffer retmem);
	public native double lkf_coreSystem_mixerSuspend(double csys);
	public native double lkf_coreSystem_mixerResume(double csys);
	public native double lkf_coreSystem_getVersion(double csys);
	public native double lkf_coreSystem_getOutputHandle(double csys);
	public native double lkf_coreSystem_getChannelsPlaying(double csys, ByteBuffer retmem);
	public native double lkf_coreSystem_getCPUUsage(double csys, ByteBuffer retmem);
	public native double lkf_coreSystem_getCPUUsageEx(double csys, ByteBuffer retmem);
	public native double lkf_coreSystem_getFileUsage(double csys, ByteBuffer retmem);
	public native double lkf_coreSystem_lockDSP(double csys);
	public native double lkf_coreSystem_unlockDSP(double csys);
	public native double lkf_coreSystem_setNetworkProxy(double csys, String proxy);
	public native String lkf_coreSystem_getNetworkProxy(double csys);
	public native double lkf_coreSystem_setNetworkTimeout(double csys, double timeout);
	public native double lkf_coreSystem_getNetworkTimeout(double csys);
	public native double lkf_coreSystem_createSound(double csys, String name, double mode);
	public native double lkf_coreSystem_createChannelGroup(double csys, String name);
	public native double lkf_coreSystem_getMasterChannelGroup(double csys);
	public native double lkf_coreSystem_playSound(double csys, double csnd, double cgrp, double paused);
	public native double lkf_coreSystem_createDSPByType(double csys, double type);
	public native double lkf_coreSound_exists(double csnd);
	public native double lkf_coreSound_setDefaults(double csnd, double freq, double pri);
	public native double lkf_coreSound_getDefaults(double csnd, ByteBuffer retmem);
	public native double lkf_coreSound_set3DMinMaxDistance(double csnd, double dmin, double dmax);
	public native double lkf_coreSound_get3DMinMaxDistance(double csnd, ByteBuffer retmem);
	public native double lkf_coreSound_set3DConeSettings(double csnd, double insideconeangle, double outsideconeangle, double outsidevolume);
	public native double lkf_coreSound_get3DConeSettings(double csnd, ByteBuffer retmem);
	public native double lkf_coreChannelGroup_exists(double cchg);
	public native double lkf_coreChannelGroup_stop(double cc);
	public native double lkf_coreChannelGroup_setPaused(double cc, double paused);
	public native double lkf_coreChannelGroup_getPaused(double cc);
	public native double lkf_coreChannelGroup_setVolume(double cc, double volume);
	public native double lkf_coreChannelGroup_getVolume(double cc);
	public native double lkf_coreChannelGroup_setVolumeRamp(double cc, double ramp);
	public native double lkf_coreChannelGroup_getVolumeRamp(double cc);
	public native double lkf_coreChannelGroup_getAudibility(double cc);
	public native double lkf_coreChannelGroup_setPitch(double cc, double pitch);
	public native double lkf_coreChannelGroup_getPitch(double cc);
	public native double lkf_coreChannelGroup_setMute(double cc, double mute);
	public native double lkf_coreChannelGroup_getMute(double cc);
	public native double lkf_coreChannelGroup_setReverbProperties(double cc, double instance, double wet);
	public native double lkf_coreChannelGroup_getReverbProperties(double cc, double instance);
	public native double lkf_coreChannelGroup_setLowPassGain(double cc, double gain);
	public native double lkf_coreChannelGroup_getLowPassGain(double cc);
	public native double lkf_coreChannelGroup_setMode(double cc, double mode);
	public native double lkf_coreChannelGroup_getMode(double cc);
	public native double lkf_coreChannelGroup_isPlaying(double cc);
	public native double lkf_coreChannelGroup_setPan(double cc, double pan);
	public native double lkf_coreChannelGroup_setMixLevelsOutput(double cc, double frontleft, double frontright, double center, double lfe, double surroundleft, double surroundright, double backleft, double backright);
	public native double lkf_coreChannelGroup_getDSPClock(double cc, ByteBuffer retmem);
	public native double lkf_coreChannelGroup_setDelay(double cc, double clock_start, double clock_end, double stopchan);
	public native double lkf_coreChannelGroup_getDelay(double cc, ByteBuffer retmem);
	public native double lkf_coreChannelGroup_addFadePoint(double cc, double clock, double volume);
	public native double lkf_coreChannelGroup_setFadePointRamp(double cc, double clock, double volume);
	public native double lkf_coreChannelGroup_removeFadePoints(double cc, double clock_start, double clock_end);
	public native double lkf_coreChannelGroup_getSystemObject(double cc);
	public native double lkf_coreChannelGroup_set3DAttributes(double cc, ByteBuffer vecs);
	public native double lkf_coreChannelGroup_get3DAttributes(double cc, ByteBuffer retmem);
	public native double lkf_coreChannelGroup_set3DMinMaxDistance(double cc, double dmin, double dmax);
	public native double lkf_coreChannelGroup_get3DMinMaxDistance(double cc, ByteBuffer retmem);
	public native double lkf_coreChannelGroup_set3DConeSettings(double cc, double insideconeangle, double outsideconeangle, double outsidevolume);
	public native double lkf_coreChannelGroup_get3DConeSettings(double cc, ByteBuffer retmem);
	public native double lkf_coreChannelGroup_set3DConeOrientation(double cc, ByteBuffer vec);
	public native double lkf_coreChannelGroup_set3DOcclusion(double cc, double directocclusion, double reverbocclusion);
	public native double lkf_coreChannelGroup_get3DOcclusion(double cc, ByteBuffer retmem);
	public native double lkf_coreChannelGroup_set3DSpread(double cc, double angle);
	public native double lkf_coreChannelGroup_get3DSpread(double cc);
	public native double lkf_coreChannelGroup_set3DLevel(double cc, double level);
	public native double lkf_coreChannelGroup_get3DLevel(double cc);
	public native double lkf_coreChannelGroup_set3DDopplerLevel(double cc, double level);
	public native double lkf_coreChannelGroup_get3DDopplerLevel(double cc);
	public native double lkf_coreChannelGroup_set3DDistanceFilter(double cc, double custom, double customLevel, double centerFreq);
	public native double lkf_coreChannelGroup_get3DDistanceFilter(double cc, ByteBuffer retmem);
	public native double lkf_coreChannelGroup_release(double cc);
	public native String lkf_coreChannelGroup_getName(double cc);
	public native double lkf_coreChannelGroup_getNumChannels(double cc);
	public native double lkf_coreChannelGroup_getChannel(double cc, double index);
	public native double lkf_coreChannelGroup_getNumGroups(double cc);
	public native double lkf_coreChannelGroup_getGroup(double cc, double index);
	public native double lkf_coreChannelGroup_getParentGroup(double cc);
	public native double lkf_coreChannelGroup_getDSP(double cc, double index);
	public native double lkf_coreChannelGroup_addDSP(double cc, double index, double cdsp);
	public native double lkf_coreChannelGroup_removeDSP(double cc, double cdsp);
	public native double lkf_coreChannelGroup_getNumDSPs(double cc);
	public native double lkf_coreChannelGroup_setDSPIndex(double cc, double cdsp, double index);
	public native double lkf_coreChannelGroup_getDSPIndex(double cc, double cdsp);
	public native double lkf_coreChannel_exists(double cchn);
	public native double lkf_coreChannel_stop(double cc);
	public native double lkf_coreChannel_setPaused(double cc, double paused);
	public native double lkf_coreChannel_getPaused(double cc);
	public native double lkf_coreChannel_setVolume(double cc, double volume);
	public native double lkf_coreChannel_getVolume(double cc);
	public native double lkf_coreChannel_setVolumeRamp(double cc, double ramp);
	public native double lkf_coreChannel_getVolumeRamp(double cc);
	public native double lkf_coreChannel_getAudibility(double cc);
	public native double lkf_coreChannel_setPitch(double cc, double pitch);
	public native double lkf_coreChannel_getPitch(double cc);
	public native double lkf_coreChannel_setMute(double cc, double mute);
	public native double lkf_coreChannel_getMute(double cc);
	public native double lkf_coreChannel_setReverbProperties(double cc, double instance, double wet);
	public native double lkf_coreChannel_getReverbProperties(double cc, double instance);
	public native double lkf_coreChannel_setLowPassGain(double cc, double gain);
	public native double lkf_coreChannel_getLowPassGain(double cc);
	public native double lkf_coreChannel_setMode(double cc, double mode);
	public native double lkf_coreChannel_getMode(double cc);
	public native double lkf_coreChannel_isPlaying(double cc);
	public native double lkf_coreChannel_setPan(double cc, double pan);
	public native double lkf_coreChannel_setMixLevelsOutput(double cc, double frontleft, double frontright, double center, double lfe, double surroundleft, double surroundright, double backleft, double backright);
	public native double lkf_coreChannel_getDSPClock(double cc, ByteBuffer retmem);
	public native double lkf_coreChannel_setDelay(double cc, double clock_start, double clock_end, double stopchan);
	public native double lkf_coreChannel_getDelay(double cc, ByteBuffer retmem);
	public native double lkf_coreChannel_addFadePoint(double cc, double clock, double volume);
	public native double lkf_coreChannel_setFadePointRamp(double cc, double clock, double volume);
	public native double lkf_coreChannel_removeFadePoints(double cc, double clock_start, double clock_end);
	public native double lkf_coreChannel_getSystemObject(double cc);
	public native double lkf_coreChannel_set3DAttributes(double cc, ByteBuffer vecs);
	public native double lkf_coreChannel_get3DAttributes(double cc, ByteBuffer retmem);
	public native double lkf_coreChannel_set3DMinMaxDistance(double cc, double dmin, double dmax);
	public native double lkf_coreChannel_get3DMinMaxDistance(double cc, ByteBuffer retmem);
	public native double lkf_coreChannel_set3DConeSettings(double cc, double insideconeangle, double outsideconeangle, double outsidevolume);
	public native double lkf_coreChannel_get3DConeSettings(double cc, ByteBuffer retmem);
	public native double lkf_coreChannel_set3DConeOrientation(double cc, ByteBuffer vec);
	public native double lkf_coreChannel_set3DOcclusion(double cc, double directocclusion, double reverbocclusion);
	public native double lkf_coreChannel_get3DOcclusion(double cc, ByteBuffer retmem);
	public native double lkf_coreChannel_set3DSpread(double cc, double angle);
	public native double lkf_coreChannel_get3DSpread(double cc);
	public native double lkf_coreChannel_set3DLevel(double cc, double level);
	public native double lkf_coreChannel_get3DLevel(double cc);
	public native double lkf_coreChannel_set3DDopplerLevel(double cc, double level);
	public native double lkf_coreChannel_get3DDopplerLevel(double cc);
	public native double lkf_coreChannel_set3DDistanceFilter(double cc, double custom, double customLevel, double centerFreq);
	public native double lkf_coreChannel_get3DDistanceFilter(double cc, ByteBuffer retmem);
	public native double lkf_coreChannel_getDSP(double cc, double index);
	public native double lkf_coreChannel_addDSP(double cc, double index, double cdsp);
	public native double lkf_coreChannel_removeDSP(double cc, double cdsp);
	public native double lkf_coreChannel_getNumDSPs(double cc);
	public native double lkf_coreChannel_setDSPIndex(double cc, double cdsp, double index);
	public native double lkf_coreChannel_getDSPIndex(double cc, double cdsp);
	public native double lkf_coreDSP_exists(double cdsp);
	public native double lkf_coreDSP_release(double cdsp);
	public native double lkf_coreDSP_getSystemObject(double cdsp);
	public native double lkf_coreDSP_setActive(double cdsp, double active);
	public native double lkf_coreDSP_getActive(double cdsp);
	public native double lkf_coreDSP_setBypass(double cdsp, double bypass);
	public native double lkf_coreDSP_getBypass(double cdsp);
	public native double lkf_coreDSP_setWetDryMix(double cdsp, double prewet, double postwet, double dry);
	public native double lkf_coreDSP_getWetDryMix(double cdsp, ByteBuffer retmem);
	public native double lkf_coreDSP_reset(double cdsp);
	public native double lkf_coreDSP_setParameterFloat(double cdsp, double index, double value);
	public native double lkf_coreDSP_setParameterInt(double cdsp, double index, double value);
	public native double lkf_coreDSP_setParameterBool(double cdsp, double index, double value);
	public native double lkf_coreDSP_setParameterData(double cdsp, double index, String value, double length);
	public native double lkf_coreDSP_getType(double cdsp);
	public native double lkf_coreDSP_getIdle(double cdsp);
} // LKFNative