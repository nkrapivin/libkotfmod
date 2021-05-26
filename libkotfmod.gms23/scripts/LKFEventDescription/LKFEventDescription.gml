// FMOD::Studio::EventDescription
function LKFEventDescription(_myindex) constructor {
	_index = _myindex;
	_callback = undefined;
	_userdata = undefined;
	
	LKFWeakRegister(global._lkf_event_descriptions_map, _index, weak_ref_create(self));
	
	static createInstance = function() {
		var _r = lkf_eventDescription_createInstance(_index);
		if (__lkf_check_result(_r)) {
			var _inst = new LKFEventInstance(_r);
			_inst.setCallback(_callback);
			return _inst;
		}
	};
	
	static loadSampleData = function() {
		var _r = lkf_eventDescription_loadSampleData(_index);
		__lkf_check_result(_r); return self;
	};
	
	static unloadSampleData = function() {
		var _r = lkf_eventDescription_unloadSampleData(_index);
		__lkf_check_result(_r); return self;
	};
	
	static releaseAllInstances = function() {
		var _r = lkf_eventDescription_releaseAllInstances(_index);
		__lkf_check_result(_r); return self;
	};
	
	static getSampleLoadingState = function() {
		var _r = lkf_eventDescription_getSampleLoadingState(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static isSnapshot = function() {
		var _r = lkf_eventDescription_isSnapshot(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static isOneshot = function() {
		var _r = lkf_eventDescription_isOneshot(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static isStream = function() {
		var _r = lkf_eventDescription_isStream(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static is3D = function() {
		var _r = lkf_eventDescription_is3D(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static isDopplerEnabled = function() {
		var _r = lkf_eventDescription_isDopplerEnabled(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static hasCue = function() {
		var _r = lkf_eventDescription_hasCue(_index);
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
	
	static setUserData = function(_myuserdata) {
		_userdata = _myuserdata;
		return self;
	};
	
	static getUserData = function() {
		return _userdata;	
	};
}