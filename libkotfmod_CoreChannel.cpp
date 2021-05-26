// libkotfmod_CoreChannel.cpp: [Core API] Channel stuff

#include "libkotfmod.h"

dllx double lkf_coreChannel_exists(double cchn) {
	return (
		cchn >= 0.0
	&&	std::floor(cchn) == cchn
	&&	Global::CoreChannels.find(static_cast<std::size_t>(cchn)) != Global::CoreChannels.end()
	) ? 1.0 : 0.0;
}

dllx double lkf_coreChannel_stop(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->stop() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setPaused(double cc, double paused) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->setPaused(paused > 0.5) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getPaused(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		bool p{ false };
		auto result{ ccref->getPaused(&p) };

		if (LKF_OK(result)) {
			return p ? 1.0 : 0.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setVolume(double cc, double volume) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->setVolume(static_cast<float>(volume)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getVolume(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		float volume{ 0.f };
		auto result{ ccref->getVolume(&volume) };

		if (LKF_OK(result)) {
			return static_cast<double>(volume);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setVolumeRamp(double cc, double ramp) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->setVolumeRamp(ramp > 0.5) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getVolumeRamp(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		bool r{ false };
		auto result{ ccref->getVolumeRamp(&r) };

		if (LKF_OK(result)) {
			return r ? 1.0 : 0.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getAudibility(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		float a{ 0.f };
		auto result{ ccref->getAudibility(&a) };

		if (LKF_OK(result)) {
			return static_cast<double>(a);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setPitch(double cc, double pitch) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->setPitch(static_cast<float>(pitch)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getPitch(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		float p{ 0.f };
		auto result{ ccref->getPitch(&p) };

		if (LKF_OK(result)) {
			return static_cast<double>(p);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setMute(double cc, double mute) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->setPitch(mute > 0.5) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getMute(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		bool m{ false };
		auto result{ ccref->getMute(&m) };

		if (LKF_OK(result)) {
			return m ? 1.0 : 0.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setReverbProperties(double cc, double instance, double wet) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->setReverbProperties(static_cast<int>(instance), static_cast<float>(wet)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getReverbProperties(double cc, double instance) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		float w{ 0.f };
		auto result{ ccref->getReverbProperties(static_cast<int>(instance), &w) };

		if (LKF_OK(result)) {
			return static_cast<double>(w);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setLowPassGain(double cc, double gain) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->setLowPassGain(static_cast<float>(gain)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getLowPassGain(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		float g{ 0.f };
		auto result{ ccref->getLowPassGain(&g) };

		if (LKF_OK(result)) {
			return static_cast<double>(g);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setMode(double cc, double mode) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->setMode(static_cast<FMOD_MODE>(mode)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getMode(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		FMOD_MODE m{};
		auto result{ ccref->getMode(&m) };

		if (LKF_OK(result)) {
			return static_cast<double>(m);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_isPlaying(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		bool isp{ false };
		auto result{ ccref->isPlaying(&isp) };

		if (LKF_OK(result)) {
			return isp ? 1.0 : 0.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setPan(double cc, double pan) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->setPan(static_cast<float>(pan)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setMixLevelsOutput(double cc, double frontleft, double frontright, double center, double lfe, double surroundleft, double surroundright, double backleft, double backright) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{
			ccref->setMixLevelsOutput(
				static_cast<float>(frontleft),
				static_cast<float>(frontright),
				static_cast<float>(center),
				static_cast<float>(lfe),
				static_cast<float>(surroundleft),
				static_cast<float>(surroundright),
				static_cast<float>(backleft),
				static_cast<float>(backright)
			)
		};

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getDSPClock(double cc, unsigned long long* retmem) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		unsigned long long dspclock{ 0 };
		unsigned long long parentclock{ 0 };
		auto result{ ccref->getDSPClock(&dspclock, &parentclock) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = dspclock;
				retmem[1] = parentclock;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setDelay(double cc, double clock_start, double clock_end, double stopchan) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->setDelay(static_cast<unsigned long long>(clock_start), static_cast<unsigned long long>(clock_end), stopchan > 0.5) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getDelay(double cc, unsigned long long* retmem) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		unsigned long long dspclock_start{ 0 };
		unsigned long long dspclock_end{ 0 };
		bool stopchannels{ false };
		auto result{ ccref->getDelay(&dspclock_start, &dspclock_end, &stopchannels) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = dspclock_start;
				retmem[1] = dspclock_end;
				retmem[2] = stopchannels ? 1 : 0;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_addFadePoint(double cc, double clock, double volume) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->addFadePoint(static_cast<unsigned long long>(clock), static_cast<float>(volume)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setFadePointRamp(double cc, double clock, double volume) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->setFadePointRamp(static_cast<unsigned long long>(clock), static_cast<float>(volume)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_removeFadePoints(double cc, double clock_start, double clock_end) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->removeFadePoints(static_cast<unsigned long long>(clock_start), static_cast<unsigned long long>(clock_end)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getSystemObject(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		FMOD::System* sys{ nullptr };
		auto result{ ccref->getSystemObject(&sys) };

		if (LKF_OK(result)) {
			std::size_t i{ lkf_T_indexOf(Global::CoreSystems, sys) };
			return static_cast<double>(i);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_set3DAttributes(double cc, const FMOD_VECTOR* vecs) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		FMOD_VECTOR pos = vecs[0];
		FMOD_VECTOR vel = vecs[1];
		auto result{ ccref->set3DAttributes(&pos, &vel) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_get3DAttributes(double cc, FMOD_VECTOR* retmem) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		FMOD_VECTOR pos{ 0.f, 0.f, 0.f };
		FMOD_VECTOR vel{ 0.f, 0.f, 0.f };
		auto result{ ccref->get3DAttributes(&pos, &vel) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = pos;
				retmem[1] = vel;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_set3DMinMaxDistance(double cc, double dmin, double dmax) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->set3DMinMaxDistance(static_cast<float>(dmin), static_cast<float>(dmax)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_get3DMinMaxDistance(double cc, float* retmem) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		float mindistance{ 0.f };
		float maxdistance{ 0.f };
		auto result{ ccref->get3DMinMaxDistance(&mindistance, &maxdistance) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = mindistance;
				retmem[1] = maxdistance;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_set3DConeSettings(double cc, double insideconeangle, double outsideconeangle, double outsidevolume) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->set3DConeSettings(static_cast<float>(insideconeangle), static_cast<float>(outsideconeangle), static_cast<float>(outsidevolume)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_get3DConeSettings(double cc, float* retmem) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		float inside{ 0.f };
		float outside{ 0.f };
		float vol{ 0.f };
		auto result{ ccref->get3DConeSettings(&inside, &outside, &vol) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = inside;
				retmem[1] = outside;
				retmem[2] = vol;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_set3DConeOrientation(double cc, FMOD_VECTOR* vec) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->set3DConeOrientation(vec) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_get3DConeOrientation(double cc, FMOD_VECTOR* retmem) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		FMOD_VECTOR stack_vec{ 0.f, 0.f, 0.f };
		auto result{ ccref->get3DConeOrientation(&stack_vec) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = stack_vec;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_set3DOcclusion(double cc, double directocclusion, double reverbocclusion) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->set3DOcclusion(static_cast<float>(directocclusion), static_cast<float>(reverbocclusion)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_get3DOcclusion(double cc, float* retmem) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		float directocclusion{ 0.f };
		float reverbocclusion{ 0.f };
		auto result{ ccref->get3DOcclusion(&directocclusion, &reverbocclusion) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = directocclusion;
				retmem[1] = reverbocclusion;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_set3DSpread(double cc, double angle) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->set3DSpread(static_cast<float>(angle)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_get3DSpread(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		float angle{ 0.f };
		auto result{ ccref->get3DSpread(&angle) };

		if (LKF_OK(result)) {
			return angle;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_set3DLevel(double cc, double level) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->set3DLevel(static_cast<float>(level)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_get3DLevel(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		float level{ 0.f };
		auto result{ ccref->get3DLevel(&level) };

		if (LKF_OK(result)) {
			return level;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_set3DDopplerLevel(double cc, double level) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->set3DDopplerLevel(static_cast<float>(level)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_get3DDopplerLevel(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		float level{ 0.f };
		auto result{ ccref->get3DDopplerLevel(&level) };

		if (LKF_OK(result)) {
			return level;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}


dllx double lkf_coreChannel_set3DDistanceFilter(double cc, double custom, double customLevel, double centerFreq) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto result{ ccref->set3DDistanceFilter(custom > 0.5, static_cast<float>(customLevel), static_cast<float>(centerFreq)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_get3DDistanceFilter(double cc, float* retmem) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		bool custom{ false };
		float customLevel{ 0.f };
		float centerFreq{ 0.f };
		auto result{ ccref->get3DDistanceFilter(&custom, &customLevel, &centerFreq) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = custom ? 1.f : 0.f;
				retmem[1] = customLevel;
				retmem[2] = centerFreq;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

// DSP stuff.

dllx double lkf_coreChannel_getDSP(double cc, double index) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		FMOD::DSP* dsp{ nullptr };
		auto result{ ccref->getDSP(static_cast<int>(index), &dsp) };

		if (LKF_OK(result)) {
			std::size_t i{ lkf_T_push_back_smart(Global::DSPs, dsp, Global::CoreDSPLast) };
			return static_cast<double>(i);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_addDSP(double cc, double index, double cdsp) {
	if (lkf_coreChannel_exists(cc) && lkf_coreDSP_exists(cdsp)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		auto result{ ccref->addDSP(static_cast<int>(index), dspref) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_removeDSP(double cc, double cdsp) {
	if (lkf_coreChannel_exists(cc) && lkf_coreDSP_exists(cdsp)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		auto result{ ccref->removeDSP(dspref) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getNumDSPs(double cc) {
	if (lkf_coreChannel_exists(cc)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		int num{ 0 };
		auto result{ ccref->getNumDSPs(&num) };

		if (LKF_OK(result)) {
			return static_cast<double>(num);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_setDSPIndex(double cc, double cdsp, double index) {
	if (lkf_coreChannel_exists(cc) && lkf_coreDSP_exists(cdsp)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		auto result{ ccref->setDSPIndex(dspref, static_cast<int>(index)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreChannel_getDSPIndex(double cc, double cdsp) {
	if (lkf_coreChannel_exists(cc) && lkf_coreDSP_exists(cdsp)) {
		auto& ccref{ Global::CoreChannels[static_cast<std::size_t>(cc)] };
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		int ind{ 0 };
		auto result{ ccref->getDSPIndex(dspref, &ind) };

		if (LKF_OK(result)) {
			return static_cast<double>(ind);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

// Channel-specific only.


