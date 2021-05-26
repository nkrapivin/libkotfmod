// FMOD::Studio::EventInstance
function LKFEventInstance(_myindex) constructor {
	_index = _myindex;
	_callback = undefined;
	_userdata = undefined;
	
	LKFWeakRegister(global._lkf_events_map, _index, weak_ref_create(self));
	
	static start = function() {
		var _r = lkf_eventInstance_start(_index);
		__lkf_check_result(_r); return self;
	};
	
	static stop = function(stopmode) {
		var _r = lkf_eventInstance_stop(_index, is_undefined(stopmode) ? LKF_STOP_IMMEDIATE : stopmode);
		__lkf_check_result(_r); return self;
	};
	
	static setParameterByName = function(name, value, ignoreseekspeed) {
		var _r = lkf_eventInstance_setParameterByName(_index, name, value, is_undefined(ignoreseekspeed) ? false : ignoreseekspeed);
		__lkf_check_result(_r); return self;
	};
	
	static getParameterByName = function(name) {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 2, buffer_fixed, 1);
		var _r = lkf_eventInstance_getParameterByName(_index, name, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _value = buffer_read(_b, buffer_f32);
		var _finalvalue = buffer_read(_b, buffer_f32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { value: _value, finalvalue: _finalvalue };
	};
	
	static set3DAttributes = function(_attributes) {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 3 * 4, buffer_fixed, 1);
		_attributes.serialize(_b);
		var _r = lkf_eventInstance_set3DAttributes(_index, buffer_get_address(_b));
		if (buffer_exists(_b)) buffer_delete(_b);
		__lkf_check_result(_r); return self;
	}
	
	static get3DAttributes = function() {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 3 * 4, buffer_fixed, 1);
		var _r = lkf_eventInstance_get3DAttributes(_index, buffer_get_address(_b));
		var _3dattr = new LKF3DAttributes();
		_3dattr.deserialize(_b);
		if (buffer_exists(_b)) buffer_delete(_b);
		__lkf_check_result(_r); return _3dattr;
	}
	
	static release = function() {
		var _r = lkf_eventInstance_release(_index);
		__lkf_check_result(_r); return self; // don't unregister an instance here, it will be done in a callback.
	};
	
	static setVolume = function(volume) {
		var _r = lkf_eventInstance_setVolume(_index, volume);
		__lkf_check_result(_r); return self;
	}
	
	static getVolume = function() {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 2, buffer_fixed, 1);
		var _r = lkf_eventInstance_getVolume(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _volume = buffer_read(_b, buffer_f32);
		var _finalvolume = buffer_read(_b, buffer_f32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { volume: _volume, finalvolume: _finalvolume };
	};
	
	static setPitch = function(pitch) {
		var _r = lkf_eventInstance_setPitch(_index, pitch);
		__lkf_check_result(_r); return self;
	}
	
	static getPitch = function() {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 2, buffer_fixed, 1);
		var _r = lkf_eventInstance_getPitch(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _pitch = buffer_read(_b, buffer_f32);
		var _finalpitch = buffer_read(_b, buffer_f32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { pitch: _pitch, finalpitch: _finalpitch };
	};
	
	static triggerCue = function() {
		var _r = lkf_eventInstance_triggerCue(_index);
		__lkf_check_result(_r); return self;
	};
	
	static getPaused = function() {
		var _r = lkf_eventInstance_getPaused(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setPaused = function(paused) {
		var _r = lkf_eventInstance_setPaused(_index, paused);
		__lkf_check_result(_r); return self;
	};
	
	static setReverbLevel = function(index, level) {
		var _r = lkf_eventInstance_setReverbLevel(_index, index, level);
		__lkf_check_result(_r); return self;
	};
	
	static getReverbLevel = function(index) {
		var _r = lkf_eventInstance_getReverbLevel(_index, index);
		__lkf_check_result(_r); return _r;
	};
	
	static setTimelinePosition = function(position) {
		var _r = lkf_eventInstance_setTimelinePosition(_index, position);
		__lkf_check_result(_r); return self;
	};
	
	static getTimelinePosition = function() {
		var _r = lkf_eventInstance_getTimelinePosition(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setListenerMask = function(maskvalue) {
		var _r = lkf_eventInstance_setListenerMask(_index, maskvalue);
		__lkf_check_result(_r); return self;
	};
	
	static getListenerMask = function() {
		var _r = lkf_eventInstance_getListenerMask(_index);
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
	
	static getDescription = function() {
		var _r = lkf_eventInstance_getDescription(_index);
		__lkf_check_result(_r);
		if (ds_map_exists(global._lkf_event_descriptions_map, string(_r))) {
			return global._lkf_event_descriptions_map[? string(_r)].ref;
		}
		else {
			throw "TODO: Allocating new event description, is that intended?";
			return new LKFEventDescription(_r);
		}
	};
	
	static isVirtual = function() {
		var _r = lkf_eventInstance_isVirtual(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setUserData = function(_myuserdata) {
		_userdata = _myuserdata;
		return self;
	};
	
	static getUserData = function() {
		return _userdata;	
	};
}
