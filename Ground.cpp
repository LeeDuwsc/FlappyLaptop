#include "Ground.h"

Ground::Ground(Vector c_pos, SDL_Texture *c_tex)
    : Object(c_pos, c_tex)
{
}

void Ground::Update(float speed)
{
    setPosition(Vector(getPosition().getX() - 0.32f * speed, 200.0f));

    if (getPosition().getX() <= -154)
        setPosition(Vector(154, 200));
}
