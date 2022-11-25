#include "Input.hpp"
#include "Renderer.hpp"
#include <cstdlib>
#include <iostream>
#include <random>
#include <string>
using namespace std;

int main() {
	Renderer::SetMatrixSize(Position(100, 100));
	Position playerPosition = Position::zero;
	while(true) {
		playerPosition += Input::GetMovement();

		Renderer::SetPixel(playerPosition, Pixel('a'));

		Renderer::Update();
	}
	Sleep(100);

	return 0;
}

//TODO: life Rendering
//TODO: editing
//TODO: rule ui
//TODO: node expansion
//TODO: pause
//TODO: frame skip
//TODO: Input Movement
//TODO: frame step
//TODO: game-lifenode integration