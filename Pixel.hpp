#pragma once
#include "Palette.hpp"
class Pixel
{
public:
	Palette palette;
	char character;
	Pixel(char character, Palette palette);
	Pixel(char character);
};

