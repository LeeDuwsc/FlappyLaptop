#pragma once

#include "Object.h"

class Button : public Object
{
public:
    Button(Vector pos, SDL_Texture *tex);
};