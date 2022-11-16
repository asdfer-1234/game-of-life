#include "Renderer.hpp"

#include <iostream>

Console Renderer::console[] = {Renderer::CreateConsole(),
                               Renderer::CreateConsole()};
bool Renderer::currentConsoleIndex = false;
const SMALL_RECT Renderer::windowInitializationStarter = {0, 0, 2, 2};
Position Renderer::matrixSize;
Pixel* Renderer::matrix = nullptr;
Pixel* Renderer::renderedMatrix = {nullptr, nullptr};

Pixel& Renderer::GetPixel(Pixel*& matrix, Position position) {
  return matrix[position.y * matrixSize.x + position.x];
}
Pixel& Renderer::SetPixel(Pixel*& matrix, Position position, Pixel& pixel) {
  return GetPixel(matrix, position) = pixel;
}

Console& Renderer::ActiveConsole() { return console[currentConsoleIndex]; }

Console& Renderer::OtherConsole() { 3 return console[!currentConsoleIndex]; }

void Renderer::DeleteMatrix() {
  delete[] matrix;
  delete[] renderedMatrix;
  matrix = nullptr;
  renderedMatrix = nullptr;
}

COORD Renderer::PositionToCoord(Position position) {
  return {(short)position.x, (short)position.y};
}

SMALL_RECT Renderer::PositionToSmallRect(Position position) {
  return {0, 0, (short)(position.x - 1), (short)(position.y - 1)};
}

Console Renderer::CreateConsole() {
  return CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL,
                                   CONSOLE_TEXTMODE_BUFFER, NULL);
}

void Renderer::InitializeMatrix(Pixel*& matrix) {
  matrix = new Pixel[matrixSize.Size()];
}

void Renderer::InitializeConsole(Console& console) {
  DeleteMatrix();
  SetConsoleWindowInfo(console, TRUE, &windowInitializationStarter);
  COORD bufferSize = PositionToCoord(matrixSize);
  SetConsoleScreenBufferSize(console, bufferSize);
  SMALL_RECT windowSize = PositionToSmallRect(matrixSize);
  SetConsoleWindowInfo(console, TRUE, &windowSize);
  InitializeMatrix(matrix);
  InitializeMatrix(renderedMatrix);
}

void Renderer::SetConsole(bool consoleindex) {
  currentConsoleIndex = consoleindex;
  SetConsoleActiveScreenBuffer(console[currentConsoleIndex]);
}

void Renderer::SwitchConsole() { SetConsole(!currentConsoleIndex); }

void Renderer::SetWritingPalette(Console& console, Palette palette) {
  SetConsoleTextAttribute(console, palette.GetCode());
}

void Renderer::SetCursorPosition(Console& console, Position position) {
  SetConsoleCursorPosition(console, PositionToCoord(position));
}

void Renderer::WriteCharacter(Console& console, char character) {
  DWORD dw;
  WriteFile(console, &character, 1, &dw, NULL);
}

void Renderer::WritePixel(Console& console, Pixel pixel) {
  SetWritingPalette(console, pixel.palette);
  WriteCharacter(console, pixel.character);
}

void Renderer::WritePixelInPosition(Console& console, Position position,
                                    Pixel& pixel) {
  if (GetPixel(matrix, position) != GetPixel(renderedMatrix, position)) {
    SetCursorPosition(console, position);
    WritePixel(console, pixel);
    SetPixel(renderedMatrix, position, pixel);
  }
}

void Renderer::Write(Console& console) {
  for (int x = 0; x < matrixSize.x; x++) {
    for (int y = 0; y < matrixSize.y; y++) {
      WritePixelInPosition(console, Position(x, y), GetPixel(Position(x, y)));
    }
  }
}

Pixel& Renderer::GetPixel(Position position) {
  return GetPixel(matrix, position);
}

Pixel& Renderer::SetPixel(Position position, Pixel& pixel) {
  return SetPixel(matrix, position, pixel);
}

void Renderer::SetMatrixSize(Position matrixSize) {
  Renderer::matrixSize = matrixSize;

  for (int i = 0; i < 2; i++) {
    InitializeConsole(console[i]);
  }
  SetConsoleActiveScreenBuffer(console[0]);
}

void Renderer::FillRectangle(Position start, Position end, Pixel& pixel) {
  for (int x = start.x; x < end.x; x++) {
    for (int y = start.y; y < end.y; y++) {
      SetPixel(Position(x, y), pixel);
    }
  }
}

void Renderer::Update() {
  Write(OtherConsole());
  SwitchConsole();
}