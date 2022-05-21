#include "Object.h"

Object::Object(Vector c_pos, SDL_Texture *c_tex)
    : pos(c_pos), Texture(c_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    SDL_QueryTexture(Texture, NULL, NULL, &currentFrame.w, &currentFrame.h);
}

Vector &Object::getPosition()
{
    return pos;
}
void Object::setPosition(Vector c_pos)
{
    pos = c_pos;
}
SDL_Texture *Object::getTexture()
{
    return Texture;
}
SDL_Rect Object::getCurrentFrame()
{
    return currentFrame;
}