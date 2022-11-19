#include "Pixel.hpp"

const Pixel Pixel::blank = Pixel(' ');

Pixel::Pixel(): Pixel(' ') {}

Pixel::Pixel(char character): Pixel(character, Palette::basic) {}

Pixel::Pixel(Palette palette): Pixel(' ', palette) {}

Pixel::Pixel(char character, Palette palette): character(character), palette(palette) {}

bool Pixel::operator==(const Pixel& other) const {
	return character == other.character && palette == other.palette;
}

bool Pixel::operator!=(const Pixel& other) const {
	return !((*this) == other);
}