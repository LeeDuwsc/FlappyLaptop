#include <SDL_image.h>
#include <stdlib.h>
#include <time.h>
#include <SDL_ttf.h>

#include "RenderWindow.h"
#include "Pipe.h"
#include "Utilities.h"
#include "Laptop.h"
#include "Ground.h"
#include "Button.h"

bool Init();

bool load = Init();

RenderWindow window;

const int SCREEN_WIDTH = 432;
const int SCREEN_HEIGHT = 768;

SDL_Texture *background = NULL;
SDL_Texture *pipeTex_down = NULL;
SDL_Texture *pipeTex_up = NULL;
SDL_Texture *laptopTex[3] = {NULL, NULL, NULL};
SDL_Texture *groundTex = NULL;
SDL_Texture *UI_GetReadyTexture = NULL;
SDL_Texture *UI_LapTexture = NULL;
SDL_Texture *UI_HandTexture = NULL;
SDL_Texture *UI_TapTexture = NULL;
SDL_Texture *UI_OKButtonTexture = NULL;
SDL_Texture *UI_GameOverTexture = NULL;

SDL_Event event;
bool gameRunning = true;

const int frameRate = 60;
int startTicks;
int frameTicks;
const int PIPE_UP_MAX_Y = -30,
          PIPE_UP_MIN_Y = -90;
float oneFlapTime = 0.2f;
float cTime = 0.0f;
int num = 0;
int num2 = 0;
bool start = false;
bool lapDead = false;
int mouseX, mouseY;
std::string scoreText;
float scoreTime = 0.f;
int currentScore = 0;
bool scoreCheck = false;

float gameSpeed = 3.3f;

SDL_Color scoreColor = {255, 255, 100};
TTF_Font *font = TTF_OpenFont("res/font/font.ttf", 90);

bool Init()
{
    srand((unsigned int)time(NULL));
    if (SDL_Init(SDL_INIT_VIDEO > 0))
        std::cout << "SDL_Init has Failed. Error: " << SDL_GetError() << std::endl;
    if (!IMG_Init(IMG_INIT_PNG))
        std::cout << "SDL_image has Failed. Error: " << IMG_GetError() << std::endl;
    if (TTF_Init() == -1)
        std::cout << "SDL_ttf has Failed. Error: " << TTF_GetError() << std::endl;

    window.createWindow("Flappy Laptop", SCREEN_WIDTH, SCREEN_HEIGHT);

    std::cout << "Refresh Rate: " << window.getRefreshRate() << std::endl;

    // Loading Textures

    background = window.LoadTexture("res/gfx/Background.png");

    pipeTex_up = window.LoadTexture("res/gfx/PipeUp.png");
    pipeTex_down = window.LoadTexture("res/gfx/PipeDown.png");

    laptopTex[0] = window.LoadTexture("res/gfx/Lap1.png");
    laptopTex[1] = window.LoadTexture("res/gfx/Lap2.png");
    laptopTex[2] = window.LoadTexture("res/gfx/Lap3.png");

    groundTex = window.LoadTexture("res/gfx/Ground1.png");

    UI_GetReadyTexture = window.LoadTexture("res/gfx/GetReadyText.png");
    UI_LapTexture = window.LoadTexture("res/gfx/Lap4.png");
    UI_HandTexture = window.LoadTexture("res/gfx/TutorialHand.png");
    UI_TapTexture = window.LoadTexture("res/gfx/Tap.png");
    UI_OKButtonTexture = window.LoadTexture("res/gfx/OkButton.png");
    UI_GameOverTexture = window.LoadTexture("res/gfx/GameOverText.png");

    return true;
}

float pipe_X_pos[4] = {270.f, 350.f, 420.f, 490.f};

float randPipeValue[4] = {
    (float)RandomValues(PIPE_UP_MAX_Y, PIPE_UP_MIN_Y),
    (float)RandomValues(PIPE_UP_MAX_Y, PIPE_UP_MIN_Y),
    (float)RandomValues(PIPE_UP_MAX_Y, PIPE_UP_MIN_Y),
    (float)RandomValues(PIPE_UP_MAX_Y, PIPE_UP_MIN_Y)};

Pipe pipe_down[4] = {
    Pipe(Vector(pipe_X_pos[0], 190 + randPipeValue[0]), pipeTex_down),
    Pipe(Vector(pipe_X_pos[1], 190 + randPipeValue[1]), pipeTex_down),
    Pipe(Vector(pipe_X_pos[2], 190 + randPipeValue[2]), pipeTex_down),
    Pipe(Vector(pipe_X_pos[3], 190 + randPipeValue[3]), pipeTex_down)};

Pipe pipe_up[4] = {
    Pipe(Vector(pipe_X_pos[0], randPipeValue[0]), pipeTex_up),
    Pipe(Vector(pipe_X_pos[1], randPipeValue[1]), pipeTex_up),
    Pipe(Vector(pipe_X_pos[2], randPipeValue[2]), pipeTex_up),
    Pipe(Vector(pipe_X_pos[3], randPipeValue[3]), pipeTex_up)};

