
function LKFCallbackParameters(_type, _parameters) constructor {
	type = _type;
	parameters = _parameters;
	
	static getType = function() {
		return type;	
	};
	
	static getParameters = function() {
		return parameters;	
	};
}
