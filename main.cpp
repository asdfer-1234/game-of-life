#include "Renderer.hpp"
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
using namespace std;

int main() {
	Renderer::SetMatrixSize(Position(100, 100));
	for(int i = 0; i < 1000; i++) {
		for(int x = 0; x < 100; x++) {
			for(int y = 0; y < 49; y++) {
				Palette randomPalette((Color)(rand() % 16), (Color)(rand() % 16));
				char randomChar = 'b';
				Pixel randomPixel = Pixel(randomChar, randomPalette);
				Renderer::SetPixel(Position(x, y), randomPixel);
				Renderer::Update();
			}
		}
	}
	Sleep(100);
	return 0;
}