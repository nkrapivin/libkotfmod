// libkotfmod_CoreSound.cpp: [Core API] Sound class.

#include "libkotfmod.h"

dllx double lkf_coreSound_exists(double csys) {
	return (
		csys >= 0.0
	&&	std::floor(csys) == csys
	&&	Global::CoreSounds.find(static_cast<std::size_t>(csys)) != Global::CoreSounds.end()
	) ? 1.0 : 0.0;
}

dllx double lkf_coreSound_setDefaults(double csnd, double freq, double pri) {
	if (lkf_coreSound_exists(csnd)) {
		auto& coresnd{ Global::CoreSounds[static_cast<std::size_t>(csnd)] };
		auto result{ coresnd->setDefaults(static_cast<float>(freq), static_cast<int>(pri)) };

		if (LKF_OK(result)) {
			return 1.0;
		}
		
		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSound_getDefaults(double csnd, float* retmem) {
	if (lkf_coreSound_exists(csnd)) {
		auto& coresnd{ Global::CoreSounds[static_cast<std::size_t>(csnd)] };
		float freq{ 0.f };
		int pri{ 0 };
		auto result{ coresnd->getDefaults(&freq, &pri) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = freq;
				(reinterpret_cast<int*>(retmem))[1] = pri;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSound_set3DMinMaxDistance(double csnd, double dmin, double dmax) {
	if (lkf_coreSound_exists(csnd)) {
		auto& coresnd{ Global::CoreSounds[static_cast<std::size_t>(csnd)] };
		auto result{ coresnd->set3DMinMaxDistance(static_cast<float>(dmin), static_cast<float>(dmax)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSound_get3DMinMaxDistance(double csnd, float* retmem) {
	if (lkf_coreSound_exists(csnd)) {
		auto& coresnd{ Global::CoreSounds[static_cast<std::size_t>(csnd)] };
		float dmin{ 0.f };
		float dmax{ 0.f };
		auto result{ coresnd->get3DMinMaxDistance(&dmin, &dmax) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = dmin;
				retmem[1] = dmax;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSound_set3DConeSettings(double csnd, double insideconeangle, double outsideconeangle, double outsidevolume) {
	if (lkf_coreSound_exists(csnd)) {
		auto& coresnd{ Global::CoreSounds[static_cast<std::size_t>(csnd)] };
		auto result{ coresnd->set3DConeSettings(static_cast<float>(insideconeangle), static_cast<float>(outsideconeangle), static_cast<float>(outsidevolume)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreSound_get3DConeSettings(double csnd, float* retmem) {
	if (lkf_coreSound_exists(csnd)) {
		auto& coresnd{ Global::CoreSounds[static_cast<std::size_t>(csnd)] };
		float inside{ 0.f };
		float outside{ 0.f };
		float vol{ 0.f };
		auto result{ coresnd->get3DConeSettings(&inside, &outside, &vol) };

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