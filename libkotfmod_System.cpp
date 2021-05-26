#include "libkotfmod.h"

dllx double lkf_system_create() {
	FMOD::Studio::System* sys{ nullptr };
	auto result{ FMOD::Studio::System::create(&sys) };

	if (LKF_OK(result)) {
		std::size_t i{ lkf_T_push_back_smart(Global::Systems, sys, Global::SystemLast) };
		// don't need the update callbacks because they are spammy.
		sys->setCallback(lkf_studio_system_callback);
		return static_cast<double>(i);
	}

	return lkf_err_code(result);
}

dllx double lkf_system_update(double system) {
	if (lkf_system_exists(system)) {
		auto& sys{ Global::Systems[static_cast<std::size_t>(system)] };
		auto result{ sys->update() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_system_exists(double system) {
	return (
		system >= 0.0 // very obvious.
		&& std::floor(system) == system
		&& system < (static_cast<double>(Global::Systems.size()))
		&& Global::Systems[(static_cast<std::size_t>(system))] != nullptr
	) ? 1.0 : 0.0;
}

dllx double lkf_system_initialize(double system, double maxchannels, double studioflags, double flags) {
	if (lkf_system_exists(system)) {
		auto& sys{ Global::Systems[static_cast<std::size_t>(system)] };
		auto result{ sys->initialize(
			static_cast<int>(maxchannels),
			static_cast<FMOD_STUDIO_INITFLAGS>(studioflags),
			static_cast<FMOD_INITFLAGS>(flags),
			nullptr) };

		if (LKF_OK(result)) {
			FMOD::System* coresys{ nullptr };
			if (LKF_OK(sys->getCoreSystem(&coresys))) {
				lkf_T_push_back_smart(Global::CoreSystems, coresys, Global::CoreSystemLast);
				coresys->setCallback(lkf_coreSystem_callback);
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_system_loadBankFile(double system, const char* filename, double flags) {
	if (lkf_system_exists(system)) {
		auto& sys{ Global::Systems[static_cast<std::size_t>(system)] };
		FMOD::Studio::Bank* bank{ nullptr };
		auto result{
			sys->loadBankFile(filename, static_cast<FMOD_STUDIO_LOAD_BANK_FLAGS>(flags), &bank)
		};

		if (LKF_OK(result)) {
			std::size_t i{ lkf_T_push_back_smart(Global::Banks, bank, Global::BankLast) };
			return static_cast<double>(i);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_system_getEvent(double system, const char* path) {
	if (lkf_system_exists(system)) {
		auto& sys{ Global::Systems[static_cast<std::size_t>(system)] };
		FMOD::Studio::EventDescription* eventDescription{ nullptr };
		auto result{ sys->getEvent(path, &eventDescription) };

		if (LKF_OK(result)) {
			std::size_t i{ lkf_T_push_back_smart(Global::EventDescriptions, eventDescription, Global::EventDescriptionLast) };
			eventDescription->setCallback(lkf_studio_event_callback);
			return static_cast<double>(i);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_system_unloadAll(double system) {
	if (lkf_system_exists(system)) {
		auto& sys{ Global::Systems[static_cast<std::size_t>(system)] };
		auto result{ sys->unloadAll() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_system_setListenerAttributes(double system, double listener, const FMOD_3D_ATTRIBUTES* attributes, const FMOD_VECTOR* attenuationposition) {
	if (lkf_system_exists(system)) {
		auto& sys{ Global::Systems[static_cast<std::size_t>(system)] };

		// reallocate everything on the stack just in case, so we don't screw with GM's memory.

		FMOD_3D_ATTRIBUTES attr{ { 0.f, 0.f, 0.f }, { 0.f, 0.f, 0.f }, { 0.f, 0.f, 0.f }, { 0.f, 0.f, 0.f } };
		FMOD_VECTOR att{ 0.f, 0.f, 0.f };

		// only copy if pointers are valid.
		if (attributes != nullptr)
			attr = *attributes;
		if (attenuationposition != nullptr)
			att = *attenuationposition;

		auto result{ sys->setListenerAttributes(static_cast<int>(listener), &attr, (attenuationposition != nullptr) ? &att : nullptr) };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_system_release(double system) {
	if (lkf_system_exists(system)) {
		auto& sys{ Global::Systems[static_cast<std::size_t>(system)] };
		auto result{ sys->release() };

		if (LKF_OK(result)) {
			lkf_T_pop_back_smart(Global::Systems, static_cast<std::size_t>(system), Global::SystemLast);
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_system_flushCommands(double system) {
	if (lkf_system_exists(system)) {
		auto& sys{ Global::Systems[static_cast<std::size_t>(system)] };
		auto result{ sys->flushCommands() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_system_flushSampleLoading(double system) {
	if (lkf_system_exists(system)) {
		auto& sys{ Global::Systems[static_cast<std::size_t>(system)] };
		auto result{ sys->flushSampleLoading() };

		if (LKF_OK(result)) {
			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_system_getCPUUsage(double system, FMOD_STUDIO_CPU_USAGE* retmem) {
	if (lkf_system_exists(system)) {
		auto& sys{ Global::Systems[static_cast<std::size_t>(system)] };
		FMOD_STUDIO_CPU_USAGE usage{ 0.f, 0.f, 0.f, 0.f, 0.f };
		auto result{ sys->getCPUUsage(&usage) };

		if (LKF_OK(result)) {
			if (retmem != nullptr) {
				(*retmem) = usage;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_system_getMemoryUsage(double system, FMOD_STUDIO_MEMORY_USAGE* memoryusage) {
	if (lkf_system_exists(system)) {
		auto& sys{ Global::Systems[static_cast<std::size_t>(system)] };
		FMOD_STUDIO_MEMORY_USAGE usage{ 0, 0, 0 };
		auto result{ sys->getMemoryUsage(&usage) };
		
		if (LKF_OK(result)) {
			if (memoryusage != nullptr) {
				(*memoryusage) = usage;
			}

			return 1.0;
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}

dllx double lkf_system_getCoreSystem(double system) {
	if (lkf_system_exists(system)) {
		auto& sys{ Global::Systems[static_cast<std::size_t>(system)] };
		FMOD::System* coresystem{ nullptr };
		auto result{ sys->getCoreSystem(&coresystem) };

		if (LKF_OK(result)) {
			std::size_t i{ lkf_T_push_back_smart(Global::CoreSystems, coresystem, Global::CoreSystemLast) };
			return static_cast<double>(i);
		}

		return lkf_err_code(result);
	}

	return LKF_ERR_INVALID_INDEX;
}
