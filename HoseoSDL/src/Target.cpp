#include "Target.h"

Target::Target(int _x, int _y) : Vehicle(_x, _y), DistanceFormBoundry(30.f), DistAway()
{
	VecPos = new Vector2D(0, 0);
	hidespot = new Vector2D(0, 0);
	ToOb = new Vector2D(0, 0);
}

void Target::update()
{
	Vehicle::update();
}

void Target::applyforce(Vector2D* force)
{
	Target::applyForce(force);
}

Vector2D Target::Hide(Vector2D* target)
{
	*VecPos = *target;
	*hidespot = *VecPos;

	DistAway = (r * 3) + DistanceFormBoundry;
	*ToOb = *m_pos - *target;

	ToOb->normalize();
	*ToOb *= DistAway;

	*ToOb += *m_pos;

	return *ToOb;
}

void Target::draw(SDL_Renderer* renderer)
{
	filledCircleRGBA(renderer, m_pos->getX(), m_pos->getY(), (r * 3), 100, 100, 100, 100);

}
