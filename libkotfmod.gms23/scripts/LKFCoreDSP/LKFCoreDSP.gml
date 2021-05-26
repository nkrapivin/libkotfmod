// [Core API] FMOD::DSP
function LKFCoreDSP(_myindex) constructor {
	_index = _myindex;
	_userdata = undefined;
	
	LKFWeakRegister(global._lkf_core_dsps_map, _index, weak_ref_create(self));
	
	static setUserData = function(_myuserdata) {
		_userdata = _myuserdata;
		return self;
	};
	
	static getUserData = function() {
		return _userdata;	
	};
	
	static release = function() {
		var _r = lkf_coreDSP_release(_index);
		__lkf_check_result(_r); LKFWeakUnregister(global._lkf_core_dsps_map, _index); return self;
	};
	
	static getSystemObject = function() {
		var _r = lkf_coreDSP_getSystemObject(_index);
		__lkf_check_result(_r);
		return global._lkf_core_systems_map[? string(_r)].ref;	
	};
	
	static setActive = function(_active) {
		var _r = lkf_coreDSP_setActive(_index, _active);
		__lkf_check_result(_r); return self;
	};
	
	static getActive = function() {
		var _r = lkf_coreDSP_getActive(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setBypass = function(_bypass) {
		var _r = lkf_coreDSP_setBypass(_index, _bypass);
		__lkf_check_result(_r); return self;
	};
	
	static getBypass = function() {
		var _r = lkf_coreDSP_getBypass(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static setWetDryMix = function(_prewet, _postwet, _dry) {
		var _r = lkf_coreDSP_setWetDryMix(_index, _prewet, _postwet, _dry);
		__lkf_check_result(_r); return self;
	};
	
	static getWetDryMix = function() {
		var _b = buffer_create(buffer_sizeof(buffer_f32) * 3, buffer_fixed, 1);
		var _r = lkf_coreDSP_getWetDryMix(_index, buffer_get_address(_b));
		__lkf_check_result(_r);
		var _prewet = buffer_read(_b, buffer_f32);
		var _postwet = buffer_read(_b, buffer_f32);
		var _dry = buffer_read(_b, buffer_f32);
		if (buffer_exists(_b)) buffer_delete(_b);
		return { prewet: _prewet, postwet: _postwet, dry: _dry };
	};
	
	static reset = function() {
		var _r = lkf_coreDSP_reset(_index);
		__lkf_check_result(_r); return self;
	};
	
	static setParameterFloat = function(_pindex, _value) {
		var _r = lkf_coreDSP_setParameterFloat(_index, _pindex, _value);
		__lkf_check_result(_r); return self;
	};
	
	static setParameterInt = function(_pindex, _value) {
		var _r = lkf_coreDSP_setParameterInt(_index, _pindex, _value);
		__lkf_check_result(_r); return self;
	};
	
	static setParameterBool = function(_pindex, _value) {
		var _r = lkf_coreDSP_setParameterBool(_index, _pindex, _value);
		__lkf_check_result(_r); return self;
	};
	
	static setParameterData = function(_pindex, _value, _size) {
		var _r = lkf_coreDSP_setParameterData(_index, _pindex, buffer_get_address(_value), _size);
		__lkf_check_result(_r); return self;
	};
	
	static getType = function() {
		var _r = lkf_coreDSP_getType(_index);
		__lkf_check_result(_r); return _r;
	};
	
	static getIdle = function() {
		var _r = lkf_coreDSP_getIdle(_index);
		__lkf_check_result(_r); return _r;
	};
}
