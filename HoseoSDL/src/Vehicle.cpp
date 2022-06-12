#include "Vehicle.h"
#include <random>
//#include <algorithm>
//#include <math.h>


Vehicle::Vehicle(int x, int y) : r(16), maxSpeed(4), maxForce(0.25f), desiredSpeed(0),
distace(0), Deceleration(1.f), speed(0), seeingDistace(0)
{
	m_pos = new Vector2D(x, y);
	m_vel = new Vector2D(0, 0);
	m_acc = new Vector2D(0, 0);
	m_force = new Vector2D(0, 0);

	rdi1 = new Vector2D(0, 0);
	rdi2 = new Vector2D(0, 0);
	rdi3 = new Vector2D(0, 0);
}

void Vehicle::update()
{
	*m_vel += *m_acc;
	*m_pos += *m_vel;
	m_vel->limit(maxSpeed);
	*m_acc *= 0;

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

Vector2D Vehicle::arrive(Vector2D* target)
{
	return seek(target);
}

Vector2D Vehicle::seek(Vector2D* target)
{
	*m_force = *target - *m_pos;
	distace = m_force->length();

	if (distace > 0)
	{
		speed = distace / (10 * Deceleration);
		speed = std::min(speed, (float)maxSpeed);

		*m_force *= speed;
		*m_force /= distace;
		*m_force -= *m_vel;

		return *m_force;
	}

	return Vector2D(0, 0);
}

void Vehicle::applyForce(Vector2D* force)
{
	*m_acc += *force;
}

void Vehicle::draw(SDL_Renderer* renderer)
{
	filledTrigonRGBA(renderer, rdi1->getX() + m_pos->getX(), rdi1->getY() + m_pos->getY(),
		rdi2->getX() + m_pos->getX(), rdi2->getY() + m_pos->getY(),
		rdi3->getX() + m_pos->getX(), rdi3->getY() + m_pos->getY(),
		255, 255, 255, 255);


}
