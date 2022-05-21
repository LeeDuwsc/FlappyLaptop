#include <iostream>
#include <string>
#include "RenderWindow.h"

void RenderWindow::createWindow(const char *title, int w, int h)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    if (window == NULL)
        std::cout << "Window failed to load. ERROR: " << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}
SDL_Texture *RenderWindow::LoadTexture(const char *filepath)
{
    SDL_Texture *tex = NULL;

    tex = IMG_LoadTexture(renderer, filepath);

    if (tex == NULL)
        std::cout << "Failed to load texture. ERROR :" << IMG_GetError << std::endl;
    return tex;
}
int RenderWindow::getRefreshRate()
{
    int displayIndex = SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode mode;
    SDL_GetDisplayMode(displayIndex, 0, &mode);

    return mode.refresh_rate;
}
void RenderWindow::Render(Object &object)
{
    SDL_Rect src;
    src.x = object.getCurrentFrame().x;
    src.y = object.getCurrentFrame().y;
    src.w = object.getCurrentFrame().w;
    src.h = object.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = (int)object.getPosition().getX() * multiplier;
    dst.y = (int)object.getPosition().getY() * multiplier;
    dst.w = (int)object.getCurrentFrame().w * multiplier;
    dst.h = (int)object.getCurrentFrame().h * multiplier;

    SDL_RenderCopy(renderer, object.getTexture(), &src, &dst);
}

void RenderWindow::Render(SDL_Texture *c_tex, Vector c_pos)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    SDL_QueryTexture(c_tex, NULL, NULL, &src.w, &src.h);

    SDL_Rect dst;
    dst.x = (int)c_pos.getX() * multiplier;
    dst.y = (int)c_pos.getY() * multiplier;
    dst.w = (int)src.w * multiplier;
    dst.h = (int)src.h * multiplier;

    SDL_RenderCopy(renderer, c_tex, &src, &dst);
}

void RenderWindow::Render(Object &object, Vector c_pos)
{
    SDL_Rect src;
    src.x = object.getCurrentFrame().x;
    src.y = object.getCurrentFrame().y;
    src.w = object.getCurrentFrame().w;
    src.h = object.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x = (int)c_pos.getX() * multiplier;
    dst.y = (int)c_pos.getY() * multiplier;
    dst.w = (int)object.getCurrentFrame().w * multiplier;
    dst.h = (int)object.getCurrentFrame().h * multiplier;

    SDL_RenderCopy(renderer, object.getTexture(), &src, &dst);
}

void RenderWindow::renderRotate(SDL_Texture *c_tex, Vector c_pos, float angle)
{
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    SDL_QueryTexture(c_tex, NULL, NULL, &src.w, &src.h);

    SDL_Rect dst;
    dst.x = (int)c_pos.getX() * multiplier;
    dst.y = (int)c_pos.getY() * multiplier;
    dst.w = src.w * multiplier;
    dst.h = src.h * multiplier;

    SDL_RenderCopyEx(renderer, c_tex, &src, &dst, angle, NULL, SDL_FLIP_NONE);
}

void RenderWindow::renderText(float x, float y, int score, TTF_Font *font, SDL_Color color)
{
    SDL_Surface *surfaceMessage = TTF_RenderText_Blended(font, std::to_string(score).c_str(), color);
    SDL_Texture *message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.w = surfaceMessage->w;
    src.h = surfaceMessage->h;

    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = src.w;
    dst.h = src.h;

    SDL_RenderCopy(renderer, message, &src, &dst);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
}

void RenderWindow::Display()
{
    SDL_RenderPresent(renderer);
}

void RenderWindow::Clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::CleanUp()
{
    SDL_DestroyWindow(window);
}