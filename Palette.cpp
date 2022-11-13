#include "Palette.hpp"

const char Palette::foregroundBits = 0x0F;
const char Palette::backgroundBits = 0xF0;

const Palette Palette::basic = Palette();
const Palette Palette::inverted = Palette().Inverted();

char Palette::Foregroundify(Color color){
	return (char) color;
}

char Palette::Backgroundify(Color color){
	return ((char) color) << 4;
}

Palette::Palette() : Palette(Color::LightGray){}
Palette::Palette(Color foreground) : Palette(foreground, Color::Black){}
Palette::Palette(Color foreground, Color background){
	SetForeground(foreground);
	SetBackground(background);
}

char Palette::GetCode(){
	return code;
}

Color Palette::GetForeground(){
	return (Color)(code & foregroundBits);
}

Color Palette::GetBackground(){
	return (Color)((code & backgroundBits) >> 4);
}

Color Palette::SetForeground(Color color){
	code &= ~foregroundBits;
	code |= Foregroundify(color);
}

Color Palette::SetBackground(Color color){
	code &= ~backgroundBits;
	code |= Backgroundify(color);
}

Palette Palette::Inverted(){
	return Palette(GetBackground(), GetForeground());
}