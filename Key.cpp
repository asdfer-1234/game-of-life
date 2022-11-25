#include "Key.hpp"

Key::Key(int keyCode): keyCode(keyCode) {}

bool Key::Update() {
	return pressed = GetAsyncKeyState(keyCode);
}

bool Key::GetKey() {
	return Update();
}

bool Key::GetKeyDown() {
	if(pressed) {
		Update();
		return false;
	}
	return GetKey();
}

bool Key::GetKeyUp() {
	if(!pressed) {
		Update();
		return false;
	}
	return !GetKey();
}