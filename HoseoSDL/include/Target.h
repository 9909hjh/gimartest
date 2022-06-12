#pragma once

#include "Vehicle.h"

class Target : public Vehicle
{
public:
	Target(int _x, int _y);
	virtual void draw(SDL_Renderer* renderer);
	virtual void update();
	virtual void applyforce(Vector2D* force);

	Vector2D Hide(Vector2D* target);

private:
	Vector2D* VecPos;
	Vector2D* hidespot;
	Vector2D* ToOb;

	float DistanceFormBoundry;
	float DistAway;
};
