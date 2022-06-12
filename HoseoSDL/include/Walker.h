#pragma once
#include "main.h"

#include <vector>
#include "Vehicle.h"
#include "Target.h"

#include "Vector2D.h"
#include "InputHandler.h"
#include "Game.h"

class Walker 
{
public:
  Walker();
  void draw(SDL_Renderer* renderer);
  void update();
  void mousemove();

private:
	std::vector<Vehicle*> m_Vehicle;
	std::vector<Target*> m_Target;

	Vector2D* m_mousePos;
	Vector2D* target;
	Vector2D* steer;
	Vector2D* T_steer;
};