#include "Input.hpp"

Key Input::right = Key(VK_RIGHT);
Key Input::left = Key(VK_LEFT);
Key Input::down = Key(VK_DOWN);
Key Input::up = Key(VK_UP);
Key Input::interact = Key(VK_RETURN);
Key Input::pause = Key(VK_SPACE);
Key Input::step = Key('F');

Position Input::GetMovement() {
	Position movement = Position::zero;
	if(Input::right.GetKeyDown()) {
		movement += Position::right;
	}
	if(Input::left.GetKeyDown()) {
		movement += Position::left;
	}
	if(Input::down.GetKeyDown()) {
		movement += Position::down;
	}
	if(Input::up.GetKeyDown()) {
		movement += Position::up;
	}
	return movement;
}