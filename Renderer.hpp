#pragma once
#include "Pixel.hpp"
#include "Position.hpp"
#include <Windows.h>

typedef HANDLE Console;

class Renderer
{
private:
	static Console console[];
	static bool currentConsoleIndex;
	static const SMALL_RECT windowInitializationStarter;
	static Position matrixSize;
	static Pixel* matrix;
	static Console& ActiveConsole();
	static Console& OtherConsole();
	static COORD PositionToCoord(Position position);
	static SMALL_RECT PositionToSmallRect(Position position);
	static Console CreateConsole();
	static void InitializeMatrix();
	static void InitializeConsole(Console &console);
	static void SetConsole(bool consoleIndex);
	static void SwitchConsole();
	static void SetWritingPalette(Console& console, Palette palette);
	static void SetCursorPosition(Console &console, Position position);
	static void WriteCharacter(Console& console, char character);
	static void WritePixel(Console &console, Pixel pixel);
	static void WritePixelInPosition(Console& console, Position position, Pixel pixel);
	static void Write(Console& console);
public:
	static void SetMatrixSize(Position matrixSize);
	static Pixel& GetPixel(Position position);
	static Pixel& SetPixel(Position position, Pixel& pixel);
	static void FillRectangle(Position start, Position end, Pixel& pixel);
	static void Update();
};
