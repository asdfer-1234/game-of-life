#include "Renderer.hpp"
#include <iostream>

Console Renderer::console[] = {Renderer::CreateConsole(), Renderer::CreateConsole()};
bool Renderer::currentConsoleIndex = false;
const SMALL_RECT Renderer::windowInitializationStarter = {0, 0, 2, 2};
Position Renderer::matrixSize;
Pixel *Renderer::matrix;

Console& Renderer::ActiveConsole(){
	return console[currentConsoleIndex];
}

Console &Renderer::OtherConsole(){
	return console[!currentConsoleIndex];
}

COORD Renderer::PositionToCoord(Position position){
	return {(short) position.x, (short) position.y};
}

SMALL_RECT Renderer::PositionToSmallRect(Position position){
	return {0, 0, (short) (position.x - 1), (short) (position.y - 1)};
}

Console Renderer::CreateConsole(){
	return CreateConsoleScreenBuffer(
		GENERIC_READ | GENERIC_WRITE,
		0,
		NULL,
		CONSOLE_TEXTMODE_BUFFER,
		NULL);
}

void Renderer::InitializeMatrix() {
	matrix = new Pixel[matrixSize.Size()];
}

void Renderer::InitializeConsole(Console &console){
	SetConsoleWindowInfo(console, TRUE, &windowInitializationStarter);
	COORD bufferSize = PositionToCoord(matrixSize);
	SetConsoleScreenBufferSize(console, bufferSize);
	SMALL_RECT windowSize = PositionToSmallRect(matrixSize);
	SetConsoleWindowInfo(console, TRUE, &windowSize);
}

void Renderer::SetConsole(bool consoleindex){
	currentConsoleIndex = consoleindex;
	SetConsoleActiveScreenBuffer(console[currentConsoleIndex]);
}

void Renderer::SwitchConsole(){
	SetConsole(!currentConsoleIndex);
}

void Renderer::SetWritingPalette(Console& console, Palette palette){
	SetConsoleTextAttribute(console, palette.GetCode());
}

void Renderer::SetCursorPosition(Console& console, Position position){
	SetConsoleCursorPosition(console, PositionToCoord(position));
}

void Renderer::WriteCharacter(Console &console, char character)
{
	DWORD dw;
	WriteFile(console, &character, 1, &dw, NULL);
}

void Renderer::WritePixel(Console& console, Pixel pixel){
	SetWritingPalette(console, pixel.palette);
	WriteCharacter(console, pixel.character);
}

void Renderer::WritePixelInPosition(Console& console, Position position, Pixel pixel){
	SetCursorPosition(console, position);
	WritePixel(console, pixel);
}

void Renderer::Write(Console& console){
	for(int x = 0; x < matrixSize.x; x++){
		for (int y = 0; y < matrixSize.y; y++){
			WritePixelInPosition(console, Position(x, y), GetPixel(Position(x, y)));
		}
	}
}

void Renderer::SetMatrixSize(Position matrixSize)
	{
	Renderer::matrixSize = matrixSize;
	InitializeMatrix();
	for(int i = 0; i < 2; i++){
		InitializeConsole(console[i]);
	}
	SetConsoleActiveScreenBuffer(console[0]);
}

Pixel& Renderer::GetPixel(Position position){
	return matrix[matrixSize.x * position.y + position.x];
}

Pixel& Renderer::SetPixel(Position position, Pixel& pixel){
	return GetPixel(position) = pixel;
}

void Renderer::FillRectangle(Position start, Position end, Pixel &pixel){
	for(int x = start.x; x < end.x; x++){
		for (int y = start.y; y < end.y; y++){
			SetPixel(Position(x, y), pixel);
		}
	}
}

void Renderer::Update(){
	Write(OtherConsole());
	SwitchConsole();
}