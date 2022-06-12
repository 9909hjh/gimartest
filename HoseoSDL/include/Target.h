#pragma once
#include "Vehicle.h"

class Target : public Vehicle
{
public:
	Target(int _x, int _y);
	virtual void draw(SDL_Renderer* renderer);
	virtual void update();
	virtual void applyForce(Vector2D* force);

	Vector2D Hide(Vector2D* target);

private:
	Vector2D* hidespot;
	Vector2D* VehPos;
	Vector2D* ToOb;

	float DistanceFormBoundary;
	float DistAway;
};
