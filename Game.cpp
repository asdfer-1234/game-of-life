#include "Game.hpp"
#include "Input.hpp"
#include "Stem.hpp"

LifeNode* Game::main = new Chunk();
Cursor Game::cursor = Cursor(dynamic_cast<Chunk*>(main), Position::zero);
Rule const& Game::rule = Rule::life;
bool Game::state = false;
bool Game::paused = true;

void Game::Step() {
	state = !state;
	main->Step();
}

void Game::Extend() {
	Stem* stem = new Stem();
	stem->ConnectChildren(Position::zero, main);
	main = stem;
}

void Game::Play() {
	Renderer::SetMatrixSize(Position(100, 100));
	while(true) {
		cursor.Move(Input::GetMovement());

		if(Input::pause.GetKeyDown()) {
			paused = !paused;
		}

		if(Input::interact.GetKeyDown()) {
			cursor.Activate(state);
		}

		if(paused) {
			if (Input::step.GetKeyDown()) {
				Step();
			}
		}
		else {
			Step();
		}

		Game::Render();
	}
}

void Game::Render() {
	for(int x = 0; x < Renderer::GetSize().x; x++) {
		for(int y = 0; y < Renderer::GetSize().y; y++) {
			Position current = Position(x, y);

			Pixel pixel = Game::cursor.chunk->GetData(state, current - Renderer::GetSize() / 2 + cursor.position) ? Pixel('+', Palette(Color::Red)) : Pixel('.', Palette(Color::Blue));
			if(current == Renderer::GetSize() / 2) {
				pixel.palette = pixel.palette.Inverted();
			}
			Renderer::SetPixel(current, pixel);
		}
	}
	Renderer::Update();
}

void Game::Pause() {}