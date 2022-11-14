#include <iostream>
#include "Renderer.hpp"
#include <random>
using namespace std;


int main(){
	Renderer::SetMatrixSize(Position(100, 50));
	
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> xDistribution(0, 99);
	uniform_int_distribution<int> yDistribution(0, 49);
	uniform_int_distribution<int> colorDistribution(0, 15);
	uniform_int_distribution<int> charDistribution(33, 126);
	for(int i = 0; i < 1000; i++){
		for (int j = 0; j < 100; j++)
		{
			Position randomPosition(xDistribution(gen), yDistribution(gen));
			Palette randomPalette((Color)colorDistribution(gen), (Color)colorDistribution(gen));
			char randomChar = charDistribution(gen);
			Pixel randomPixel = Pixel(randomChar, randomPalette);
			Renderer::SetPixel(randomPosition, randomPixel);
		}
		Renderer::Update();
		
	}
	Sleep(100);

	return 0;
}