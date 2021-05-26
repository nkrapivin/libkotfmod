// libkotfmod_RegisterCallbacks.cpp: Contains GML callback stuff.
#include "libkotfmod.h"

CreateAsynEventWithDSMap_t CreateAsynEventWithDSMap{ nullptr };
CreateDsMap_t CreateDsMap{ nullptr };
DsMapAddD_t DsMapAddD{ nullptr };
DsMapAddS_t DsMapAddS{ nullptr };

dllx char* RegisterCallbacks(void* please, void* dont, void* call, void* it) {
	CreateAsynEventWithDSMap = reinterpret_cast<CreateAsynEventWithDSMap_t>(please);
	CreateDsMap = reinterpret_cast<CreateDsMap_t>(dont);
	DsMapAddD = reinterpret_cast<DsMapAddD_t>(call);
	DsMapAddS = reinterpret_cast<DsMapAddS_t>(it);
	LKF_TRACE("Callbacks registered! 1=0x%p, 2=0x%p, 3=0x%p, 4=0x%p.", CreateAsynEventWithDSMap, CreateDsMap, DsMapAddD, DsMapAddS);
	return nullptr; // TODO: fix after updating GmxGen.
}

dllx double lkf_are_callbacks_registered() {
	return (((CreateAsynEventWithDSMap != nullptr) && (CreateDsMap != nullptr) && (DsMapAddD != nullptr) && (DsMapAddS != nullptr)) ? 1.0 : 0.0);
}
