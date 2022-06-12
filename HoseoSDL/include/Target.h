#pragma once
#include "Vector2D.h"
#include <iostream>

class Target : public Vector2D
{
public:
	Target(int _x, int _y, int _r) : Vector2D(_x, _y), x(_x), y(_y), r(_r) {}

	void draw(SDL_Renderer* renderer)
	{
		filledCircleRGBA(renderer, x, y, r, 100, 100, 100, 100);
	}

	int getR() {return r; }
private:
	int x, y, r;
};