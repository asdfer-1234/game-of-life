#pragma once
#include "Chunk.hpp"
#include "Cursor.hpp"
#include "Renderer.hpp"
#include "Rule.hpp"
#include "Stem.hpp"

class Game {
private:
	static LifeNode* main;
	static Cursor cursor;
	static Rule rule;
	static bool state;
public:
	static void Step();

	static void Render();
};