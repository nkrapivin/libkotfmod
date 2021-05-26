
// an example of how callbacks work.

// PS: only use _reflection() functions if you have to :)

function my_system_callback(_cbparam) {
	// here `self` refers to the LKFSystem struct!
	var _type = _cbparam.getType();
	var _params = _cbparam.getParameters(); // may be `undefined` if not used!
	
	show_debug_message("system callback:");
	show_debug_message("my internal index=" + string(self._index)); // don't actually do this internal stuff plz
	show_debug_message("type=" + lkf_enum_system_callback_reflection(_type));
	show_debug_message("params(struct)=" + string(_params));
	
}

function my_event_callback(_cbparam) {
	// here `self` refers to the LKFEventInstance struct!
	var _type = _cbparam.getType();
	var _params = _cbparam.getParameters(); // may be `undefined` if not used!
	
	show_debug_message("event instance callback:");
	show_debug_message("my internal index=" + string(self._index)); // don't actually do this internal stuff plz
	show_debug_message("type=" + lkf_enum_event_instance_callback_reflection(_type));
	show_debug_message("params(struct)=" + string(_params));
	
}


