#include "Chunk.hpp"
#include "Rule.hpp"

int Chunk::GetIndex(bool state, Position position) {
	return (state ? chunkSize * chunkSize : 0) + position.x * chunkSize + position.y;
}

Chunk& Chunk::GetRelativeLifeNode(Position position) const {
	return dynamic_cast<Chunk&>(LifeNode::GetRelativeLifeNode(position));
}

bool Chunk::GetLocalData(bool state, Position position) {
	return (this->data & (1 << GetIndex(state, position))) != 0;
}

void Chunk::SetLocalData(bool state, Position position, bool value) {
	if(value) {
		data |= 1 << GetIndex(state, position);
	} else {
		data &= ~(1 << GetIndex(state, position));
	}
}

bool Chunk::GetData(bool state, Position position) {
	return GetRelativeLifeNode(position / chunkSize).GetLocalData(state, position % chunkSize);
}

void Chunk::SetData(bool state, Position position, bool value) {
	GetRelativeLifeNode(position / chunkSize).SetLocalData(state, position % chunkSize, value);
}

void Chunk::Step(bool state, Rule rule) {
	for(int x = 0; x < chunkSize; x++) {
		for(int y = 0; y < chunkSize; y++) {
			Position current = Position(x, y);
			int adjacent = 0;
			for(Position direction: Position::directions) {
				if(GetData(state, current + direction)) {
					adjacent++;
				}
			}
			SetData(!state, current, rule.IsToTrue(GetData(state, current), adjacent));
		}
	}
}

Chunk& Chunk::operator=(const Chunk& other) {
	LifeNode::operator=(other);
	data = other.data;
	return *this;
}
