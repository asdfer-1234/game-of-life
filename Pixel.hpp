#pragma once
#include "Palette.hpp"
class Pixel {
 public:
  Palette palette;
  char character;
  Pixel();
  Pixel(char character);
  Pixel(char character, Palette palette);
};

bool operator==(const Pixel& a, const Pixel& b);
bool operator!=(const Pixel& a, const Pixel& b);