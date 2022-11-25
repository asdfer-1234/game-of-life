#include "Cursor.hpp"

void Cursor::Move(Position direction) {
	position += direction;
	chunk = dynamic_cast<Chunk&>(chunk.GetRelativeLifeNode(position / chunkSize));
	position %= chunkSize;
}