#include "Renderer.hpp"
#include <iostream>
HANDLE Renderer::consoleBuffer[] = {CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL), CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL)};

Pixel *Renderer::matrix;
Position Renderer::matrixSize;
const SMALL_RECT Renderer::smallWindowSize = {0, 0, 2, 2};

void Renderer::InitializeMatrix() {
	matrix = new Pixel[matrixSize.Size()];
}

void Renderer::InitializeConsole(HANDLE &console){
	SetConsoleWindowInfo(console, TRUE, &smallWindowSize);
	COORD bufferSize = {(short) matrixSize.x, (short) matrixSize.y};
	SetConsoleScreenBufferSize(console, bufferSize);
	SMALL_RECT windowSize = {0, 0, (short)matrixSize.x - 1, (short) matrixSize.y - 1};
	SetConsoleWindowInfo(console, TRUE, &windowSize);
}

void Renderer::SetMatrixSize(Position matrixSize){
	
	Renderer::matrixSize = matrixSize;
	SetConsoleActiveScreenBuffer(consoleBuffer[0]);
	InitializeMatrix();
	for(int i = 0; i < 2; i++){
		InitializeConsole(consoleBuffer[i]);
	}
	
}