//
// Created by Denis Frohmüller on 05.11.25.

#ifndef SONICFAKE_GAME_H
#define SONICFAKE_GAME_H

#include "window.h"

struct player;

typedef enum {
    MAINMENU,
    GAMEMENU,
    SETTINGSMENU
}gameState;

typedef struct game{
    unsigned int running : 1; //Ein bit
    gameState state;
    struct player* player;
}game;

void gameLoop(const sdlPointer* sdlPointer, game* game);
#endif //SONICFAKE_GAME_H
