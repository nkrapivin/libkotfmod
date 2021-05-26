/// @description libkotfmod Core API Demo.
// aka: I am too lazy to download FMOD Studio so I'll create my sounds in code!

if (instance_exists(oStudioAPIDemo))
	throw "Two demo objects cannot coexist.";

if (!lkf_is_present() || !lkf_are_callbacks_registered()) {
	throw "Unable to properly load libkotfmod and/or FMOD.";	
}

// >:(
prefix = working_directory;
f = LKF_INIT_NORMAL;
if (os_type == os_android) {
	prefix = "file:///android_asset";
}

// Initialize the wrapper.
LKFGMLInit();
sys = new LKFCoreSystem();
// Initialize the actual system.
// (if a method returns nothing, it returns self, so you can chain void methods together!)
sys.create()
   .init(64, f);

// Load the sound.
//                                working_directory/core/jos-fck.xm
fckdaripper = sys.createSound(PathCombine(prefix, "core", "jos-fck.xm"), LKF_MODE_DEFAULT);
// imagine being able to play tracker music without ogg, crazy right?

// Create an echo DSP, just because echo is fun.
echo = sys.createDSPByType(LKF_DSP_TYPE_ECHO);
// eh fuck it, let's bash a few more effects (this won't end well, my ears will hurt)
lol = sys.createDSPByType(LKF_DSP_TYPE_CHORUS);
ohno = sys.createDSPByType(LKF_DSP_TYPE_DISTORTION);

// create our new channel group where we will apply the effects
mygroup = sys.createChannelGroup("LKFCoreGroup");

// apply the effects before playing the sound (0 index means I don't care about the priority)
// (remember, you can chain void methods together)
//mygroup
//	.addDSP(0, echo)
//	.addDSP(0, lol)
//	.addDSP(0, ohno);

// le play
chan = sys.playSound(fckdaripper, mygroup, false);

show_debug_message("end");
