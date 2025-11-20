//
// Created by Denis Frohmüller on 17.11.25.
//

#ifndef SONICFAKE_PLAYER_H
#define SONICFAKE_PLAYER_H

#include "../window.h"

struct game;

typedef struct player {
    SDL_FRect hitbox;
    uint8_t health;
}player;

int createPlayer(struct game* game);
int freePlayer(struct game* game);
#endif //SONICFAKE_PLAYER_H
