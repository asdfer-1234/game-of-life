#include "Renderer.hpp"
#include <iostream>

Console Renderer::console[] = {Console(), Console()};
bool Renderer::currentConsoleIndex = false;
Matrix Renderer::matrix = Matrix();

Console& Renderer::ActiveConsole() {
	return console[currentConsoleIndex];
}

Console& Renderer::OtherConsole() {
	return console[!currentConsoleIndex];
}

void Renderer::SetConsole(bool consoleindex) {
	currentConsoleIndex = consoleindex;
	Console::ActivateConsole(ActiveConsole());
}

void Renderer::SwitchConsole() {
	SetConsole(!currentConsoleIndex);
}

Pixel& Renderer::GetPixel(Position position) {
	return matrix.GetPixel(position);
}

Pixel& Renderer::SetPixel(Position position, const Pixel& pixel) {
	return matrix.SetPixel(position, pixel);
}

void Renderer::SetMatrixSize(Position matrixSize) {
	matrix = Matrix(matrixSize);
	for(int i = 0; i < 2; i++) {
		console[i] = Console(matrixSize);
	}
	
	Console::ActivateConsole(ActiveConsole());
}

void Renderer::FillRectangle(Position start, Position end, Pixel& pixel) {
	for(int x = start.x; x < end.x; x++) {
		for(int y = start.y; y < end.y; y++) {
			matrix.SetPixel(Position(x, y), pixel);
		}
	}
}

void Renderer::Update() {
	OtherConsole().SetMatrix(matrix);
	SwitchConsole();
}