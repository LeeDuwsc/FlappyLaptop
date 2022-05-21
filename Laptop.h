#pragma once

#include <iostream>

#include "Object.h"
#include "Vector.h"

class Laptop : public Object
{
private:
    Vector gravity;
    Vector velocity;
    float angle = 0.0f;
    bool jump = false;
    float waveValue = 0.f;

public:
    Laptop(Vector c_pos, SDL_Texture *p_tex);
    void Update();
    void Jump();
    float getAngle();
    void setAngle(float value);
    void setGravity(float x, float y);
    void Wave();
};