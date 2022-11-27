#pragma once
#include "Chunk.hpp"
#include "Configuration.hpp"
#include "Position.hpp"

class Cursor {
public:
	Chunk* chunk;
	Position position;
	Cursor(Chunk* chunk, Position position);
	void Move(Position direction);
	void Activate(bool state);
	bool Info(bool state);
};