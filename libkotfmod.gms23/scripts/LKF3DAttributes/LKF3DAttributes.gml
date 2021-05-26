
function LKF3DAttributes() constructor {
	position = new LKFVector(0, 0, 0);
	velocity = new LKFVector(0, 0, 0);
	forward = new LKFVector(0, 0, 0);
	up = new LKFVector(0, 0, 0);
	
	static serialize = function(buffer) {
		position.serialize(buffer);
		velocity.serialize(buffer);
		forward.serialize(buffer);
		up.serialize(buffer);
	};
	
	static deserialize = function(buffer) {
		position.deserialize(buffer);
		velocity.deserialize(buffer);
		forward.deserialize(buffer);
		up.deserialize(buffer);
	};
}
