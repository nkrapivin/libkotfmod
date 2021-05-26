
function LKFGMLInit() {
	// need this to track references.
	global._lkf_systems_map = ds_map_create();
	global._lkf_events_map = ds_map_create();
	global._lkf_event_descriptions_map = ds_map_create();
	global._lkf_banks_map = ds_map_create();
	global._lkf_core_systems_map = ds_map_create();
	global._lkf_core_channel_groups_map = ds_map_create();
	global._lkf_core_channels_map = ds_map_create();
	global._lkf_core_dsps_map = ds_map_create();
	global._lkf_last_time = get_timer();
}

function LKFGarbageCollectAll() {
	// is it time?
	if (get_timer() > (global._lkf_last_time + (1000000 * LKF_GML_GC_INTERVAL))) {
		LKFTrace("Running LKF garbage collection...");
		LKFGarbageCollect(global._lkf_systems_map);
		LKFGarbageCollect(global._lkf_events_map);
		LKFGarbageCollect(global._lkf_event_descriptions_map);
		LKFGarbageCollect(global._lkf_banks_map);
		LKFGarbageCollect(global._lkf_core_systems_map);
		LKFGarbageCollect(global._lkf_core_channel_groups_map);
		LKFGarbageCollect(global._lkf_core_channels_map);
		LKFGarbageCollect(global._lkf_core_dsps_map);
		
		// advance the last time forward.
		global._lkf_last_time = get_timer();
		LKFTrace("GC done, timer updated.");
	}
}

function LKFGarbageCollect(_map) {
	var _l = [];
	for (var _k = ds_map_find_first(_map), _v = undefined; ds_map_exists(_map, _k); _k = ds_map_find_next(_map, _k)) {
		_v = ds_map_find_value(_map, _k);
		
		if (!is_undefined(_v) && !weak_ref_alive(_v)) {
			LKFTrace("Found a weak ref that needs garbage collection. %0", _k);
			array_push(_l, _k);
		}
	}
	
	for (var _i = 0; _i < array_length(_l); _i++) {
		ds_map_delete(_map, _l[_i]);	
	}
}

function LKFWeakUnregister(_map, _index) {
	if (ds_map_exists(_map, string(_index))) {
		LKFTrace("Unregistered weak reference [%0].", _index);
		ds_map_delete(_map, string(_index));	
	}
	else {
		if (LKF_GML_CONFIG_THROW_ON_ERR) {
			throw "Possible duplicate of an LKF struct tried to unregister the same index twice.";	
		}
	}
}

function LKFWeakExists(_map, _index) {
	if (ds_map_exists(_map, string(_index))) {
		if (!weak_ref_alive(_map[? string(_index)])) {
			var _dbgstack = debug_get_callstack();
			LKFTrace("Tried to check if an index exists, it does, but weak ref isn't. [%0,%1]", _index, _dbgstack[1]);
			LKFWeakUnregister(_map, _index);
			return false;
		}
		
		return true;
	}
	else {
		return false;	
	}
}

function LKFWeakRegister(_map, _index, _thing) {
	if (!LKFWeakExists(_map, _index)) {
		var _dbgstack = debug_get_callstack();
		LKFTrace("Function %0 has registered a new weak ref!", _dbgstack[1]);
		ds_map_add(_map, string(_index), _thing);
	}
	else {
		// should we throw or not? there is an active weak ref!
		if (LKF_GML_CONFIG_THROW_ON_ERR) {
			throw "Possible duplicate of an LKF struct detected.";	
		}
	}
}




