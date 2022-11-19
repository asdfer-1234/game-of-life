#pragma once
#include "Console.hpp"
#include <Windows.h>

class Renderer {
private:
	static Console console[];
	static bool currentConsoleIndex;
	static Matrix matrix;
	static Console& ActiveConsole();
	static Console& OtherConsole();
	static void SetConsole(bool consoleIndex);
	static void SwitchConsole();
public:
	static Pixel& GetPixel(Position position);
	static Pixel& SetPixel(Position position, const Pixel& pixel);
	static void SetMatrixSize(Position matrixSize);
	static void FillRectangle(Position start, Position end, Pixel& pixel);
	static void Update();
};
