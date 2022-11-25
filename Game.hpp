#pragma once
#include "Chunk.hpp"
#include "Cursor.hpp"
#include "Renderer.hpp"
#include "Rule.hpp"
#include "Stem.hpp"

class Game {
private:
	LifeNode* main;
	Cursor cursor;
	Rule rule;
};