#pragma once
#include <Windows.h>

class Key {
private:
	bool pressed;
	bool Update();
public:
	Key(int keyCode);
	int keyCode;
	bool GetKey();
	bool GetKeyDown();
	bool GetKeyUp();
};
