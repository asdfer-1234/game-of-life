#include "Console.hpp"

const SMALL_RECT Console::windowInitializationStarter = {0, 0, 2, 2};

COORD Console::PositionToCoord(Position position) {
	return {(short)position.x, (short)position.y};
}

SMALL_RECT Console::PositionToSmallRect(Position position) {
	return {0, 0, (short)(position.x - 1), (short)(position.x - 1)};
}

void Console::SetPalette(Palette palette) {
	SetConsoleTextAttribute(consoleHandle, palette.GetCode());
}

void Console::MoveCursor(Position position) {
	SetConsoleCursorPosition(consoleHandle, PositionToCoord(position));
}

void Console::WriteCharacter(char character) {
	DWORD dword;
	WriteFile(consoleHandle, &character, 1, &dword, NULL);
}

void Console::WritePixel(const Pixel& pixel) {
	SetPalette(pixel.palette);
	WriteCharacter(pixel.character);
}

void Console::WritePixelInPosition(const Pixel& pixel, Position position) {
	if(pixel != GetPixel(position)) {
		MoveCursor(position);
		WritePixel(pixel);
		SetPixel(position, pixel);
	}
}

void Console::UpdateWindow() {
	SetConsoleWindowInfo(consoleHandle, TRUE, &windowInitializationStarter);
	COORD bufferSize = PositionToCoord(GetSize());
	SetConsoleScreenBufferSize(consoleHandle, bufferSize);
	SMALL_RECT windowSize = PositionToSmallRect(GetSize());
	SetConsoleWindowInfo(consoleHandle, TRUE, &windowSize);
}

Console::Console(): Console(Position::zero) {}

Console::Console(Position size): Matrix(size) {
	consoleHandle = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	UpdateWindow();
}

Console::~Console() {}

const Position& Console::SetSize(Position size) {
	Matrix::SetSize(size);
	UpdateWindow();
	return GetSize();
}

void Console::SetMatrix(const Matrix& matrix) {
	for(int x = 0; x < matrix.GetSize().x; x++) {
		for(int y = 0; y < matrix.GetSize().y; y++) {
			WritePixelInPosition(matrix.GetPixel(Position(x, y)), Position(x, y));
		}
	}
}

void Console::ActivateConsole(Console& console) {
	SetConsoleActiveScreenBuffer(console.consoleHandle);
}