#include "Pixel.hpp"

Pixel::Pixel() : Pixel(' ') {}

Pixel::Pixel(char character) : Pixel(character, Palette::basic){}

Pixel::Pixel(char character, Palette palette) : character(character), palette(palette) {}

bool operator==(const Pixel &a, const Pixel &b){
	return a.character == b.character && a.palette == b.palette;
}
bool operator!=(const Pixel &a, const Pixel &b){
	return !(a == b);
}