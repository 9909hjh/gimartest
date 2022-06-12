#include "Target.h"


Target::Target(int _x, int _y) : Vehicle(_x, _y), dist(30.f), distAway(0)
{
	ToOb = new Vector2D(0, 0);
}

void Target::update()
{
	Vehicle::update();
}

void Target::applyForce(Vector2D* force)
{
	Vehicle::applyForce(force);
}

Vector2D Target::Hide(Vector2D* target)
{
	distAway = (r * 3) + dist;

	*ToOb = *m_pos - *target;
	ToOb->normalize();
	*ToOb *= distAway;
	*ToOb += *m_pos;

	return *ToOb;
}

void Target::draw(SDL_Renderer* renderer)
{
	filledCircleRGBA(renderer, m_pos->getX(), m_pos->getY(), (r * 3), 100, 100, 200, 100);
}
