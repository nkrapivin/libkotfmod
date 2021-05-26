#include "libkotfmod.h"

dllx double lkf_eventDescription_exists(double evdesc) {
	return (
		evdesc >= 0.0 // very obvious.
		&& std::floor(evdesc) == evdesc
		&& Global::EventDescriptions.find(static_cast<std::size_t>(evdesc)) != Global::EventDescriptions.end()
	) ? 1.0 : 0.0;
}

dllx double lkf_eventDescription_createInstance(double evdesc) {
	if (lkf_eventDescription_exists(evdesc)) {
		auto& evd{ Global::EventDescriptions[static_cast<std::size_t>(evdesc)] };
		FMOD::Studio::EventInstance* eventInstance{ nullptr };
		auto result{ evd->createInstance(&eventInstance) };

		if (LKF_OK(result)) {
			std::size_t i{ lkf_T_push_back_smart(Global::EventInstances, eventInstance, Global::EventInstanceLast) };
			return static_cast<double>(i);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventDescription_loadSampleData(double evdesc) {
	if (lkf_eventDescription_exists(evdesc)) {
		auto& evd{ Global::EventDescriptions[static_cast<std::size_t>(evdesc)] };
		auto result{ evd->loadSampleData() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventDescription_unloadSampleData(double evdesc) {
	if (lkf_eventDescription_exists(evdesc)) {
		auto& evd{ Global::EventDescriptions[static_cast<std::size_t>(evdesc)] };
		auto result{ evd->unloadSampleData() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventDescription_releaseAllInstances(double evdesc) {
	if (lkf_eventDescription_exists(evdesc)) {
		auto& evd{ Global::EventDescriptions[static_cast<std::size_t>(evdesc)] };
		auto result{ evd->releaseAllInstances() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventDescription_getSampleLoadingState(double evdesc) {
	if (lkf_eventDescription_exists(evdesc)) {
		auto& evd{ Global::EventDescriptions[static_cast<std::size_t>(evdesc)] };
		FMOD_STUDIO_LOADING_STATE st{ };
		auto result{ evd->getSampleLoadingState(&st) };

		if (LKF_OK(result)) {
			return st;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventDescription_isSnapshot(double evdesc) {
	if (lkf_eventDescription_exists(evdesc)) {
		auto& evd{ Global::EventDescriptions[static_cast<std::size_t>(evdesc)] };
		bool val{ false };
		auto result{ evd->isSnapshot(&val) };

		if (LKF_OK(result)) {
			return val;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventDescription_isOneshot(double evdesc) {
	if (lkf_eventDescription_exists(evdesc)) {
		auto& evd{ Global::EventDescriptions[static_cast<std::size_t>(evdesc)] };
		bool val{ false };
		auto result{ evd->isOneshot(&val) };

		if (LKF_OK(result)) {
			return val;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventDescription_isStream(double evdesc) {
	if (lkf_eventDescription_exists(evdesc)) {
		auto& evd{ Global::EventDescriptions[static_cast<std::size_t>(evdesc)] };
		bool val{ false };
		auto result{ evd->isStream(&val) };

		if (LKF_OK(result)) {
			return val;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventDescription_is3D(double evdesc) {
	if (lkf_eventDescription_exists(evdesc)) {
		auto& evd{ Global::EventDescriptions[static_cast<std::size_t>(evdesc)] };
		bool val{ false };
		auto result{ evd->is3D(&val) };

		if (LKF_OK(result)) {
			return val;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventDescription_isDopplerEnabled(double evdesc) {
	if (lkf_eventDescription_exists(evdesc)) {
		auto& evd{ Global::EventDescriptions[static_cast<std::size_t>(evdesc)] };
		bool val{ false };
		auto result{ evd->isDopplerEnabled(&val) };

		if (LKF_OK(result)) {
			return val;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_eventDescription_hasCue(double evdesc) {
	if (lkf_eventDescription_exists(evdesc)) {
		auto& evd{ Global::EventDescriptions[static_cast<std::size_t>(evdesc)] };
		bool val{ false };
		auto result{ evd->hasCue(&val) };

		if (LKF_OK(result)) {
			return val;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}
