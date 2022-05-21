#pragma once

#include "Object.h"

class Ground : public Object
{
public:
    Ground(Vector c_pos, SDL_Texture *c_tex);
    void Update(float speed = 1.0f);
};