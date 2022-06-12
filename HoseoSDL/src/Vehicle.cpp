#define WIDTH (600)
#define HEIGHT (400)

#include "Vehicle.h"

#include <algorithm>
#include <math.h>
#include <iostream>

Vehicle::Vehicle(int x, int y) : maxSpeed(4),
maxForce(0.25f), r(16), desiredSpeed(0), distance(0),
DecelerationTweaker(1.0f), speed(0), seeingDistace(100)
{
    m_pos = new Vector2D(x, y);
    m_vel = new Vector2D(4, 0);
    m_acc = new Vector2D(0, 0);
    m_force = new Vector2D(0, 0);
    rdi1 = new Vector2D(0, 0);
    rdi2 = new Vector2D(0, 0);
    rdi3 = new Vector2D(0, 0);


    posp = new Vector2D(0, 0);
    normalPoint = new Vector2D(0, 0);
    normal = new Vector2D(0, 0);
    
    m_end = new Vector2D(0, 0);
    emtiy = new Target(0, 0, 0);
    m_vel2 = new Vector2D(0, 0);
}

void Vehicle::update()
{
    edges();

    *m_vel += *m_acc;
    m_vel->limit(maxSpeed);
    *m_pos += *m_vel;
    *m_acc *= 0;

    radian = atan2(m_vel->getY(), m_vel->getX());
    *rdi1 = goradian(-r, -r / 2, radian);
    *rdi2 = goradian(-r, r / 2, radian);
    *rdi3 = goradian(r, 0, radian);

}

Vector2D Vehicle::getNormalPoint(Target* p, Vector2D* pos, Vector2D* vel)
{
    *posp = *p - *pos;
    vel->normalize();
    *normalPoint = *pos + *vel;

    return *normalPoint;
}

void Vehicle::avoid(Target* obstacle)
{
    *emtiy = *obstacle;

    *normal = getNormalPoint(obstacle, m_pos, m_vel);
    d1 = Vector2D(*normal - *obstacle).length();

    m_vel->normalize();
    *m_vel *= seeingDistace;
    *m_end = *m_pos + *m_vel;

    d2 = Vector2D(*m_end - *obstacle).length();

    if (d1 - 150 < obstacle->getR() && d2 < obstacle->getR())
    {
        *m_force = *m_end - *obstacle;

        m_force->normalize();
        *m_force *= maxForce;
        *m_force += *m_pos;

        applyForce(m_force);
    }
}

Vector2D Vehicle::goradian(float x, float y, float radian)
{
    Vector2D rota(0, 0);

    rota.setX(cos(radian) * x - sin(radian) * y);
    rota.setY(sin(radian) * x + cos(radian) * y);

    return rota;
}

void Vehicle::draw(SDL_Renderer* renderer)
{
    filledTrigonRGBA(renderer, rdi1->getX() + m_pos->getX(), rdi1->getY() + m_pos->getY(),
        rdi2->getX() + m_pos->getX(), rdi2->getY() + m_pos->getY(),
        rdi3->getX() + m_pos->getX(), rdi3->getY() + m_pos->getY(),
        255, 255, 255, 255);

    rectangleRGBA(renderer, m_pos->getX(), m_pos->getY() - r, m_pos->getX() + seeingDistace, m_pos->getY() + r
    , 100, 100, 100, 100);

    filledCircleRGBA(renderer, normal->getX(), normal->getY(), 12, 100, 100, 200, 100);

    lineRGBA(renderer, normal->getX(), normal->getY(), emtiy->getX(), emtiy->getY(), 200, 100, 100, 100);
}

void Vehicle::applyForce(Vector2D* force)
{
    *m_acc += *force;
}

void Vehicle::edges()
{
    if (m_pos->getX() > WIDTH + r)
    {
        m_pos->setX(-r);
    }
    else if (m_pos->getX() < -r)
    {
        m_pos->setX(WIDTH + r);
    }

    if (m_pos->getY() > HEIGHT + r)
    {
        m_pos->setY(-r);
    }
    else if (m_pos->getY() < -r)
    {
        m_pos->setY(HEIGHT + r);
    }
}