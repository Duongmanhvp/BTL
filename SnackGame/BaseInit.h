#ifndef Base_Init_h_
#define Base_Init_h_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <bits/stdc++.h>
using namespace std;

// Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 750;

const int step = 20;

enum
{
     RIGHT,
     LEFT,
     UP,
     DOWN
};

bool CheckVaCham(SDL_Rect &a, SDL_Rect &b);

bool init(SDL_Window* &gWindow, SDL_Renderer* &gRenderer);

void QuitSDL(SDL_Window* &gWindow, SDL_Renderer* &gRenderer);

#endif
