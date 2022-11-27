#include "Cursor.hpp"

Cursor::Cursor(Chunk* chunk, Position position): chunk(chunk), position(position) {}

void Cursor::Move(Position direction) {
	position += direction;
	chunk = chunk->FetchRelativeLifeNode(position.Sloped(chunkSize));
	position = position.Clamped(chunkSize);
}

void Cursor::Activate(bool state) {
	chunk->SetData(state, position, !chunk->FetchData(state, position));
}

bool Cursor::Info(bool state) {
	return chunk->FetchData(state, position);
}