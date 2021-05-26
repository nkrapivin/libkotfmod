/// @function PathCombine([...])
/// @description like Path.Combine in C#.
/// @returns {string} final path
function PathCombine() {
	for (var _i = 0, _s = ""; _i < argument_count; ++_i) {
		_s += string(argument[_i]);
		if (_i < argument_count - 1) _s += (os_type == os_windows) ? @"\" : "/";
	}
	show_debug_message("PathCombine(): " + _s);
	return _s;
}
