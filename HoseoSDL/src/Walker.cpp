#include "Walker.h"
#include <random>


Walker::Walker() 
{
	m_Vehicle.push_back(new Vehicle(100, 100));
	m_Target.push_back(new Target(300, 300));

	m_mousePos = new Vector2D(0, 0);
	target = new Vector2D(0, 0);
	steer = new Vector2D(0, 0);
	T_steer = new Vector2D(0, 0);
}

void Walker::mousemove()
{
	m_mousePos = InputHandler::Instance()->getMousePosition();
}

void Walker::update() 
{
	mousemove();

	for (int i = 0; i != m_Vehicle.size(); i++)
	{
		m_Vehicle[i]->update();
		m_Target[i]->update();

		*T_steer = m_Target[i]->Hide(m_mousePos);
		*steer = m_Vehicle[i]->arrive(T_steer);

		m_Vehicle[i]->applyForce(steer);
	}
}

void Walker::draw(SDL_Renderer* renderer)
{
	filledCircleColor(renderer, m_mousePos->getX(), m_mousePos->getY(), 10, 0xFFFFFF00);

	for (int i = 0; i != m_Vehicle.size(); i++)
	{
		m_Vehicle[i]->draw(renderer);
		m_Target[i]->draw(renderer);
	}
}
