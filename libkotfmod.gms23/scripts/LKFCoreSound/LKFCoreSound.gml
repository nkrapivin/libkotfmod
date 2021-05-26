// [Core API] FMOD::Sound
function LKFCoreSound(_myindex) constructor {
	_index = _myindex;
	_userdata = undefined;
	
	static setUserData = function(_myuserdata) {
		_userdata = _myuserdata;
		return self;
	};
	
	static getUserData = function() {
		return _userdata;	
	};
	
	static setDefaults = function(_freq, _prio) {
		var _r = lkf_coreSound_setDefaults(_index, _freq, _prio);
		__lkf_check_result(_r); return self;
	};
	
	static getDefaults = function() {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 2, buffer_fixed, 1);
		var _r = lkf_coreSound_getDefaults(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _frequency = buffer_read(_b, buffer_f32);
		var _priority = buffer_read(_b, buffer_s32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { frequency: _frequency, priority: _priority };
	};
	
	static set3DMinMaxDistance = function(_min, _max) {
		var _r = lkf_coreSound_set3DMinMaxDistance(_index, _min, _max);
		__lkf_check_result(_r); return self;
	};
	
	static get3DMinMaxDistance = function() {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 2, buffer_fixed, 1);
		var _r = lkf_coreSound_get3DMinMaxDistance(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _min = buffer_read(_b, buffer_f32);
		var _max = buffer_read(_b, buffer_f32);
		if (buffer_exists(_b)) buffer_delete(_b);
		// min() and max() are functions :p
		return { mind: _min, maxd: _max };
	};
	
	static set3DConeSettings = function(_insideconeangle, _outsideconeangle, _outsidevolume) {
		var _r = lkf_coreSound_set3DConeSettings(_index, _insideconeangle, _outsideconeangle, _outsidevolume);
		__lkf_check_result(_r); return self;
	};
	
	static get3DConeSettings = function() {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 3, buffer_fixed, 1);
		var _r = lkf_coreSound_get3DConeSettings(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _insideconeangle = buffer_read(_b, buffer_f32);
		var _outsideconeangle = buffer_read(_b, buffer_f32);
		var _outsidevolume = buffer_read(_b, buffer_f32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { insideconeangle: _insideconeangle, outsideconeangle: _outsideconeangle, outsidevolume: _outsidevolume };
	};
}
