#include "libkotfmod.h"

dllx double lkf_eventInstance_exists(double evinst) {
	return (
		evinst >= 0.0
	&&	std::floor(evinst) == evinst
	&&	Global::EventInstances.find(static_cast<std::size_t>(evinst)) != Global::EventInstances.end()
	) ? 1.0 : 0.0;
}

dllx double lkf_eventInstance_start(double evinst) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->start() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_stop(double evinst, double stopmode) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->stop(static_cast<FMOD_STUDIO_STOP_MODE>(stopmode)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_setParameterByName(double evinst, const char* name, double value, double ignoreseekspeed) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->setParameterByName(name, static_cast<float>(value), (ignoreseekspeed > 0.5)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_getParameterByName(double evinst, const char* name, float* retmem) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->getParameterByName(name, retmem, &retmem[1]) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_set3DAttributes(double evinst, const FMOD_3D_ATTRIBUTES* attributes) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->set3DAttributes(attributes) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_get3DAttributes(double evinst, FMOD_3D_ATTRIBUTES* retattr) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };

		auto result{ ev->get3DAttributes(retattr) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_setVolume(double evinst, double volume) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->setVolume(static_cast<float>(volume)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_getVolume(double evinst, float* retmem) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->getVolume(retmem, &retmem[1]) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_setPitch(double evinst, double pitch) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->setVolume(static_cast<float>(pitch)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_getPitch(double evinst, float* retmem) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->getVolume(retmem, &retmem[1]) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_release(double evinst) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->release() };

		if (LKF_OK(result)) {
			// lkf_T_pop_back_smart(Global::EventInstances, static_cast<std::size_t>(evinst), Global::EventInstanceLast);
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_triggerCue(double evinst) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->triggerCue() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_getPaused(double evinst) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		bool value{ false };
		auto result{ ev->getPaused(&value) };

		if (LKF_OK(result)) {
			return value;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_setPaused(double evinst, double paused) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->setPaused(paused > 0.5) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_setReverbLevel(double evinst, double index, double level) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->setReverbLevel(static_cast<int>(index), static_cast<float>(level)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_getReverbLevel(double evinst, double index) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		float level{ 0.0f };
		auto result{ ev->getReverbLevel(static_cast<int>(index), &level) };

		if (LKF_OK(result)) {
			return static_cast<double>(level);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_setTimelinePosition(double evinst, double position) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->setTimelinePosition(static_cast<int>(position)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_getTimelinePosition(double evinst) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		int pos{ 0 };
		auto result{ ev->getTimelinePosition(&pos) };

		if (LKF_OK(result)) {
			return pos;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_setListenerMask(double evinst, double mask) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		auto result{ ev->setListenerMask(static_cast<unsigned int>(mask)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_getListenerMask(double evinst) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		unsigned int m{ 0 };
		auto result{ ev->getListenerMask(&m) };

		if (LKF_OK(result)) {
			return static_cast<double>(m);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_getDescription(double evinst) {
	if (lkf_eventInstance_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		FMOD::Studio::EventDescription* evdesc{ nullptr };
		auto result{ ev->getDescription(&evdesc) };

		if (LKF_OK(result)) {
			std::size_t evdescind{ lkf_T_indexOf(Global::EventDescriptions, evdesc) };
			return static_cast<double>(evdescind);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventInstance_isVirtual(double evinst) {
	if (lkf_eventDescription_exists(evinst)) {
		auto& ev{ Global::EventInstances[static_cast<std::size_t>(evinst)] };
		bool value{ false };
		auto result{ ev->isVirtual(&value) };

		if (LKF_OK(result)) {
			return value;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}