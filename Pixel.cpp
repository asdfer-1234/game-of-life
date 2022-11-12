#include "Pixel.hpp"

Pixel::Pixel(char character, Palette palette){
	this->character = character;
	this->palette = palette;
}

Pixel::Pixel(char character) : Pixel(character, Palette::basic){}