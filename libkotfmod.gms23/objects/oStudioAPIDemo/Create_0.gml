/// @description libkotfmod Studio API Demo.

if (instance_exists(oCoreAPIDemo))
	throw "Two demo objects cannot coexist.";

// *sigh*
if (!lkf_is_present() || !lkf_are_callbacks_registered()) {
	throw "Unable to properly load libkotfmod and/or FMOD.";	
}

// >:(
prefix = working_directory;
f = LKF_STUDIO_INIT_NORMAL;
if (os_type == os_android) {
	prefix = "file:///android_asset";
	
	// android thread safety is broken for now (or not?)
	//f = f|LKF_STUDIO_INIT_SYNCHRONOUS_UPDATE;
}
else {
	// but hey, at least you get liveupdate on desktop.
	f = f|LKF_STUDIO_INIT_LIVEUPDATE;	
}

// Initialize the wrapper.
LKFGMLInit();
sys = new LKFSystem();
// Initialize the actual system.
// (if a method returns nothing, it returns self, so you can chain void methods together!)
sys.create()
   .initialize(64, f, LKF_INIT_NORMAL);
   
// get the core system just in case we'll need to set some advanced parameters.
coreSys = sys.getCoreSystem();
// TODO: set something here?
// (don't you dare release() the core system without releasing the above-level studio system)
   
// Load the banks (vewy impowtant OwO)
masterBank = sys.loadBankFile(PathCombine(prefix, "master.bank"), LKF_LOAD_BANK_NORMAL);
masterStringsBank = sys.loadBankFile(PathCombine(prefix, "master.strings.bank"), LKF_LOAD_BANK_NORMAL);

// Get the (one and only) event... you can store them in an array idfk lol
sampleEvent = sys.getEvent("event:/SampleEvent");



