#pragma once
#include <main.h>

#include "Vector2D.h"
#include "Game.h"
#include "InputHandler.h"
#include "Target.h"

class Vehicle
{
public:
	Vehicle(int x, int y);
	void draw(SDL_Renderer* renderer);
	void update();

	Vector2D getNormalPoint(Target* p, Vector2D* a, Vector2D* v);
	void avoid(Target* obstacle);

	void applyForce(Vector2D* force);
	Vector2D goradian(float x, float y, float radian);

	void edges();

	Vector2D getPos() { return *m_pos; }
	float getR() { return r; }

protected:
	Vector2D* m_pos;
	Vector2D* m_vel;
	Vector2D* m_acc;
	Vector2D* m_force;

	float radian = 0;
	Vector2D* rdi1;
	Vector2D* rdi2;
	Vector2D* rdi3;

	//obstacle.
	Vector2D* posp;
	Vector2D* normalPoint;
	Vector2D* normal;
	float d1;
	float d2;
	Vector2D* m_end;
	Target* emtiy;
	Vector2D* m_vel2;

	float result;

	int maxSpeed;
	float maxForce;
	int r;
	float desiredSpeed;

	double distance;
	const double DecelerationTweaker;
	double speed;

	int seeingDistace;
};