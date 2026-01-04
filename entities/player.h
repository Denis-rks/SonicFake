//
// Created by Denis Frohmüller on 17.11.25.
//

#ifndef SONICFAKE_PLAYER_H
#define SONICFAKE_PLAYER_H

#include "../window.h"

#define MAXSPEEDX 10
#define MAXSPEEDY 10

struct game;

typedef struct player {
    SDL_FRect hitbox;
    uint8_t health;
    short curSpeedX; // spieler soll immer schneller werden deshalb soll seine momentane geschwindigkeit festgehalten werden
    short curSpeedY;
}player;

int createPlayer(struct game* game);
int freePlayer(struct game* game);
#endif //SONICFAKE_PLAYER_H