Ground ground[2] = {
    Ground(Vector(0.f, 200.f), groundTex),
    Ground(Vector(154.f, 200.f), groundTex)};

Laptop laptop(Vector(25, 96), laptopTex[0]);

Button OkButton(Vector(50.f, 150.f), UI_OKButtonTexture);

void MenuReset()
{
    laptop.setPosition(Vector(25.f, 110.f));
    laptop.setAngle(0.f);

    for (int i = 0; i < 4; i++)
    {
        float randPipe = (float)RandomValues(PIPE_UP_MAX_Y, PIPE_UP_MIN_Y);
        pipe_down[i].setPosition(Vector(pipe_X_pos[i], 190 + randPipe));
        pipe_up[i].setPosition(Vector(pipe_X_pos[i], randPipe));
    }

    currentScore = 0;
    start = false;
    lapDead = false;
}

void GameLoop()
{
    getFramesRate();

    startTicks = SDL_GetTicks();
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
        {
            gameRunning = false;
            break;
        }

        case SDL_MOUSEBUTTONDOWN:
        {
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                laptop.Jump();
                if (!start)
                {
                    start = true;
                }
                if (IsCollide((float)mouseX / 3, (float)mouseY / 3, OkButton) && lapDead)
                {
                    MenuReset();
                }
            }
            break;
        }
        }
    }
    window.Clear();

    window.Render(background, Vector(0, 0));

    // sinh cot random

    for (num = 0; num < 4; num++)
    {
        float randPipe = (float)RandomValues(PIPE_UP_MAX_Y, PIPE_UP_MIN_Y);
        if (pipe_up[num].pipeCrossed)
        {
            pipe_up[num].setPosition(Vector(pipe_up[num].getPosition().getX(), randPipe));
            pipe_up[num].pipeCrossed = false;
        }

        if (pipe_down[num].pipeCrossed)
        {
            pipe_down[num].setPosition(Vector(pipe_down[num].getPosition().getX(), 190 + randPipe));
            pipe_down[num].pipeCrossed = false;
        }
    }
    // tinh diem
    if (scoreCheck)
    {
        scoreTime += 0.007f * gameSpeed;
        if (scoreTime >= 1.f)
        {
            scoreTime = 0.f;
            scoreCheck = false;
        }
    }
    // xu ly va cham giua cot va laptop
    if (!lapDead)
    {
        for (num = 0; num < 4; num++)
        {
            if (IsCollide(laptop, pipe_up[num]))
                lapDead = true;
            else if (IsCollide(laptop, pipe_down[num]))
                lapDead = true;
            else if (IsTrigger(laptop, pipe_down[num].getPosition().getX() + (pipe_down[num].getCurrentFrame().w / 2.f), pipe_down[num].getPosition().getY(), 100.f) && !scoreCheck)
            {
                scoreCheck = true;
                currentScore += 1;
            }
            if (num < 2)
                if (IsCollide(laptop, ground[num]))
                    lapDead = true;
            if (laptop.getPosition().getY() <= 0)
                lapDead = true;
        }
    }

    // render pipe
    if (start)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (!lapDead)
            {
                pipe_down[i].Update(gameSpeed);
                pipe_up[i].Update(gameSpeed);
            }
            window.Render(pipe_down[i]);
            window.Render(pipe_up[i]);
        }
    }
    // UI mini menu
    if (!start)
    {
        window.Render(UI_GetReadyTexture, Vector(25.f, 40.f));
        window.Render(UI_LapTexture, Vector(85.f, 100.f));
        window.Render(UI_HandTexture, Vector(90.f, 120.f));
        window.Render(UI_TapTexture, Vector(103.f, 130.f));
        laptop.Wave();
    }
    else
    {
        if (!lapDead)
        {
            laptop.setGravity(0.f, 0.05f);
            laptop.Update();
        }
    }

    // ground render
    for (num = 0; num < 2; num++)
    {
        if (!lapDead)
        {
            ground[num].Update(gameSpeed);
        }
        window.Render(ground[num]);
    }

    // laptop render
    if (!lapDead)
    {
        if (cTime >= oneFlapTime)
        {
            cTime = 0.0f;
            num2 += 1;
            if (num2 > 2)
                num2 = 0;
        }
        cTime += 0.02f;
        window.renderRotate(laptopTex[num2], laptop.getPosition(), laptop.getAngle());
    }
    else
        window.renderRotate(laptopTex[0], laptop.getPosition(), laptop.getAngle());

    // Game Over
    if (lapDead)
    {
        window.Render(OkButton);
        window.Render(UI_GameOverTexture, Vector(25.f, 50.f));
        SDL_GetMouseState(&mouseX, &mouseY);
    }

    // render score
    if (start)
    {
        window.renderText(200.0f, 10.0f, currentScore, font, scoreColor);
    }

    window.Display();

    frameTicks = SDL_GetTicks() - startTicks;
    if (frameTicks < 1000 / window.getRefreshRate())
        SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
}

int main(int argc, char *args[])
{
    while (gameRunning)
    {
        GameLoop();
    }

    window.CleanUp();
    TTF_Quit();
    SDL_Quit();

    return 0;
}
