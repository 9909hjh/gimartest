#include "Walker.h"
#include <random>


Walker::Walker(int x, int y) 
{
  _x = x;
  _y = y;
}

void Walker::update() 
{
  //깃허브 테스트
}

void Walker::draw(SDL_Renderer* renderer)
{
 filledCircleColor(renderer, _x, _y, 1, 0xFFFFFF00); 
}
