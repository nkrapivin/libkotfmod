// [Core API] FMOD::System
function LKFCoreSystem() constructor {
	_index = argument_count ? argument[0] : -1;
	_callback = undefined;
	_userdata = undefined;
	
	if (_index > -1) {
		LKFTrace("Registering new Core System [%0].", _index);
		LKFWeakRegister(global._lkf_core_systems_map, _index, weak_ref_create(self));
	}
	
	static setSoftwareFormat = function(samplerate, speakermode, numrawspeakers) {
		var _r = lkf_coreSystem_setSoftwareFormat(_index, samplerate, speakermode, numrawspeakers);
		__lkf_check_result(_r); return self;
	};
	
	static setUserData = function(_myuserdata) {
		_userdata = _myuserdata;
		return self;
	};
	
	static getUserData = function() {
		return _userdata;	
	};
	
	static create = function() {
		if (_index > -1) {
			LKFTrace("%T A core system has already been created for this struct. [%0]", _index);
		}
		
		var _r = lkf_coreSystem_create();
		__lkf_check_result(_r);
		_index = _r;
		LKFWeakRegister(global._lkf_core_systems_map, _index, weak_ref_create(self));
		return self;
	};
	
	static init = function(_maxchan, _initflags) {
		var _r = lkf_coreSystem_init(_index, _maxchan, _initflags);
		__lkf_check_result(_r); return self;
	};
	
	static update = function() {
		var _r = lkf_coreSystem_update(_index);
		__lkf_check_result(_r); return self;
	};
	
	static close = function() {
		var _r = lkf_coreSystem_close(_index);
		__lkf_check_result(_r); return self;
	};
	
	static release = function() {
		var _r = lkf_coreSystem_release(_index);
		__lkf_check_result(_r); LKFWeakUnregister(global._lkf_core_systems_map, _index); return self;
	};
	
	static setOutput = function(_output) {
		var _r = lkf_coreSystem_setOutput(_index, _output);
		__lkf_check_result(_r); return self;
	};
	
	static getOutput = function() {
		var _r = lkf_coreSystem_getOutput(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setSoftwareChannels = function(_numsoftchan) {
		var _r = lkf_coreSystem_setSoftwareChannels(_index, _numsoftchan);
		__lkf_check_result(_r); return self;
	};
	
	static getSoftwareChannels = function() {
		var _r = lkf_coreSystem_getSoftwareChannels(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static getSoftwareFormat = function() {
		var _b = buffer_create(buffer_sizeof(buffer_s32) * 3, buffer_fixed, 1);
		var _r = lkf_coreSystem_getSoftwareFormat(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _samplerate = buffer_read(_b, buffer_s32);
		var _speakermode = buffer_read(_b, buffer_s32);
		var _numrawspeakers = buffer_read(_b, buffer_s32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { samplerate: _samplerate, speakermode: _speakermode, numrawspeakers: _numrawspeakers };
	};
	
	static setDSPBufferSize = function(_bufflen, _numbuff) {
		var _r = lkf_coreSystem_setDSPBufferSize(_index, _bufflen, _numbuff);
		__lkf_check_result(_r); return self;
	};
	
	static getDSPBufferSize = function() {
		var _b = buffer_create(buffer_sizeof(buffer_u32) * 2, buffer_fixed, 1);
		var _r = lkf_coreSystem_getDSPBufferSize(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _bufferlength = buffer_read(_b, buffer_u32);
		var _numbuffers = buffer_read(_b, buffer_s32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { bufferlength: _bufferlength, numbuffers: _numbuffers };
	};
	
	static setPluginPath = function(_path) {
		var _r = lkf_coreSystem_setPluginPath(_index, _path);
		__lkf_check_result(_r); return self;
	};
	
	static loadPlugin = function(_name, _prio) {
		var _r = lkf_coreSystem_loadPlugin(_index, _name, _prio);
		__lkf_check_result(_r); return _r;
	};
	
	static unloadPlugin = function(_handle) {
		var _r = lkf_coreSystem_unloadPlugin(_index, _handle);
		__lkf_check_result(_r); return self;
	};
	
	static setOutputByPlugin = function(_handle) {
		var _r = lkf_coreSystem_setOutputByPlugin(_index, _handle);
		__lkf_check_result(_r); return self;
	};
	
	static getOutputByPlugin = function() {
		var _r = lkf_coreSystem_getOutputByPlugin(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setSpeakerPosition = function(_spk, _x, _y, _active) {
		var _r = lkf_coreSystem_setSpeakerPosition(_index, _spk, _x, _y, _active);
		__lkf_check_result(_r); return self;
	};
	
	static getSpeakerPosition = function(_spk) {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 3, buffer_fixed, 1);
		var _r = lkf_coreSystem_getSpeakerPosition(_index, _spk, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _x = buffer_read(_b, buffer_f32);
		var _y = buffer_read(_b, buffer_f32);
		var _active = buffer_read(_b, buffer_f32) == 1.0;
		if (buffer_exists(_b)) buffer_delete(_b);
		return { x: _x, y: _y, active: _active };
	};
	
	static setStreamBufferSize = function(_filebuffersize, _filebuffersizetype) {
		var _r = lkf_coreSystem_setStreamBufferSize(_index, _filebuffersize, _filebuffersizetype);	
		__lkf_check_result(_r); return self;
	};
	
	static getStreamBufferSize = function() {
		var _b = buffer_create(buffer_sizeof(buffer_u32) * 2, buffer_fixed, 1);
		var _r = lkf_coreSystem_getStreamBufferSize(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _filebuffersize = buffer_read(_b, buffer_u32);
		var _filebuffersizetype = buffer_read(_b, buffer_u32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { filebuffersize: _filebuffersize, filebuffersizetype: _filebuffersizetype };
	};
	
	static set3DSettings = function(_dopplerscale, _distancefactor, _rolloffscale) {
		var _r = lkf_coreSystem_set3DSettings(_index, _dopplerscale, _distancefactor, _rolloffscale);
		__lkf_check_result(_r); return self;
	};
	
	static get3DSettings = function() {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 3, buffer_fixed, 1);
		var _r = lkf_coreSystem_get3DSettings(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _dopplerscale = buffer_read(_b, buffer_f32);
		var _distancefactor = buffer_read(_b, buffer_f32);
		var _rolloffscale = buffer_read(_b, buffer_f32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { dopplerscale: _dopplerscale, distancefactor: _distancefactor, rolloffscale: _rolloffscale };
	};
	
	static set3DNumListeners = function(_numlisteners) {
		var _r = lkf_coreSystem_set3DNumListeners(_index, _numlisteners);
		__lkf_check_result(_r); return self;
	};
	
	static get3DNumListeners = function() {
		var _r = lkf_coreSystem_get3DNumListeners(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static set3DListenerAttributes = function(_listener, _pos, _vel, _forward, _up) {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 3 * 4, buffer_fixed, 1);
		_pos.serialize(_b);
		_vel.serialize(_b);
		_forward.serialize(_b);
		_up.serialize(_b);
		var _r = lkf_coreSystem_set3DListenerAttributes(_index, _listener, buffer_get_address(_b));
		if (buffer_exists(_b)) buffer_delete(_b);
		__lkf_check_result(_r); return self;
	};
	
	static get3DListenerAttributes = function(_listener) {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 3 * 4, buffer_fixed, 1);
		var _r = lkf_coreSystem_get3DListenerAttributes(_index, _listener, buffer_get_address(_b));
		var _retattr = new LKF3DAttributes();
		_retattr.deserialize(_b);
		if (buffer_exists(_b)) buffer_delete(_b);
		__lkf_check_result(_r); return _retattr;
	};
	
	static mixerSuspend = function() {
		var _r = lkf_coreSystem_mixerSuspend();
		__lkf_check_result(_r); return self;
	};
	
	static mixerResume = function() {
		var _r = lkf_coreSystem_mixerResume();
		__lkf_check_result(_r); return self;
	};
	
	static getVersion = function() {
		var _r = lkf_coreSystem_getVersion();
		__lkf_check_result(_r); return _r;
	};
	
	static getOutputHandle = function() {
		var _r = lkf_coreSystem_getOutputHandle();
		__lkf_check_result(_r); return _r;
	};
	
	static getChannelsPlaying = function() {
		var _b = buffer_create(buffer_sizeof(buffer_s32) * 2, buffer_fixed, 1);
		var _r = lkf_coreSystem_getChannelsPlaying(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _channels = buffer_read(_b, buffer_s32);
		var _realchannels = buffer_read(_b, buffer_s32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { channels: _channels, realchannels: _realchannels };
	};
	
	static getCPUUsage = function() {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 5, buffer_fixed, 1);
		var _r = lkf_coreSystem_getCPUUsage(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _dsp = buffer_read(_b, buffer_f32);
		var _stream = buffer_read(_b, buffer_f32);
		var _geometry = buffer_read(_b, buffer_f32);
		var _update = buffer_read(_b, buffer_f32);
		var _total = buffer_read(_b, buffer_f32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { dsp: _dsp, stream: _stream, geometry: _geometry, update: _update, total: _total };
	};
	
	static getCPUUsageEx = function() {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 2, buffer_fixed, 1);
		var _r = lkf_coreSystem_getCPUUsageEx(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _convolutionThread1 = buffer_read(_b, buffer_f32);
		var _convolutionThread2 = buffer_read(_b, buffer_f32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { convolutionThread1: _convolutionThread1, convolutionThread2: _convolutionThread2 };
	};
	
	static getFileUsage = function() {
		var _b = buffer_create(buffer_sizeof(buffer_u64) * 3, buffer_fixed, 1);
		var _r = lkf_coreSystem_getFileUsage(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _sampleBytesRead = buffer_read(_b, buffer_u64);
		var _streamBytesRead = buffer_read(_b, buffer_u64);
		var _otherBytesRead = buffer_read(_b, buffer_u64);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { sampleBytesRead: _sampleBytesRead, streamBytesRead: _streamBytesRead, otherBytesRead: _otherBytesRead };
	};
	
	static lockDSP = function() {
		var _r = lkf_coreSystem_lockDSP(_index);
		__lkf_check_result(_r); return self;
	};
	
	static unlockDSP = function() {
		var _r = lkf_coreSystem_unlockDSP(_index);
		__lkf_check_result(_r); return self;
	};
	
	static setNetworkProxy = function(_proxy) {
		var _r = lkf_coreSystem_setNetworkProxy(_index, _proxy);
		__lkf_check_result(_r); return self;
	};
	
	static getNetworkProxy = function() {
		var _r = lkf_coreSystem_getNetworkProxy(_index); // returns a string.
		return _r;
	};
	
	static setNetworkTimeout = function(_timeout) {
		var _r = lkf_coreSystem_setNetworkTimeout(_index, _timeout);
		__lkf_check_result(_r); return self;
	};
	
	static getNetworkTimeout = function() {
		var _r = lkf_coreSystem_getNetworkTimeout(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static createSound = function(_name, _mode) {
		var _r = lkf_coreSystem_createSound(_index, _name, _mode);
		if (__lkf_check_result(_r))
			return new LKFCoreSound(_r);
	};
	
	static createChannelGroup = function(_name) {
		var _r = lkf_coreSystem_createChannelGroup(_index, _name);
		if (__lkf_check_result(_r))
			return new LKFCoreChannelGroup(_r);
	};
	
	static getMasterChannelGroup = function() {
		var _r = lkf_coreSystem_getMasterChannelGroup(_index);
		__lkf_check_result(_r);
		if (LKFWeakExists(global._lkf_core_channel_groups_map, _r)) {
			// you've already got the master group once.
			return global._lkf_core_channel_groups_map[? string(_r)].ref;	
		}
		else {
			return new LKFCoreChannelGroup(_r);	
		}
	}
	
	static playSound = function(_snd, _grp, _paused) {
		var _grpind = -1;
		// undefined _grp means master channel group, so it's ok here.
		if (!is_undefined(_grp)) _grpind = _grp._index;
		
		var _r = lkf_coreSystem_playSound(_index, _snd._index, _grpind, _paused);
		__lkf_check_result(_r);
		return new LKFCoreChannel(_r);
	};
	
	static createDSPByType = function(_type) {
		var _r = lkf_coreSystem_createDSPByType(_index, _type);
		__lkf_check_result(_r);
		return new LKFCoreDSP(_r);
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
