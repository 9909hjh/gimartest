#pragma once

#include <main.h>
#include "InputHandler.h"
#include "Vector2D.h"
#include "Game.h"

#include "Vehicle.h"
#include "Target.h"
#include <vector>
#include <iostream>

class Walker
{
public:
	Walker();
	void draw(SDL_Renderer* renderer);
	void update();

private:
	std::vector<Vehicle*> m_Vehicle;
	std::vector<Target*> m_Target;
	Vector2D* m_mousePos;
	Vector2D* target;
	Vector2D* steering;
	Vector2D* T_steering;
};
