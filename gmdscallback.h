#pragma once

//void CreateAsynEventWithDSMap(int dsmapindex, int event_index)
//int CreateDsMap(int _num, ...)
//bool F_DsMapAdd_Internal(int _index, char * _pKey, double _value)
//bool F_DsMapAdd_Internal.conflict2(int _index, char * _pKey, char * _pValue)
typedef void(*CreateAsynEventWithDSMap_t)(int dsmapindex, int event_index);
typedef int(*CreateDsMap_t)(int _num, ...);
typedef bool(*DsMapAddD_t)(int _index, const char* _pKey, double _value);
typedef bool(*DsMapAddS_t)(int _index, const char* _pKey, const char* _pValue);

extern CreateAsynEventWithDSMap_t CreateAsynEventWithDSMap;
extern CreateDsMap_t CreateDsMap;
extern DsMapAddD_t DsMapAddD;
extern DsMapAddS_t DsMapAddS;

const int ev_audio_playback = 74;
