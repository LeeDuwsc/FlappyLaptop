#pragma once

#include <SDL.h>
#include "Vector.h"
class Object
{
private:
    Vector pos;
    SDL_Rect currentFrame;
    SDL_Texture *Texture;

public:
    Object(Vector c_pos, SDL_Texture *c_tex);
    Vector &getPosition();
    void setPosition(Vector c_pos);
    SDL_Texture *getTexture();
    SDL_Rect getCurrentFrame();
};