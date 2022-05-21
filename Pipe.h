#pragma once
#include <SDL.h>

#include "Object.h"
#include "Vector.h"

class Pipe : public Object
{
public:
    bool pipeCrossed = false;
    Pipe(Vector c_pos, SDL_Texture *c_texture);
    void Update(float speed = 1.0f);
};
