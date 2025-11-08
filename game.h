//
// Created by Denis Frohmüller on 05.11.25.

#ifndef SONICFAKE_GAME_H
#define SONICFAKE_GAME_H

#include "window.h"

typedef enum {
    MAINMENU,
    GAMEMENU,
    SETTINGSMENU
}gameState;

typedef struct game{
    SDL_FRect box;
    int running;
    SDL_Event event;
}game;

void gameLoop(sdlPointer* sdlPointer, game* game);
#endif //SONICFAKE_GAME_H