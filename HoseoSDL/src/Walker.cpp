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
    
}

void Walker::update()
{
    

}

void Walker::draw(SDL_Renderer* renderer)
{
    
}
