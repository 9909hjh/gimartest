#include "Vehicle.h"
#include <algorithm>
#include <math.h>
#include <iostream>

#include <random>

Vehicle::Vehicle(int x, int y) : maxspeed(4), maxForce(0.25f), r(16), desiredspeed(0),
distance(0), DecelerationTweaker(1.0f), speed(0)
{
	m_pos = new Vector2D(x, y);
	m_vel = new Vector2D(0, 0);
	m_acc = new Vector2D(0, 0);
	m_force = new Vector2D(0, 0);

	rdi1 = new Vector2D(0, 0);
	rdi2 = new Vector2D(0, 0);
	rdi3 = new Vector2D(0, 0);

	m_target = new Vector2D(0, 0);
	m_prediction = new Vector2D(0, 0);

	DesiredVelocity = new Vector2D(0, 0);
	steer = new Vector2D(0, 0);
}

void Vehicle::update()
{
	*m_vel += *m_acc;
	m_vel->limit(maxspeed);
	*m_pos += *m_vel;
	*m_acc *= 0;

	// heading부분.
	radian = atan2(m_vel->getY(), m_vel->getX());
	*rdi1 = Rradian(-r, -r / 2, radian);
	*rdi2 = Rradian(-r, r / 2, radian);
	*rdi3 = Rradian(r, 0, radian);
}

Vector2D Vehicle::Rradian(float x, float y, float radian)
{
	Vector2D rota(0, 0);

	rota.setX(cos(radian) * x - sin(radian) * y);
	rota.setY(sin(radian) * x + cos(radian) * y);

	return rota;
}

void Vehicle::applyForce(Vector2D* force)
{
	*m_acc += *force;
}

Vector2D Vehicle::arrive(Vector2D* target)
{
	return seek(target, true);
}

Vector2D Vehicle::seek(Vector2D* target, bool arrival = false)
{
	*m_force = *target - *m_pos;
	distance = m_force->length();
	//std::cout << distance << std::endl;
	if (distance > 0)
	{
		speed = distance / (10 * DecelerationTweaker);
		speed = std::min(speed, (double)maxspeed);

		*m_force *= speed;
		*m_force /= distance;
		*m_force -= *m_vel;

		return *m_force;
	}

	return Vector2D(0, 0);
}

void Vehicle::draw(SDL_Renderer* renderer)
{
	filledTrigonRGBA(renderer,
		rdi1->getX() + m_pos->getX(), rdi1->getY() + m_pos->getY(),
		rdi2->getX() + m_pos->getX(), rdi2->getY() + m_pos->getY(),
		rdi3->getX() + m_pos->getX(), rdi3->getY() + m_pos->getY(),
		255, 255, 255, 255);
	// 더해주는게 로컬에서 글로벌로 바꾸는 작업이다.
}
