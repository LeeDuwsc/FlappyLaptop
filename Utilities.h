#pragma once

#include <SDL.h>
#include "Object.h"
#include <iostream>

int fps = 0;
float startTime = 0.f;
float currentTime = 0.f;

float HireTimeInSeconds()
{
    return (float)SDL_GetTicks() * 0.0001f;
}

void getFramesRate()
{
    fps++;
    startTime = (float)SDL_GetTicks();

    if ((startTime - currentTime) > 1000.0f)
    {
        currentTime = startTime;
        std::cout << fps << std::endl;
        fps = 0;
    }
}

int RandomValues(int maxx, int minn)
{
    return rand() % (maxx - minn + 1) + minn;
}

float Distance(Vector v1, Vector v2)
{
    float dx = v1.getX() - v2.getX();
    float dy = v1.getY() - v2.getY();

    return sqrt(dx * dx + dy * dy);
}

float DistanceXY(float x1, float y1, float x2, float y2)
{
    float dx = x1 - x2;
    float dy = y1 - y2;

    return sqrt(dx * dx + dy * dy);
}

bool RangeIntersect(float min0, float max0, float min1, float max1)
{
    return std::min(min0, max0) <= std::max(min1, max1) &&
           std::max(min0, max0) >= std::min(min1, max1);
}

bool IsCollide(Object o1, Object o2)
{
    return RangeIntersect(o1.getPosition().getX(), o1.getPosition().getX() + (float)o1.getCurrentFrame().w, o2.getPosition().getX(), o2.getPosition().getX() + (float)o2.getCurrentFrame().w) &&
           RangeIntersect(o1.getPosition().getY(), o1.getPosition().getY() + (float)o1.getCurrentFrame().h, o2.getPosition().getY(), o2.getPosition().getY() + (float)o2.getCurrentFrame().h);
}

bool IsTrigger(Object object, float x, float y, float value)
{
    return RangeIntersect(object.getPosition().getX(), object.getPosition().getX() + (float)object.getCurrentFrame().w, x, x + 1) &&
           RangeIntersect(object.getPosition().getY(), object.getPosition().getY() + (float)object.getCurrentFrame().h, y, y - value);
}

bool InRange(float minn, float maxx, float value)
{
    return value >= std::min(minn, maxx) && value <= std::max(minn, maxx);
}

bool IsCollide(float x, float y, Object object)
{
    return InRange(object.getPosition().getX(), object.getPosition().getX() + object.getCurrentFrame().w, x) &&
           InRange(object.getPosition().getY(), object.getPosition().getY() + object.getCurrentFrame().h, y);
}