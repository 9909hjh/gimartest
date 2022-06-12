#include "Target.h"

Target::Target(int _x, int _y) : Vehicle(_x, _y), DistanceFormBoundary(30.f), DistAway(0)
{
	VehPos = new Vector2D(0, 0);
	hidespot = new Vector2D(0, 0);
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
	*VehPos = *target;
	*hidespot = *VehPos;

	DistAway = (r * 3) + DistanceFormBoundary;
	*ToOb = *m_pos - *target;
	ToOb->normalize();

	*ToOb *= DistAway;
	*ToOb += *m_pos;

	return *ToOb;
}

void Target::draw(SDL_Renderer* renderer)
{
	filledCircleRGBA(renderer, m_pos->getX(), m_pos->getY(), (r * 3), 100, 100, 100, 100);

	lineRGBA(renderer, m_pos->getX(), m_pos->getY(), VehPos->getX(), VehPos->getY(), 100, 100, 100, 100);
	lineRGBA(renderer, m_pos->getX(), m_pos->getY(), ToOb->getX(), ToOb->getY(), 100, 100, 100, 100);

	circleRGBA(renderer, ToOb->getX(), ToOb->getY(), r / 2, 200, 100, 100, 100);
}