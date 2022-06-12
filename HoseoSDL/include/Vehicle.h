#pragma once

#include <main.h>

#include "Vector2D.h"
#include "Game.h"
#include "InputHandler.h"

class Vehicle
{
public:
	Vehicle(int x, int y);
	void draw(SDL_Renderer* renderer);
	void update();

	Vector2D seek(Vector2D* target, bool arrival);
	Vector2D arrive(Vector2D* force);
	void applyForce(Vector2D* force);
	Vector2D Rradian(float x, float y, float radian);

protected:
	Vector2D* m_pos;
	Vector2D* m_vel;
	Vector2D* m_acc;
	Vector2D* m_force;

	float radian = 0;
	Vector2D* rdi1;
	Vector2D* rdi2;
	Vector2D* rdi3;

	Vector2D* m_target;
	Vector2D* m_prediction;
	Vector2D* DesiredVelocity;
	Vector2D* steer;

	int maxspeed;
	int r;
	float maxForce;
	float desiredspeed;

	double distance;
	const double DecelerationTweaker;
	double speed;
};