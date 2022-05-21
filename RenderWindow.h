#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "Object.h"

class RenderWindow
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    const int multiplier = 3;

public:
    void createWindow(const char *title, int w, int h);
    SDL_Texture *LoadTexture(const char *filepath);
    int getRefreshRate();
    void Render(Object &object);
    void Render(SDL_Texture *c_tex, Vector c_pos);
    void Render(Object &object, Vector c_pos);
    void renderRotate(SDL_Texture *c_tex, Vector c_pos, float angle);
    void renderText(float x, float y, int score, TTF_Font *font, SDL_Color color);
    void Display();
    void Clear();
    void CleanUp();
};
