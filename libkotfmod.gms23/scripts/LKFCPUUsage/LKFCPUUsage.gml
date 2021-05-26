
// FMOD_STUDIO_CPU_USAGE
function LKFCPUUsage() constructor {
	dspusage = undefined;
	streamusage = undefined;
	geometryusage = undefined;
	updateusage = undefined;
	studiousage = undefined;
	
	static getDSPUsage = function() { return dspusage; };
	static getStreamUsage = function() { return streamusage; };
	static getGeometryUsage = function() { return geometryusage; };
	static getUpdateUsage = function() { return updateusage; };
	static getStudioUsage = function() { return studiousage; };
	
	static deserialize = function(buffer) {
		dspusage = buffer_read(buffer, buffer_f32);
		streamusage = buffer_read(buffer, buffer_f32);
		geometryusage = buffer_read(buffer, buffer_f32);
		updateusage = buffer_read(buffer, buffer_f32);
		studiousage = buffer_read(buffer, buffer_f32);
	};
}
