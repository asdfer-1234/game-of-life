#pragma once
#include "Color.hpp"
class Palette {
 private:
  char code;
  static const char foregroundBits;
  static const char backgroundBits;
  char Foregroundify(Color color);
  char Backgroundify(Color color);

 public:
  static const Palette basic;
  static const Palette inverted;
  Palette();
  Palette(Color foreground);
  Palette(Color foreground, Color background);
  char GetCode() const;
  Color GetForeground();
  Color GetBackground();
  void SetForeground(Color color);
  void SetBackground(Color color);
  Palette Inverted();
  bool operator==(const Palette& other) const;
  bool operator!=(const Palette& other) const;
};
