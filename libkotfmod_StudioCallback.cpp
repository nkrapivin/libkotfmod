// libkotfmod_StudioCallback.cpp: FMOD Studio API callback provided by libkotfmod which wraps stuff into GML.
#include "libkotfmod.h"

FMOD_RESULT F_CALLBACK lkf_studio_system_callback(FMOD_STUDIO_SYSTEM* system, FMOD_STUDIO_SYSTEM_CALLBACK_TYPE type, void* commanddata, void* userdata) {
	std::size_t systemIndex{ lkf_T_indexOf(Global::Systems, reinterpret_cast<FMOD::Studio::System*>(system)) };

	// what the hell?
	if (systemIndex == SIZE_MAX) {
		return FMOD_ERR_INVALID_HANDLE;
	}

	// ignore the spammy types.
	if (type == FMOD_STUDIO_SYSTEM_CALLBACK_PREUPDATE || type == FMOD_STUDIO_SYSTEM_CALLBACK_POSTUPDATE)
		return FMOD_OK;

	int cmap{ CreateDsMap(0) };

	DsMapAddS(cmap, "event_type", "lkf_studio_system_callback");
	DsMapAddD(cmap, "lkf_type", static_cast<double>(type));
	DsMapAddD(cmap, "lkf_systemIndex", static_cast<double>(systemIndex));

	switch (type) {
		default: {
			DsMapAddD(cmap, "lkf_parametersDsMap", -1.0);
			break;
		}

		case FMOD_STUDIO_SYSTEM_CALLBACK_BANK_UNLOAD: {
			int pmap{ CreateDsMap(0) };
			auto bnk{ reinterpret_cast<FMOD::Studio::Bank*>(commanddata) };
			DsMapAddD(cmap, "lkf_parametersDsMap", pmap);
			DsMapAddD(pmap, "bank",
				static_cast<double>(lkf_T_indexOf(Global::Banks, bnk))
			);
			break;
		}
	}

	CreateAsynEventWithDSMap(cmap, ev_audio_playback);
	return FMOD_OK;
}

FMOD_RESULT F_CALLBACK lkf_studio_event_callback(FMOD_STUDIO_EVENT_CALLBACK_TYPE type, FMOD_STUDIO_EVENTINSTANCE* event, void* parameters) {
	std::size_t eventIndex{ lkf_T_indexOf(Global::EventInstances, reinterpret_cast<FMOD::Studio::EventInstance*>(event)) };

	// what the hell?
	if (eventIndex == SIZE_MAX) {
		LKF_TRACE("Wtf? Invalid index passed to a callback!");
		return FMOD_ERR_INVALID_HANDLE;
	}

	int cmap{ CreateDsMap(0) };

	DsMapAddS(cmap, "event_type", "lkf_studio_event_callback");
	DsMapAddD(cmap, "lkf_type", static_cast<double>(type));
	DsMapAddD(cmap, "lkf_eventInstanceIndex", static_cast<double>(eventIndex));

	switch (type) {
		// unused.
		default: {
			DsMapAddD(cmap, "lkf_parametersDsMap", -1.0);
			break;
		}

		case FMOD_STUDIO_EVENT_CALLBACK_DESTROYED: {
			LKF_TRACE("Event instance is about to be destroyed [%zu].", eventIndex);
			DsMapAddD(cmap, "lkf_parametersDsMap", -1.0);
			lkf_T_pop_back_smart(Global::EventInstances, eventIndex, Global::EventInstanceLast);
			// On the GML side the index will be invalid, and it has to finish off the job.
			break;
		}

		case FMOD_STUDIO_EVENT_CALLBACK_START_EVENT_COMMAND: {
			int pmap{ CreateDsMap(0) };
			auto evv{ reinterpret_cast<FMOD::Studio::EventInstance*>(parameters) };
			DsMapAddD(cmap, "lkf_parametersDsMap", pmap);
			DsMapAddD(pmap, "eventInstance",
				// push_back_smart will try to reuse indexes whenever possible.
				static_cast<double>(lkf_T_push_back_smart(Global::EventInstances, evv, Global::EventInstanceLast))
			);
			break;
		}
	}

	CreateAsynEventWithDSMap(cmap, ev_audio_playback);
	return FMOD_OK;
}
