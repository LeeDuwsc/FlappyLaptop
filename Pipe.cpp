#include "Pipe.h"

Pipe::Pipe(Vector c_pos, SDL_Texture *c_tex)
    : Object(c_pos, c_tex)
{
}
void Pipe::Update(float speed)
{
    setPosition(Vector(getPosition().getX() - 0.32f * speed, getPosition().getY()));

    if (getPosition().getX() <= -40)
    {
        setPosition(Vector(240, getPosition().getY()));
        pipeCrossed = true;
    }
}