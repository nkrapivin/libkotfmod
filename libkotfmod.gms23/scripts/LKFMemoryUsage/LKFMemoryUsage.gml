
// FMOD_STUDIO_MEMORY_USAGE
function LKFMemoryUsage() constructor {
	exclusive = undefined;
	inclusive = undefined;
	sampledata = undefined;
	
	static getExclusiveUsage = function() { return exclusive; };
	static getInclusiveUsage = function() { return inclusive; };
	static getSampleDataUsage = function() { return sampledata; };
	
	static deserialize = function(buffer) {
		exclusive = buffer_read(buffer, buffer_s32);
		inclusive = buffer_read(buffer, buffer_s32);
		sampledata = buffer_read(buffer, buffer_s32);
	};
}
