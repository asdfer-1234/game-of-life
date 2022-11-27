#include "Chunk.hpp"
#include "Game.hpp"
#include "Rule.hpp"
#include <exception>

int Chunk::GetIndex(bool state, Position position) {
	return (state ? chunkSize * chunkSize : 0) + position.x * chunkSize + position.y;
}

bool Chunk::GetLocalData(bool state, Position position) {
	if(this == nullptr) {
		return false;
	}
	if(!position.Within(Position::zero, Position(4))) {
		throw exception("GetLocalData out of bounds");
	}
	return (this->data & (1 << GetIndex(state, position))) != 0;
}

Chunk::Chunk(): Chunk(nullptr) {}

Chunk::Chunk(Stem* parent): LifeNode(parent) {}

void Chunk::SetParent(Stem* parent) {
	this->parent = parent;
	if(parent != nullptr) {
		Step();
	}
}

Chunk::~Chunk() {}

Chunk* Chunk::FetchRelativeLifeNode(Position position, bool isChunk) {
	return dynamic_cast<Chunk*>(LifeNode::FetchRelativeLifeNode(position, isChunk));
}

Chunk* Chunk::GetRelativeLifeNode(Position position) {
	return dynamic_cast<Chunk*>(LifeNode::GetRelativeLifeNode(position));
}

void Chunk::SetLocalData(bool state, Position position, bool value) {
	if(value) {
		data |= 1 << GetIndex(state, position);
	} else {
		data &= ~(1 << GetIndex(state, position));
	}
}

bool Chunk::FetchData(bool state, Position position) {
	return FetchRelativeLifeNode(position.Sloped(chunkSize))->GetLocalData(state, position.Clamped(chunkSize));
}

bool Chunk::GetData(bool state, Position position) {
	Chunk* node = GetRelativeLifeNode(position.Sloped(chunkSize));
	if(node == nullptr) {
		return false;
	}
	return node->GetLocalData(state, position.Clamped(chunkSize));
}

void Chunk::SetData(bool state, Position position, bool value) {
	FetchRelativeLifeNode(position.Sloped(chunkSize))->SetLocalData(state, position.Clamped(chunkSize), value);

	if(value) {
		for(Position direction: Game::rule.direction) {
			Position invoker = (position - direction).Sloped(chunkSize);
			if(invoker != Position::zero) {
				if(GetRelativeLifeNode(invoker) == nullptr) {
					FetchRelativeLifeNode(invoker);
				}
			}
		}
	}
}

void Chunk::Step() {
	for(int x = 0; x < chunkSize; x++) {
		for(int y = 0; y < chunkSize; y++) {
			Position current = Position(x, y);
			int adjacent = 0;
			for(Position direction: Game::rule.direction) {
				if(GetData(!Game::state, current + direction)) {
					adjacent++;
				}
			}
			bool toTrue = Game::rule.IsToTrue(GetData(!Game::state, current), adjacent);

			SetData(Game::state, current, toTrue);
		}
	}
}