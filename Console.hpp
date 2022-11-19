#pragma once
#include "Matrix.hpp"
#include <Windows.h>

class Console: public Matrix {
private:
	HANDLE consoleHandle;
	static const SMALL_RECT windowInitializationStarter;
	static COORD PositionToCoord(Position position);
	static SMALL_RECT PositionToSmallRect(Position position);
	void SetPalette(Palette palette);
	void MoveCursor(Position position);
	void WriteCharacter(char character);
	void WritePixel(const Pixel& pixel);
	void WritePixelInPosition(const Pixel& pixel, Position position);
	void UpdateWindow();
public:
	Console();
	Console(Position size);
	virtual ~Console();
	virtual const Position& SetSize(Position size);
	void SetMatrix(const Matrix& matrix);
	static void ActivateConsole(Console& console);
};