// a dummy GML script I use when I need to autogenerate a reflection table
// or reparse an enum
// or something else, whatever.

function ScriptTest() {
var names = @"LKF_SYSTEM_CALLBACK_PREUPDATE
LKF_SYSTEM_CALLBACK_POSTUPDATE
LKF_SYSTEM_CALLBACK_BANK_UNLOAD
LKF_SYSTEM_CALLBACK_LIVEUPDATE_CONNECTED
LKF_SYSTEM_CALLBACK_LIVEUPDATE_DISCONNECTED";

	var f = file_text_open_from_string(names), i = 0, out = "";
	var d = -2147483647;
	while (!file_text_eof(f)) {
		var line = file_text_read_string(f);
		file_text_readln(f);
		out += "\t" + "case " + line + ": return \"" + line + "\";\r\n";
		i++;
	}
	file_text_close(f);
	clipboard_set_text(out);
	game_end();
}

//call itself on game start.
ScriptTest();
