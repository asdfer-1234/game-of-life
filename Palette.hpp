#pragma once
#include "Color.hpp"

class Palette {
private:
	unsigned char code;
	static const unsigned char foregroundBits;
	static const unsigned char backgroundBits;
	char Foregroundify(Color color);
	char Backgroundify(Color color);
public:
	static const Palette basic;
	static const Palette inverted;
	Palette();
	Palette(Color foreground);
	Palette(Color foreground, Color background);
	unsigned char GetCode() const;
	Color GetForeground();
	Color GetBackground();
	void SetForeground(Color color);
	void SetBackground(Color color);
	Palette Inverted();
	bool operator==(const Palette& other) const;
	bool operator!=(const Palette& other) const;
};
