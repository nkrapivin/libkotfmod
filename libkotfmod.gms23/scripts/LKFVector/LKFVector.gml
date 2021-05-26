
function LKFVector(_x, _y, _z) constructor {
	x = is_undefined(_x) ? 0 : _x;
	y = is_undefined(_y) ? 0 : _y;
	z = is_undefined(_z) ? 0 : _z;
	
	static serialize = function(buffer) {
		buffer_write(buffer, buffer_f32, x);
		buffer_write(buffer, buffer_f32, y);
		buffer_write(buffer, buffer_f32, z);
	};
	
	static deserialize = function(buffer) {
		x = buffer_read(buffer, buffer_f32);
		y = buffer_read(buffer, buffer_f32);
		z = buffer_read(buffer, buffer_f32);
	};
}
