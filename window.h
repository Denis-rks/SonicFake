//
// Created by Denis Frohmüller on 05.11.25.
//

#ifndef SONICFAKE_WINDOW_H
#define SONICFAKE_WINDOW_H

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#define SLD_FLAGS SDL_INIT_VIDEO

#define WINDOW_TITLE "Sonic Fake"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct sdlPointer{
    SDL_Window* window;
    SDL_Renderer* renderer;
} sdlPointer;

int gameInitSdl(sdlPointer *sdlPointer);
void gameFree(sdlPointer *sdlPointer);

#endif //SONICFAKE_WINDOW_H