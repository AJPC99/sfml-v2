#pragma once


struct Position
{
	Position operator + (Position& pos) { pos.x += x; pos.y += y; return pos; }
	Position() = default;
	Position(int x, int y) { this->x = x; this->y = y; }
	int x;
	int y;
};