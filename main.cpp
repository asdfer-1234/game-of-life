#include <iostream>
#include "Renderer.hpp"
using namespace std;
int main(){
	Renderer::SetMatrixSize(Position(40, 40));
	Pixel redPixel = Pixel('a', Palette(Color::Red));
	Renderer::SetPixel(Position(1, 1), redPixel);
	Renderer::Update();
	
	Sleep(1000);
	return 0;
}