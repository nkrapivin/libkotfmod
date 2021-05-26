// libkotfmod_Bank.cpp: Bank class bindings.
#include "libkotfmod.h"

dllx double lkf_bank_exists(double bank) {
	return (
		bank >= 0.0 // very obvious.
		&& std::floor(bank) == bank
		&& Global::Banks.find(static_cast<std::size_t>(bank)) != Global::Banks.end()
	) ? 1.0 : 0.0;
}

dllx double lkf_bank_unload(double bank) {
	if (lkf_bank_exists(bank)) {
		auto& bnk{ Global::Banks[static_cast<std::size_t>(bank)] };
		auto result{ bnk->unload() };

		if (LKF_OK(result)) {
			lkf_T_pop_back_smart(Global::Banks, static_cast<std::size_t>(bank), Global::BankLast);
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_bank_loadSampleData(double bank) {
	if (lkf_bank_exists(bank)) {
		auto& bnk{ Global::Banks[static_cast<std::size_t>(bank)] };
		auto result{ bnk->loadSampleData() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_bank_unloadSampleData(double bank) {
	if (lkf_bank_exists(bank)) {
		auto& bnk{ Global::Banks[static_cast<std::size_t>(bank)] };
		auto result{ bnk->unloadSampleData() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_bank_getLoadingState(double bank) {
	if (lkf_bank_exists(bank)) {
		auto& bnk{ Global::Banks[static_cast<std::size_t>(bank)] };
		FMOD_STUDIO_LOADING_STATE st{ };
		auto result{ bnk->getLoadingState(&st) };

		if (LKF_OK(result)) {
			return st;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_bank_getSampleLoadingState(double bank) {
	if (lkf_bank_exists(bank)) {
		auto& bnk{ Global::Banks[static_cast<std::size_t>(bank)] };
		FMOD_STUDIO_LOADING_STATE st{ };
		auto result{ bnk->getSampleLoadingState(&st) };

		if (LKF_OK(result)) {
			return st;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}
