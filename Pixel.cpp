#include "Pixel.hpp"

Pixel::Pixel() : Pixel(' ') {}

Pixel::Pixel(char character) : Pixel(character, Palette::basic){}

Pixel::Pixel(char character, Palette palette) : character(character), palette(palette) {}