/// @function LKFCallbackDispatch([__map])
function LKFCallbackDispatch() {
	var _map = argument_count ? argument[0] : async_load; // take that! :|
	LKFTrace("Callback ds map: %0, %1", _map, async_load == _map);
	var _event_type = string(_map[? "event_type"]); // in case it's undefined, it will be "<undefined>"
	var _c_type = _map[? "lkf_type"];
	var _parammap = _map[? "lkf_parametersDsMap"];
	var _leindex = undefined, _letype = undefined, _leref = undefined, _leparam = undefined;
	
	switch (_event_type) {
		case "lkf_core_system_callback": {
			_leindex = _map[? "lkf_systemIndex"];
			if (LKFWeakExists(global._lkf_core_systems_map, _leindex)) {
				_leref = global._lkf_core_systems_map[? string(_leindex)];
				if (!is_undefined(_leref.ref.getCallback())) {
					switch (_c_type) {
						case LKF_SYSTEM_CALLBACK_DEVICEREINITIALIZE: {
							_leparam = { output_type: _parammap[? "output_type"], driver_index: _parammap[? "driver_index"] };
							break;	
						}
						case LKF_SYSTEM_CALLBACK_MEMORYALLOCATIONFAILED: {
							_leparam = { file: _parammap[? "file"], line: _parammap[? "line"] };
							break;
						}
						case LKF_SYSTEM_CALLBACK_ERROR: {
							_leparam = {
								result: _parammap[? "lkf_result"],
								instancetype: _parammap[? "instancetype"],
								instance: _parammap[? "instance"],
								functionname: _parammap[? "functionname"],
								functionparams: _parammap[? "functionparams"]
							};
							break;	
						}
					}
					// execute the thing
					_leparam = new LKFCallbackParameters(_c_type, _leparam);
					var _cb = _leref.ref.getCallback();
					_cb(_leparam);
				}
			}
			else {
				//LKFTrace("wtf? callback on a dead system weakref? [%0].", _leindex);	
			}
			
			break;
		}
		case "lkf_core_channel_control_callback": {
			_leindex = _map[? "lkf_controlIndex"];	
			_letype = _map[? "lkf_controlType"];
			switch (_letype) {
				case LKF_CHANNELCONTROL_CHANNEL: {
					_leref = global._lkf_core_channels_map[? string(_leindex)];
					break;
				}
				
				case LKF_CHANNELCONTROL_CHANNELGROUP: {
					_leref = global._lkf_core_channel_groups_map[? string(_leindex)];
					break;
				}
				
				default: {
					LKFTrace("%T Invalid ChannelControl type! %0", _letype);
					break;	
				};
			}
			
			if (weak_ref_alive(_leref)) {
				if (!is_undefined(_leref.ref.getCallback())) {
					switch (_c_type) {
						case LKF_CHANNELCONTROL_CALLBACK_VIRTUALVOICE: {
							_leparam = { mode: _parammap[? "mode"] };
							break;
						}
						
						case LKF_CHANNELCONTROL_CALLBACK_SYNCPOINT: {
							_leparam = { syncpoint_index: _parammap[? "syncpoint_index"] };
							break;
						}
						
						case LKF_CHANNELCONTROL_CALLBACK_OCCLUSION: {
							_leparam = { direct_occlusion: _parammap[? "direct_occlusion"], reverb_occlusion: _parammap[? "reverb_occlusion"] };
							break;
						}
					}
					// execute the thing
					_leparam = new LKFCallbackParameters(_c_type, _leparam);
					var _cb = _leref.ref.getCallback();
					_cb(_leparam);
				}
				
				if (_c_type == LKF_CHANNELCONTROL_CALLBACK_END) {
					LKFTrace("going to unregister core sound channel %0.", _leindex);
					LKFWeakUnregister(global._lkf_core_channels_map, _leindex);
				}
			}
			else {
				LKFTrace("wtf? callback on a dead weakref? %0.", _leindex);	
			}
			
			break;
		}
		
		case "lkf_studio_system_callback": {
			_leindex = _map[? "lkf_systemIndex"];
			if (LKFWeakExists(global._lkf_systems_map, _leindex)) {
				_leref = global._lkf_systems_map[? string(_leindex)];
				if (!is_undefined(_leref.ref.getCallback())) {
					// handle system parameters here. for example index->struct etc.
					switch (_c_type) {
						case LKF_SYSTEM_CALLBACK_BANK_UNLOAD: {
							_leparam = { bank: global._lkf_banks_map[? _parammap[? "bank"]] };
							if (is_undefined(_leparam.bank)) {
								LKFTrace("%T bank bullshit uh oh. (bank=%0)", _parammap[? "bank"]);
							}
							break;
						}
					}
					// execute the thing
					_leparam = new LKFCallbackParameters(_c_type, _leparam);
					var _cb = _leref.ref.getCallback();
					_cb(_leparam);
				}
			
				if (_c_type == LKF_SYSTEM_CALLBACK_BANK_UNLOAD) {
					// need to unregister the bank here.
					LKFTrace("going to unregister a bank %0.", _parammap[? "bank"]);
					LKFWeakUnregister(global._lkf_banks_map, _parammap[? "bank"]);
				}
			}
			
			break;
		}
		
		case "lkf_studio_event_callback": {
			_leindex = _map[? "lkf_eventInstanceIndex"];
			if (LKFWeakExists(global._lkf_events_map, _leindex)) {
				_leref = global._lkf_events_map[? string(_leindex)];
				if (!is_undefined(_leref.ref.getCallback())) {
					switch (_c_type) {
						// handle event instance parameters here. again.
						case LKF_EVENT_CALLBACK_START_EVENT_COMMAND: {
							LKFTrace("Allocating a new event instance from a callback.");
							_leparam = { eventInstance: new LKFEventInstance(_parammap[? "eventInstance"]) };
							_leparam.eventInstance.setCallback(_leparam.eventInstance.getDescription().getCallback());
							break;
						}
					}
					// execute the thing
					_leparam = new LKFCallbackParameters(_c_type, _leparam);
					var _cb = _leref.ref.getCallback();
					_cb(_leparam);
				}
			}
			
			// need to unregister an event here!
			if (_c_type == LKF_EVENT_CALLBACK_DESTROYED) {
				// don't call .release() because an instance *should* be already released
				// and the index is invalid anyway

				// idk why
				if (LKFWeakExists(global._lkf_events_map, _leindex)) {
					LKFTrace("going to unregister an instance event %0.", _leindex);
					LKFWeakUnregister(global._lkf_events_map, _leindex);
				}
			}
			
			break;
		}
		
		default: {
			if (LKF_GML_CONFIG_THROW_ON_ERR) {
				throw "Invalid event_type in an LKF callback! event_type=" + _event_type;	
			}
			
			break;	
		}
	}
	
	if (_parammap > -1) {
		ds_map_destroy(_parammap);
	}
}

