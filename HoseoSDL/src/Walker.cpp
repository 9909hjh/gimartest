#include "Walker.h"
#include <random>

// �õ尪�� ��� ���� random_device ����.
std::random_device rd;

// random_device �� ���� ���� ���� ������ �ʱ�ȭ �Ѵ�.
std::mt19937 gen(rd());

// 0 ���� 3���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ����.
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
