#include "Laptop.h"

Laptop::Laptop(Vector c_pos, SDL_Texture *c_tex)
    : Object(c_pos, c_tex)
{
    gravity.setX(0.0f);
    gravity.setY(0.04f);
}

void Laptop::Update()
{
    if (velocity.getY() <= 1.2f)
        velocity.addTo(gravity);

    if (velocity.getY() > 1.2f)
        velocity.setY(2.f);

    setPosition(Vector(25, getPosition().getY() + velocity.getY()));

    if (velocity.getY() >= 1.0f && angle <= 450.0f)
    {
        jump = false;
        angle += 3.0f;

        if (angle <= 0.0f)
            angle = 0.0f;
    }

    if (velocity.getY() < 0.0f)
    {
        jump = true;
        angle = 330;
    }
}

void Laptop::Jump()
{
    if (velocity.getY() >= -1.8)
        velocity.setY(-1.5f);

    if (velocity.getY() < -1.8)
        velocity.setY(1.8f);
}

float Laptop::getAngle()
{
    return angle;
}

void Laptop::setAngle(float value)
{
    angle = value;
}
void Laptop::setGravity(float x, float y)
{
    gravity.setX(x);
    gravity.setY(y);
}

void Laptop::Wave()
{
    waveValue += 0.05f;
    setPosition(getPosition() + Vector(0.f, sin(waveValue) / 2));
}
