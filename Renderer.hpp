#pragma once
#include "Pixel.hpp"
#include "Position.hpp"
#include <Windows.h>
class Renderer
{
private:
	static const SMALL_RECT smallWindowSize;
	static HANDLE consoleBuffer[];
	static Pixel* matrix;
	static void InitializeMatrix();
	static void InitializeConsole(HANDLE& console);
	static Position matrixSize;
public:
	static void SetMatrixSize(Position matrixSize);
};

