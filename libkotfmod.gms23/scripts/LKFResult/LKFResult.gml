/// @function __lkf_check_result
/// @description This function is ONLY for internal use in the bindings, please don't use it.
/// @param {real} __result LKF Result Code
/// @returns {real} Returns the argument if all is fine, throws an exception if there was an error.
function __lkf_check_result(__result) {
	if (LKF_GML_CONFIG_THROW_ON_ERR) {
		// check if we lie within the error code range.
		var __r64 = int64(__result);
		if ((__r64 <= int64(LKF_ERR_MAX)) && (__r64 >= int64(LKF_ERR_INVALID_INDEX))) {
			LKFTrace("%T LKF Result is not OK, it's %0. Please investigate the callstack.", lkf_enum_result_reflection(__result));
		}
	}
	
	return true;
}
