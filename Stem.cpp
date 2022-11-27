#include "Stem.hpp"
#include "Chunk.hpp"
#include "Game.hpp"
#include <exception>

using namespace std;

LifeNode*& Stem::GetChildrenReference(Position position) {
	return children[position.x + stemCenter][position.y + stemCenter];
}

Stem::Stem() {
	for(Position i: Position::spaces) {
		ConnectChildren(i, nullptr);
	}
}

Stem::~Stem() {
	for(Position i: Position::spaces) {
		delete GetChildren(i);
	}
}

LifeNode* Stem::AddChildren(Position position, LifeNode* node) {
	return ConnectChildren(position, node);
}

LifeNode* Stem::FetchChildren(Position position, bool isChunk) {
	LifeNode* node = GetChildren(position);
	if(node == nullptr) {
		LifeNode* node;
		if(isChunk) {
			node = new Chunk();
		} else {
			node = new Stem();
		}
		return AddChildren(position, node);
	}
	return node;
}

LifeNode* Stem::GetChildren(Position position) const {
	return children[position.x + stemCenter][position.y + stemCenter];
}

LifeNode* Stem::ConnectChildren(Position position, LifeNode* lifeNode) {
	if(lifeNode != nullptr) {
		lifeNode->parent = this;
	}
	return GetChildrenReference(position) = lifeNode;
}

void Stem::Step() {
	for(Position i: Position::spaces) {
		LifeNode* current = GetChildren(i);
		if(current != nullptr) {
			current->Step();
		}
	}
}