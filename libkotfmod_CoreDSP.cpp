// libkotfmod_CoreDSP.cpp: [Core API] DSP.

#include "libkotfmod.h"

dllx double lkf_coreDSP_exists(double cdsp) {
	return (
		cdsp >= 0.0
	&&	std::floor(cdsp) == cdsp
	&&	Global::DSPs.find(static_cast<std::size_t>(cdsp)) != Global::DSPs.end()
	) ? 1.0 : 0.0;
}

dllx double lkf_coreDSP_release(double cdsp) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		auto result{ dspref->release() };

		if (LKF_OK(result)) {
			lkf_T_pop_back_smart(Global::DSPs, static_cast<std::size_t>(cdsp), Global::CoreDSPLast);
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_getSystemObject(double cdsp) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		FMOD::System* sys{ nullptr };
		auto result{ dspref->getSystemObject(&sys) };

		if (LKF_OK(result)) {
			std::size_t i{ lkf_T_indexOf(Global::CoreSystems, sys) };
			return static_cast<double>(i);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_setActive(double cdsp, double active) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		auto result{ dspref->setActive(active > 0.5) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_getActive(double cdsp) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		bool active{ false };
		auto result{ dspref->getActive(&active) };

		if (LKF_OK(result)) {
			return active ? 1.0 : 0.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_setBypass(double cdsp, double bypass) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		auto result{ dspref->setBypass(bypass > 0.5) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_getBypass(double cdsp) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		bool bypass{ false };
		auto result{ dspref->getBypass(&bypass) };

		if (LKF_OK(result)) {
			return bypass ? 1.0 : 0.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_setWetDryMix(double cdsp, double prewet, double postwet, double dry) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		auto result{ dspref->setWetDryMix(static_cast<float>(prewet), static_cast<float>(postwet), static_cast<float>(dry)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_getWetDryMix(double cdsp, float* retmem) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		float prewet{ 0.f };
		float postwet{ 0.f };
		float dry{ 0.f };
		auto result{ dspref->getWetDryMix(&prewet, &postwet, &dry) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				retmem[0] = prewet;
				retmem[1] = postwet;
				retmem[2] = dry;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_reset(double cdsp) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		auto result{ dspref->reset() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_setParameterFloat(double cdsp, double index, double value) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		auto result{ dspref->setParameterFloat(static_cast<int>(index), static_cast<float>(value)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_setParameterInt(double cdsp, double index, double value) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		auto result{ dspref->setParameterInt(static_cast<int>(index), static_cast<int>(value)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_setParameterBool(double cdsp, double index, double value) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		auto result{ dspref->setParameterBool(static_cast<int>(index), value > 0.5) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_setParameterData(double cdsp, double index, const char* value, double length) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		auto result{ dspref->setParameterData(static_cast<int>(index), const_cast<char*>(value), static_cast<unsigned int>(length)) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_getType(double cdsp) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		FMOD_DSP_TYPE t{};
		auto result{ dspref->getType(&t) };

		if (LKF_OK(result)) {
			return static_cast<double>(t);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_coreDSP_getIdle(double cdsp) {
	if (lkf_coreDSP_exists(cdsp)) {
		auto& dspref{ Global::DSPs[static_cast<std::size_t>(cdsp)] };
		bool i{ false };
		auto result{ dspref->getIdle(&i) };

		if (LKF_OK(result)) {
			return i ? 1.0 : 0.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}
