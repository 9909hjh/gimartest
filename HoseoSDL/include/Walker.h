#pragma once

#include <main.h>
#include "Game.h"
#include "InputHandler.h"
#include "Target.h"
#include "Vector2D.h"
#include "Vehicle.h"
#include <vector>


class Walker
{
public:
	Walker();
	void draw(SDL_Renderer* renderer);
	void update();

private:
	std::vector<Vehicle*> m_Vehicle;
	std::vector<Target*> m_Target;
	Vector2D* steering;
	Vector2D* T_steering;
	Vector2D* m_mouse;
};
