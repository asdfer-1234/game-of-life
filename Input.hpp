#pragma once
#include "Key.hpp"
#include "Position.hpp"

class Input {
private:
	static Key right;
	static Key left;
	static Key down;
	static Key up;
	static Key interact;
	static Key pause;
	static Key step;
public:
	static Position GetMovement();
};
