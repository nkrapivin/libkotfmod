// [Core API] FMOD::Channel
function LKFCoreChannel(_myindex) constructor {
	_index = _myindex;
	_callback = undefined;
	_userdata = undefined;
	
	LKFWeakRegister(global._lkf_core_channels_map, string(_index), weak_ref_create(self));
	
	static setUserData = function(_myuserdata) {
		_userdata = _myuserdata;
		return self;
	};
	
	static getUserData = function() {
		return _userdata;	
	};
	
	static stop = function() {
		var _r = lkf_coreChannel_stop(_index);
		__lkf_check_result(_r); return self;
	};
	
	static setPaused = function(_paused) {
		var _r = lkf_coreChannel_setPaused(_index, _paused);
		__lkf_check_result(_r); return self;
	};
	
	static getPaused = function() {
		var _r = lkf_coreChannel_getPaused(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setVolume = function(_volume) {
		var _r = lkf_coreChannel_setVolume(_index, _volume);
		__lkf_check_result(_r); return self;
	};
	
	static getVolume = function() {
		var _r = lkf_coreChannel_getVolume(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setVolumeRamp = function(_ramp) {
		var _r = lkf_coreChannel_setVolumeRamp(_index, _ramp);
		__lkf_check_result(_r); return self;
	};
	
	static getVolumeRamp = function() {
		var _r = lkf_coreChannel_getVolumeRamp(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static getAudibility = function() {
		var _r = lkf_coreChannel_getAudibility(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setPitch = function(_pitch) {
		var _r = lkf_coreChannel_setPitch(_index, _pitch);
		__lkf_check_result(_r); return self;
	};
	
	static getPitch = function() {
		var _r = lkf_coreChannel_getPitch(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setMute = function(_mute) {
		var _r = lkf_coreChannel_setMute(_index, _pitch);
		__lkf_check_result(_r); return self;
	};
	
	static getMute = function() {
		var _r = lkf_coreChannel_getMute(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setReverbProperties = function(_instance, _wet) {
		var _r = lkf_coreChannel_setReverbProperties(_index, _instance, _wet);
		__lkf_check_result(_r); return self;
	};
	
	static getReverbProperties = function(_instance) {
		var _r = lkf_coreChannel_getReverbProperties(_index, _instance);
		__lkf_check_result(_r); return _r;
	};
	
	static setLowPassGain = function(_gain) {
		var _r = lkf_coreChannel_setLowPassGain(_index, _gain);
		__lkf_check_result(_r); return self;
	};
	
	static getLowPassGain = function() {
		var _r = lkf_coreChannel_getLowPassGain(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setMode = function(_mode) {
		var _r = lkf_coreChannel_setMode(_index, _mode);
		__lkf_check_result(_r); return self;
	};
	
	static getMode = function() {
		var _r = lkf_coreChannel_getMode(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static isPlaying = function() {
		var _r = lkf_coreChannel_isPlaying(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setPan = function(_pan) {
		var _r = lkf_coreChannel_setPan(_index, _pan);
		__lkf_check_result(_r); return self;
	};
	
	static setMixLevelsOutput = function(_frontleft, _frontright, _center, _lfe, _surrleft, _surrright, _backleft, _backright) {
		var _r = lkf_coreChannel_setMixLevelsOutput(_index,
			_frontleft,
			_frontright,
			_center,
			_lfe,
			_surrleft,
			_surrright,
			_backleft,
			_backright);
		__lkf_check_result(_r); return self;
	};
	
	static getDSPClock = function() {
		var _b = buffer_create(buffer_sizeof(buffer_u64) * 2, buffer_fixed, 1);
		var _r = lkf_coreChannel_getDSPClock(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _dspclock = buffer_read(_b, buffer_u64);
		var _parentclock = buffer_read(_b, buffer_u64);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { dspclock: _dspclock, parentclock: _parentclock };
	};
	
	static setDelay = function(dspclock_start, dspclock_end, stopchan) {
		var _r = lkf_coreChannel_setDelay(_index, dspclock_start, dspclock_end, is_undefined(stopchan) ? true : stopchan);
		__lkf_check_result(_r); return self;
	};
	
	static getDelay = function() {
		var _b = buffer_create(buffer_sizeof(buffer_u64) * 3, buffer_fixed, 1);
		var _r = lkf_coreChannel_getDSPClock(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _dspclock_start = buffer_read(_b, buffer_u64);
		var _dspclock_end = buffer_read(_b, buffer_u64);
		var _stopchannels = buffer_read(_b, buffer_u64) == 1;
		if (buffer_exists(_b)) buffer_delete(_b);
		return { dspclock_start: _dspclock_start, dspclock_end: _dspclock_end, stopchannels: _stopchannels };
	};
	
	static addFadePoint = function(_clock, _volume) {
		var _r = lkf_coreChannel_addFadePoint(_index, _clock, _volume);
		__lkf_check_result(_r); return self;
	};
	
	static setFadePointRamp = function(_clock, _volume) {
		var _r = lkf_coreChannel_setFadePointRamp(_index, _clock, _volume);
		__lkf_check_result(_r); return self;
	};
	
	static removeFadePoints = function(_clock_start, _clock_end) {
		var _r = lkf_coreChannel_removeFadePoints(_index, _clock_start, _clock_end);
		__lkf_check_result(_r); return self;
	};
	
	static getSystemObject = function() {
		var _r = lkf_coreChannel_getSystemObject(_index);
		__lkf_check_result(_r);
		return global._lkf_core_systems_map[? string(_r)].ref;
	};
	
	static getDSP = function(_dindex) {
		var _r = lkf_coreChannel_getDSP(_index, _dindex);
		__lkf_check_result(_r);
		return global._lkf_core_dsps_map[? string(_r)].ref;
	};
	
	static addDSP = function(_dindex, _dsp) {
		var _r = lkf_coreChannel_addDSP(_index, _dindex, _dsp._index);
		__lkf_check_result(_r); return self;
	};
	
	static removeDSP = function(_dsp) {
		var _r = lkf_coreChannel_removeDSP(_index, _dsp._index);
		__lkf_check_result(_r); return self;
	};
	
	static getNumDSPs = function() {
		var _r = lkf_coreChannel_getNumDSPs(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setDSPIndex = function(_dsp, _dindex) {
		var _r = lkf_coreChannel_setDSPIndex(_index, _dsp._index, _dindex);
		__lkf_check_result(_r); return self;
	};
	
	static getDSPIndex = function(_dsp) {
		var _r = lkf_coreChannel_getDSPIndex(_index, _dsp._index);
		__lkf_check_result(_r); return _r;
	};
	
	static setCallback = function(_mycallback) {
		if (is_undefined(_mycallback))
			_callback = undefined;
		else
			_callback = method(self, _mycallback);
		
		return self;
	};
	
	static getCallback = function() {
		return _callback;
	};
}
