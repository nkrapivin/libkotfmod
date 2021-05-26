// FMOD::Studio::System
function LKFSystem() constructor {
	_index = -1;
	_callback = undefined;
	_userdata = undefined;
	
	static create = function() {
		if (_index > -1) {
			LKFTrace("%T A Studio system has already been created for this struct. [%0]", _index);	
		}
		
		var _r = lkf_system_create();
		_index = _r;
		__lkf_check_result(_r); // check the returned value BEFORE returning, it might be an error code
		// and not a meaningful index.
		LKFWeakRegister(global._lkf_systems_map, _index, weak_ref_create(self));
		return self;
	};
	
	static initialize = function(maxchannels, studioflags, flags) {
		var _r = lkf_system_initialize(_index, maxchannels, studioflags, flags);
		__lkf_check_result(_r); return self;
	};
	
	static loadBankFile = function(filename, flags) {
		var _r = lkf_system_loadBankFile(_index, filename, flags);
		if (__lkf_check_result(_r))
			return new LKFBank(_r);
	};
	
	static getEvent = function(path) {
		var _r = lkf_system_getEvent(_index, path);
		if (__lkf_check_result(_r))
			return new LKFEventDescription(_r);
	};
	
	static update = function() {
		var _r = lkf_system_update(_index);
		__lkf_check_result(_r); return self;
	}
	
	static unloadAll = function() {
		var _r = lkf_system_unloadAll(_index);
		__lkf_check_result(_r); return self;
	};
	
	static setListenerAttributes = function(listener, attributes, attenuationposition) {
		var _attr_ptr = ptr(pointer_null),
			_attu_ptr = ptr(pointer_null),
			_attr = -1,
			_attu = -1;
		
		if (!is_undefined(attributes)) {
			_attr = buffer_create(buffer_sizeof(buffer_f32) * 3 * 4, buffer_fixed, 1); // xyz * 4 vectors
			attributes.serialize(_attr);
			_attr_ptr = buffer_get_address(_attr);
		}
		
		if (!is_undefined(attenuationposition)) {
			_attu = buffer_create(buffer_sizeof(buffer_f32) * 3, buffer_fixed, 1);
			attenuationposition.serialize(_attu);
			_attu_ptr = buffer_get_address(_attu);
		}
		
		var _r = lkf_system_setListenerAttributes(_index, listener, _attr_ptr, _attu_ptr);
		
		if (buffer_exists(_attr)) buffer_delete(_attr);
		if (buffer_exists(_attu)) buffer_delete(_attu);
		
		__lkf_check_result(_r); return self;
	};
	
	static release = function() {
		var _r = lkf_system_release(_index);
		__lkf_check_result(_r); LKFWeakUnregister(global._lkf_systems_map, _index); return self;
	};
	
	static flushCommands = function() {
		var _r = lkf_system_flushCommands(_index);
		__lkf_check_result(_r); return self;
	};
	
	static flushSampleLoading = function() {
		var _r = lkf_system_flushSampleLoading(_index);
		__lkf_check_result(_r); return self;
	};
	
	static getCPUUsage = function() {
		var _buf = buffer_create(buffer_sizeof(buffer_f32) * 5, buffer_fixed, 1);
		var _r = lkf_system_getCPUUsage(_index, buffer_get_address(_buf));
		__lkf_check_result(_r);
		var _ret = new LKFCPUUsage();
		_ret.deserialize(_buf);
		if (buffer_exists(_buf)) buffer_delete(_buf);
		return _ret;
	};
	
	static getMemoryUsage = function() {
		var _buf = buffer_create(buffer_sizeof(buffer_s32) * 3, buffer_fixed, 1);
		var _r = lkf_system_getMemoryUsage(_index, buffer_get_address(_buf));
		__lkf_check_result(_r);
		var _ret = new LKFMemoryUsage();
		_ret.deserialize(_buf);
		if (buffer_exists(_buf)) buffer_delete(_buf);
		return _ret;
	};
	
	static setCallback = function(_mycallback) {
		if (is_undefined(_mycallback)) { _callback = undefined; return false; }
		_callback = method(self, _mycallback);
		return self;
	};
	
	static getCallback = function() {
		return _callback;	
	};
	
	static getCoreSystem = function() {
		var _r = lkf_system_getCoreSystem(_index);
		if (__lkf_check_result(_r)) {
			if (LKFWeakExists(global._lkf_core_systems_map, _r))
				return global._lkf_core_systems_map[? string(_r)].ref;
			else
				return new LKFCoreSystem(_r);
		}
	};
	
	static setUserData = function(_myuserdata) {
		_userdata = _myuserdata;
		return self;
	};
	
	static getUserData = function() {
		return _userdata;	
	};
}
