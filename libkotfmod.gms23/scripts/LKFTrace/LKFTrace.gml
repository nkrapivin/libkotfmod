
/// @description printf a la gml (vewy howwible)
function LKFTrace() {
	var _fmt = string(argument[0]);
	
	var _throw_error = string_count("%T", _fmt) > 0; // %T[hrow]
	
	// get rid of the %T modifier.
	if (_throw_error) {
		_fmt = string_replace(string_replace(_fmt, "%T ", ""), " %T", "");	
	}
	
	// main format loop.
	for (var _f = 0; _f < argument_count; _f++) {
		_fmt = string_replace(_fmt, "%" + string(_f - 1), string(argument[_f]));	
	}
	
	if (_throw_error) {
		_fmt = string_insert("\n----------\nlibkotfmod [GML Exception]: ", _fmt, 1);
		throw _fmt;
	}
	else {
		_fmt = string_insert("libkotfmod [GML Trace]: ", _fmt, 1);
		show_debug_message(_fmt);
	}
}

