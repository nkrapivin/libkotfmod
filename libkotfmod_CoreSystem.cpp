// libkotfmod_CoreSystem.cpp: [Core API] System.
#include "libkotfmod.h"

dllx double lkf_coreSystem_exists(double csys) {
	return (
		csys >= 0.0
	&&	std::floor(csys) == csys
	&&	Global::CoreSystems.find(static_cast<std::size_t>(csys)) != Global::CoreSystems.end()
	) ? 1.0 : 0.0;
}

dllx double lkf_coreSystem_setSoftwareFormat(double csys, double samplerate, double speakermode, double numrawspeakers) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{
			coresys->setSoftwareFormat(static_cast<int>(samplerate), static_cast<FMOD_SPEAKERMODE>(speakermode), static_cast<int>(numrawspeakers))
		};

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_create() {
	FMOD::System* csys{ nullptr };
	auto result{ FMOD::System_Create(&csys) };
	if (LKF_OK(result)) {
		csys->setCallback(lkf_coreSystem_callback);
		std::size_t i{ lkf_T_push_back_smart(Global::CoreSystems, csys, Global::CoreSystemLast) };
		return static_cast<double>(i);
	}

	return lkf_err_code(result);
}

dllx double lkf_coreSystem_init(double csys, double maxchannels, double initflags) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->init(static_cast<int>(maxchannels), static_cast<FMOD_INITFLAGS>(initflags), nullptr) };

		if (LKF_OK(result)) {
			FMOD::ChannelGroup* mastergroup{ nullptr };
			if (LKF_OK(coresys->getMasterChannelGroup(&mastergroup))) {
				mastergroup->setCallback(lkf_coreChannelControl_callback);
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_update(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->update() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_close(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->close() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_release(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->release() };

		if (LKF_OK(result)) {
			lkf_T_pop_back_smart(Global::CoreSystems, static_cast<std::size_t>(csys), Global::CoreSystemLast);
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_setOutput(double csys, double output) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->setOutput(static_cast<FMOD_OUTPUTTYPE>(output)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getOutput(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		FMOD_OUTPUTTYPE fot{};
		auto result{ coresys->getOutput(&fot) };

		if (LKF_OK(result)) {
			return static_cast<double>(fot);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_setSoftwareChannels(double csys, double numsoftwarechannels) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->setSoftwareChannels(static_cast<int>(numsoftwarechannels)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getSoftwareChannels(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		int chan{ 0 };
		auto result{ coresys->getSoftwareChannels(&chan) };

		if (LKF_OK(result)) {
			return static_cast<double>(chan);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getSoftwareFormat(double csys, int* retmem) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		int samplerate{ 0 };
		FMOD_SPEAKERMODE spk{};
		int numrawspeakers{ 0 };
		auto result{ coresys->getSoftwareFormat(&samplerate, &spk, &numrawspeakers) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = samplerate;
				retmem[1] = static_cast<int>(spk);
				retmem[2] = numrawspeakers;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_setDSPBufferSize(double csys, double bufferlen, double numbuffers) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->setDSPBufferSize(static_cast<unsigned int>(bufferlen), static_cast<int>(numbuffers)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getDSPBufferSize(double csys, int* retmem) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		unsigned int bufflen{ 0 };
		int numbuffs{ 0 };
		auto result{ coresys->getDSPBufferSize(&bufflen, &numbuffs) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				(reinterpret_cast<unsigned int*>(retmem))[0] = bufflen;
				retmem[1] = numbuffs;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_setPluginPath(double csys, const char* path) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->setPluginPath(path) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_loadPlugin(double csys, const char* name, double priority) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		unsigned int h{ 0 };
		auto result{ coresys->loadPlugin(name, &h, static_cast<unsigned int>(priority)) };

		if (LKF_OK(result)) {
			return static_cast<double>(h);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_unloadPlugin(double csys, double handle) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->unloadPlugin(static_cast<unsigned int>(handle)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_setOutputByPlugin(double csys, double handle) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->setOutputByPlugin(static_cast<unsigned int>(handle)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getOutputByPlugin(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		unsigned int h{ 0 };
		auto result{ coresys->getOutputByPlugin(&h) };

		if (LKF_OK(result)) {
			return static_cast<double>(h);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_setSpeakerPosition(double csys, double speaker, double x, double y, double active) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->setSpeakerPosition(static_cast<FMOD_SPEAKER>(speaker), static_cast<float>(x), static_cast<float>(y), active > 0.5) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getSpeakerPosition(double csys, double speaker, float* retmem) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		float x{ 0.f };
		float y{ 0.f };
		bool active{ false };
		auto result{ coresys->getSpeakerPosition(static_cast<FMOD_SPEAKER>(speaker), &x, &y, &active) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = x;
				retmem[1] = y;
				retmem[2] = active ? 1.f : 0.f;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_setStreamBufferSize(double csys, double filebuffersize, double filebuffersizetype) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->setStreamBufferSize(static_cast<unsigned int>(filebuffersize), static_cast<FMOD_TIMEUNIT>(filebuffersizetype)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getStreamBufferSize(double csys, unsigned int* retmem) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		unsigned int fbufsize{ 0 };
		FMOD_TIMEUNIT sizetype{ 0 };
		auto result{ coresys->getStreamBufferSize(&fbufsize, &sizetype) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = fbufsize;
				retmem[1] = static_cast<unsigned int>(sizetype);
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_set3DSettings(double csys, double dopplerscale, double distancefactor, double rolloffscale) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->set3DSettings(static_cast<float>(dopplerscale), static_cast<float>(distancefactor), static_cast<float>(rolloffscale)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_get3DSettings(double csys, float* retmem) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{Global::CoreSystems[static_cast<std::size_t>(csys)] };
		float dopplerscale{ 0.f };
		float distancefactor{ 0.f };
		float rolloffscale{ 0.f };
		auto result{ coresys->get3DSettings(&dopplerscale, &distancefactor, &rolloffscale) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = dopplerscale;
				retmem[1] = distancefactor;
				retmem[2] = rolloffscale;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_set3DNumListeners(double csys, double num) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->set3DNumListeners(static_cast<int>(num)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_get3DNumListeners(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		int num{ 0 };
		auto result{ coresys->get3DNumListeners(&num) };

		if (LKF_OK(result)) {
			return static_cast<double>(num);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_set3DListenerAttributes(double csys, double listener, const FMOD_VECTOR* vecs) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		FMOD_VECTOR stack_pos = vecs[0];
		FMOD_VECTOR stack_vel = vecs[1];
		FMOD_VECTOR stack_forward = vecs[2];
		FMOD_VECTOR stack_up = vecs[3];

		auto result{ coresys->set3DListenerAttributes(
			static_cast<int>(listener),
			&stack_pos,
			&stack_vel,
			&stack_forward,
			&stack_up)
		};

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_get3DListenerAttributes(double csys, double listener, FMOD_VECTOR* retmem) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		FMOD_VECTOR stack_pos{ 0.f, 0.f, 0.f };
		FMOD_VECTOR stack_vel{ 0.f, 0.f, 0.f };
		FMOD_VECTOR stack_forward{ 0.f, 0.f, 0.f };
		FMOD_VECTOR stack_up{ 0.f, 0.f, 0.f };
		auto result{ coresys->get3DListenerAttributes(static_cast<int>(listener), &stack_pos, &stack_vel, &stack_forward, &stack_up) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = stack_pos;
				retmem[1] = stack_vel;
				retmem[2] = stack_forward;
				retmem[3] = stack_up;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_mixerSuspend(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->mixerSuspend() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_mixerResume(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->mixerResume() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getVersion(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		unsigned int v{ 0 };
		auto result{ coresys->getVersion(&v) };

		if (LKF_OK(result)) {
			return v;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getOutputHandle(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		void* p{ nullptr };
		auto result{ coresys->getOutputHandle(&p) };

		if (LKF_OK(result)) {
			return static_cast<double>(reinterpret_cast<std::uintptr_t>(p));
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getChannelsPlaying(double csys, int* retmem) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		int channels{ 0 };
		int realchannels{ 0 };
		auto result{ coresys->getChannelsPlaying(&channels, &realchannels) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = channels;
				retmem[1] = realchannels;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getCPUUsage(double csys, float* retmem) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		float dsp{ 0.f };
		float stream{ 0.f };
		float geometry{ 0.f };
		float update{ 0.f };
		float total{ 0.f };
		auto result{ coresys->getCPUUsage(&dsp, &stream, &geometry, &update, &total) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = dsp;
				retmem[1] = stream;
				retmem[2] = geometry;
				retmem[3] = update;
				retmem[4] = total;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getCPUUsageEx(double csys, float* retmem) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		float convolutionThread1{ 0.f };
		float convolutionThread2{ 0.f };
		auto result{ coresys->getCPUUsageEx(&convolutionThread1, &convolutionThread2) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = convolutionThread1;
				retmem[1] = convolutionThread2;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getFileUsage(double csys, long long* retmem) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		//long long *sampleBytesRead, long long *streamBytesRead, long long *otherBytesRead
		long long sampleBytesRead{ 0 };
		long long streamBytesRead{ 0 };
		long long otherBytesRead{ 0 };
		auto result{ coresys->getFileUsage(&sampleBytesRead, &streamBytesRead, &otherBytesRead) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = sampleBytesRead;
				retmem[1] = streamBytesRead;
				retmem[2] = otherBytesRead;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_lockDSP(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->lockDSP() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_unlockDSP(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->unlockDSP() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_setNetworkProxy(double csys, const char* proxy) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->setNetworkProxy(proxy) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

static char temp_getNetworkProxy[2048]{ '\0' };

dllx const char* lkf_coreSystem_getNetworkProxy(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		memset(temp_getNetworkProxy, '\0', sizeof(temp_getNetworkProxy));
		auto result{ coresys->getNetworkProxy(temp_getNetworkProxy, sizeof(temp_getNetworkProxy) - 1) };

		if (LKF_OK(result)) {
			return temp_getNetworkProxy;
		}

		return "<Invalid FMOD result.>";
	}

	return "<Invalid index.>";
}

dllx double lkf_coreSystem_setNetworkTimeout(double csys, double timeout) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto result{ coresys->setNetworkTimeout(static_cast<int>(timeout)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getNetworkTimeout(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		int t{ 0 };
		auto result{ coresys->getNetworkTimeout(&t) };

		if (LKF_OK(result)) {
			return static_cast<double>(t);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_createSound(double csys, const char* name, double mode) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		FMOD::Sound* snd{ nullptr };
		auto result{ coresys->createSound(name, static_cast<FMOD_MODE>(mode), nullptr, &snd) };

		if (LKF_OK(result)) {
			std::size_t i{ lkf_T_push_back_smart(Global::CoreSounds, snd, Global::CoreSoundLast) };
			return static_cast<double>(i);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_createChannelGroup(double csys, const char* name) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		FMOD::ChannelGroup* cchg{ nullptr };
		auto result{ coresys->createChannelGroup(name, &cchg) };

		if (LKF_OK(result)) {
			cchg->setCallback(lkf_coreChannelControl_callback);
			std::size_t i{ lkf_T_push_back_smart(Global::CoreChannelGroups, cchg, Global::CoreChannelGroupLast) };
			return static_cast<double>(i);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_getMasterChannelGroup(double csys) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		FMOD::ChannelGroup* cchg{ nullptr };
		auto result{ coresys->getMasterChannelGroup(&cchg) };

		if (LKF_OK(result)) {
			std::size_t i{ lkf_T_push_back_smart(Global::CoreChannelGroups, cchg, Global::CoreChannelGroupLast) };
			return static_cast<double>(i);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_playSound(double csys, double csnd, double cgrp, double paused) {
	if (lkf_coreSystem_exists(csys) && lkf_coreSound_exists(csnd)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		auto& coresnd{ Global::CoreSounds[static_cast<std::size_t>(csnd)] };
		FMOD::ChannelGroup* coregrp{ nullptr };
		if (cgrp >= 0.0) {
			if (lkf_coreChannelGroup_exists(cgrp)) coregrp = Global::CoreChannelGroups[static_cast<std::size_t>(cgrp)];
			else return LKF_ERR_INVALID_INDEX;
		}

		FMOD::Channel* channel{ nullptr };
		auto result{ coresys->playSound(coresnd, coregrp, paused > 0.5, &channel) };

		if (LKF_OK(result)) {
			channel->setCallback(lkf_coreChannelControl_callback);
			std::size_t i{ lkf_T_push_back_smart(Global::CoreChannels, channel, Global::CoreChannelLast) };
			return static_cast<double>(i);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSystem_createDSPByType(double csys, double type) {
	if (lkf_coreSystem_exists(csys)) {
		auto& coresys{ Global::CoreSystems[static_cast<std::size_t>(csys)] };
		FMOD::DSP* dsp{ nullptr };
		auto result{ coresys->createDSPByType(static_cast<FMOD_DSP_TYPE>(type), &dsp) };

		if (LKF_OK(result)) {
			std::size_t i{ lkf_T_push_back_smart(Global::DSPs, dsp, Global::CoreDSPLast) };
			return static_cast<double>(i);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}
