// libkotfmod_CoreCallbacks.cpp: [Core API] Core Callbacks go here.

#include "libkotfmod.h"

FMOD_RESULT F_CALL lkf_coreSystem_callback(FMOD_SYSTEM* system, FMOD_SYSTEM_CALLBACK_TYPE type, void* commanddata1, void* commanddata2, void* userdata) {
	if (system == nullptr) {
		LKF_TRACE("Wtf? Some callback for a NULL coresystem, (type=%d,data1=%p,data2=%p,userdata=%p)", type, commanddata1, commanddata2, userdata);
		return FMOD_OK;
	}

	// ignore the spammy types.
	if (type == FMOD_SYSTEM_CALLBACK_PREUPDATE  ||
		type == FMOD_SYSTEM_CALLBACK_POSTUPDATE ||
		type == FMOD_SYSTEM_CALLBACK_PREMIX     ||
		type == FMOD_SYSTEM_CALLBACK_POSTMIX    ||
		type == FMOD_SYSTEM_CALLBACK_MIDMIX)
		return FMOD_OK;

	std::size_t sysind{ lkf_T_indexOf(Global::CoreSystems, reinterpret_cast<FMOD::System*>(system)) };
	if (sysind == SIZE_MAX) {
		LKF_TRACE("Wtf? Invalid coresystem passed to callback. %p", system);
		return FMOD_ERR_INVALID_HANDLE;
	}

	int cmap{ CreateDsMap(0) };

	DsMapAddS(cmap, "event_type", "lkf_core_system_callback");
	DsMapAddD(cmap, "lkf_type", static_cast<double>(type));
	DsMapAddD(cmap, "lkf_systemIndex", static_cast<double>(sysind));

	switch (type) {
		default: {
			DsMapAddD(cmap, "lkf_parametersDsMap", -1.0);
			break;
		}

		case FMOD_SYSTEM_CALLBACK_DEVICEREINITIALIZE: {
			int pmap{ CreateDsMap(0) };
			DsMapAddD(cmap, "lkf_parametersDsMap", static_cast<double>(pmap));
			DsMapAddD(pmap, "output_type", static_cast<double>(static_cast<FMOD_OUTPUTTYPE>(reinterpret_cast<std::intptr_t>(commanddata1))));
			DsMapAddD(pmap, "driver_index", static_cast<double>(reinterpret_cast<std::intptr_t>(commanddata2)));
			break;
		}

		case FMOD_SYSTEM_CALLBACK_MEMORYALLOCATIONFAILED: {
			int pmap{ CreateDsMap(0) };
			DsMapAddD(cmap, "lkf_parametersDsMap", static_cast<double>(pmap));
			DsMapAddS(pmap, "file", reinterpret_cast<const char*>(const_cast<const void*>(commanddata1)));
			DsMapAddD(pmap, "size", static_cast<double>(reinterpret_cast<std::intptr_t>(commanddata2)));
			break;
		}

		case FMOD_SYSTEM_CALLBACK_ERROR: {
			int pmap{ CreateDsMap(0) };
			DsMapAddD(cmap, "lkf_parametersDsMap", static_cast<double>(pmap));
			FMOD_ERRORCALLBACK_INFO* info{ reinterpret_cast<FMOD_ERRORCALLBACK_INFO*>(commanddata1) };

			DsMapAddD(pmap, "lkf_result", lkf_err_code(info->result));
			DsMapAddD(pmap, "instancetype", info->instancetype);
			DsMapAddD(pmap, "instance", static_cast<double>(reinterpret_cast<std::intptr_t>(info->instance)));
			DsMapAddS(pmap, "functionname", info->functionname);
			DsMapAddS(pmap, "functionparams", info->functionparams);

			LKF_TRACE("Uh oh, there is an error callback from FMOD, something's very wrong. :(");
			break;
		}
	}

	CreateAsynEventWithDSMap(cmap, ev_audio_playback);
	return FMOD_OK;
}

FMOD_RESULT F_CALL lkf_coreChannelControl_callback(FMOD_CHANNELCONTROL* channelcontrol, FMOD_CHANNELCONTROL_TYPE controltype, FMOD_CHANNELCONTROL_CALLBACK_TYPE callbacktype, void* commanddata1, void* commanddata2) {
	if (channelcontrol == nullptr) {
		LKF_TRACE("Wtf? ChannelControl is NULL.");
		return FMOD_OK;
	}

	std::size_t myIndex{ 0 };

	switch (controltype) {
		case FMOD_CHANNELCONTROL_CHANNEL: {
			myIndex = lkf_T_indexOf(Global::CoreChannels, reinterpret_cast<FMOD::Channel*>(channelcontrol));
			break;
		}

		case FMOD_CHANNELCONTROL_CHANNELGROUP: {
			myIndex = lkf_T_indexOf(Global::CoreChannelGroups, reinterpret_cast<FMOD::ChannelGroup*>(channelcontrol));
			break;
		}

		default: {
			LKF_TRACE("Wtf? Invalid channel control type passed to a callback! [%d]", controltype);
			return FMOD_ERR_INVALID_PARAM;
		}
	}

	if (myIndex == SIZE_MAX) {
		LKF_TRACE("Wtf? Unable to resolve channel control!! %p", channelcontrol);
	}

	int cmap{ CreateDsMap(0) };

	DsMapAddS(cmap, "event_type", "lkf_core_channel_control_callback");
	DsMapAddD(cmap, "lkf_type", callbacktype);
	DsMapAddD(cmap, "lkf_controlType", controltype);
	DsMapAddD(cmap, "lkf_controlIndex", static_cast<double>(myIndex));

	switch (callbacktype) {
		case FMOD_CHANNELCONTROL_CALLBACK_END: {
			DsMapAddD(cmap, "lkf_parametersDsMap", -1.0);
			lkf_T_pop_back_smart(Global::CoreChannels, myIndex, Global::CoreChannelLast);
			break;
		}

		case FMOD_CHANNELCONTROL_CALLBACK_VIRTUALVOICE: {
			int pmap{ CreateDsMap(0) };
			DsMapAddD(cmap, "lkf_parametersDsMap", static_cast<double>(pmap));
			DsMapAddD(pmap, "mode", static_cast<double>(reinterpret_cast<std::intptr_t>(commanddata1)));
			break;
		}

		case FMOD_CHANNELCONTROL_CALLBACK_SYNCPOINT: {
			int pmap{ CreateDsMap(0) };
			DsMapAddD(cmap, "lkf_parametersDsMap", static_cast<double>(pmap));
			DsMapAddD(pmap, "syncpoint_index", static_cast<double>(reinterpret_cast<std::intptr_t>(commanddata1)));
			break;
		}

		case FMOD_CHANNELCONTROL_CALLBACK_OCCLUSION: {
			int pmap{ CreateDsMap(0) };
			DsMapAddD(cmap, "lkf_parametersDsMap", static_cast<double>(pmap));
			DsMapAddD(pmap, "direct_occlusion", static_cast<double>(*(reinterpret_cast<float*>(commanddata1))));
			DsMapAddD(pmap, "reverb_occlusion", static_cast<double>(*(reinterpret_cast<float*>(commanddata1))));
			break;
		}

		default: {
			DsMapAddD(cmap, "lkf_parametersDsMap", -1.0);
			break;
		}
	}

	CreateAsynEventWithDSMap(cmap, ev_audio_playback);
	return FMOD_OK;
}

