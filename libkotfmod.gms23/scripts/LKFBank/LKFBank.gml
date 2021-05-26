// FMOD::Studio::Bank
function LKFBank(_myindex) constructor {
	_index = _myindex;
	_userdata = undefined;
	
	LKFWeakRegister(global._lkf_banks_map, _index, weak_ref_create(self));
	
	static unload = function() {
		var _r = lkf_bank_unload(_index);
		__lkf_check_result(_r); LKFWeakUnregister(global._lkf_banks_map, _index); return _r;
	};
	
	static loadSampleData = function() {
		var _r = lkf_bank_loadSampleData(_index);
		__lkf_check_result(_r); return self;
	};
	
	static unloadSampleData = function() {
		var _r = lkf_bank_unloadSampleData(_index);
		__lkf_check_result(_r); return self;
	};
	
	static getLoadingState = function() {
		var _r = lkf_bank_getLoadingState(_index);
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
