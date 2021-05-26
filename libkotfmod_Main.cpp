// libkotfmod.cpp: Contains implementations of global variables and some misc. functions.
#include "libkotfmod.h"

// [Studio API]
std::size_t Global::SystemLast{ 0 };
std::size_t Global::BankLast{ 0 };
std::size_t Global::EventDescriptionLast{ 0 };
std::size_t Global::EventInstanceLast{ 0 };
std::unordered_map<std::size_t, FMOD::Studio::System*> Global::Systems{ };
std::unordered_map<std::size_t, FMOD::Studio::Bank*> Global::Banks{ };
std::unordered_map<std::size_t, FMOD::Studio::EventDescription*> Global::EventDescriptions{ };
std::unordered_map<std::size_t, FMOD::Studio::EventInstance*> Global::EventInstances{ };

// [Core API]
std::size_t Global::CoreSystemLast{ 0 };
std::size_t Global::CoreSoundLast{ 0 };
std::size_t Global::CoreChannelGroupLast{ 0 };
std::size_t Global::CoreChannelLast{ 0 };
std::size_t Global::CoreDSPLast{ 0 };
std::unordered_map<std::size_t, FMOD::System*> Global::CoreSystems{ };
std::unordered_map<std::size_t, FMOD::Sound*> Global::CoreSounds{ };
std::unordered_map<std::size_t, FMOD::ChannelGroup*> Global::CoreChannelGroups{ };
std::unordered_map<std::size_t, FMOD::Channel*> Global::CoreChannels{ };
std::unordered_map<std::size_t, FMOD::DSP*> Global::DSPs{ };

dllx double lkf_internal_init() {
	LKF_TRACE("Welcome to libkotfmod by nkrapivindev! This version was built on %s %s (Asia/Yekaterinburg UTC+5 time).", __DATE__, __TIME__);
	LKF_TRACE("Made with FMOD Studio by Firelight Technologies Pty Ltd."); // following Firelight's attribution guide....

#ifdef _WIN32
	// Windows must have COM initialized.
	HRESULT hr{ CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED) };
	return SUCCEEDED(hr) ? 1.0 : 0.0;
#else
	return 1.0; // TODO: later.
#endif /* _WIN32 */
}

dllx double lkf_internal_final() {
	LKF_TRACE("Goodbye!");
	// GameMaker will call CoUninitialize for us.
	return 1.0;
}

dllx double lkf_get_api_version() {
	return FMOD_VERSION;
}

dllx double lkf_is_present() {
	return 1.0;
}
