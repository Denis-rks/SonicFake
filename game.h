//
// Created by Denis Frohmüller on 05.11.25.

#ifndef SONICFAKE_GAME_H
#define SONICFAKE_GAME_H

#include "window.h"

#define TILE_SIZE 64

struct player;

typedef enum {
    TITLE_SCREEN,
    GAME_SCREEN,
    SETTINGS_SCREEN
}gameState;

typedef struct game{
    struct player* player;
    struct level* level;
    gameState state;
    bool running;

}game;

void gameLoop(const sdlPointer* sdlPointer, game* game);
#endif //SONICFAKE_GAME_H
