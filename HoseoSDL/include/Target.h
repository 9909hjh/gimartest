#pragma once

#include "Vehicle.h"


class Target : public Vehicle
{
public:
	Target(int x, int y);
	void draw(SDL_Renderer* renderer);
	void update();
	void applyForce(Vector2D* force);

	Vector2D Hide(Vector2D* target);

private:
	Vector2D* ToOb;

	float dist;
	float distAway;
};
