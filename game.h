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

}game;

void gameLoop(sdlPointer* sdlPointer);
#endif //SONICFAKE_GAME_H