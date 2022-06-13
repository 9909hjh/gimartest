#include "Vehicle.h"
#include <random>

Vehicle::Vehicle()
{

}

void Vehicle::update()
{


}

Vector2D Vehicle::seek(Vector2D* target)
{
	*m_force = *m_pos - *target;
	distance = m_force->length();

	if (distance > 0)
	{
		speed = distance / (10 * dec);
		speed = std::min(speed, (float)maxSpeed);

		*m_force *= speed;
		*m_force /= distance;
		*m_force -= *m_vel;

		return *m_force;
	}

	return Vector2D(0, 0);
}

void Vehicle::draw(SDL_Renderer* renderer)
{

}
