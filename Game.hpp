#pragma once
#include "Chunk.hpp"
#include "Cursor.hpp"
#include "Renderer.hpp"
#include "Rule.hpp"
#include "Stem.hpp"

class Game {
public:
	static LifeNode* main;
	static Cursor cursor;
	static Rule const& rule;
	static bool state;
	static bool paused;
	static void Play();
	static void Step();
	static void Render();
	static void Extend();
	static void Pause();
};