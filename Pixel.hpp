#pragma once
#include "Palette.hpp"

class Pixel {
public:
	static const Pixel blank;
	Palette palette;
	char character;
	Pixel();
	Pixel(char character);
	Pixel(Palette palette);
	Pixel(char character, Palette palette);
	bool operator==(const Pixel& other) const;
	bool operator!=(const Pixel& other) const;
};
