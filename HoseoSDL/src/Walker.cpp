#include "Walker.h"
#include <random>

// 시드값을 얻기 위한 random_device 생성.
std::random_device rd;

// random_device 를 통해 난수 생성 엔진을 초기화 한다.
std::mt19937 gen(rd());

// 0 부터 3까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의.
std::uniform_int_distribution<int> dis(100, 400);

Walker::Walker()
{
    m_Vehicle.push_back(new Vehicle(100, 150));
    m_Target.push_back(new Target(400, 150, 50));
}

void Walker::update()
{
    for (int i = 0; i != m_Vehicle.size(); i++)
    {
        m_Vehicle[i]->update();
        m_Vehicle[i]->avoid(m_Target[0]);
    }
}

void Walker::draw(SDL_Renderer* renderer)
{
    for (int i = 0; i != m_Vehicle.size(); i++)
    {
        m_Vehicle[i]->draw(renderer);
        m_Target[i]->draw(renderer);
    }
}
