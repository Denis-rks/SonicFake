//
// Created by Denis Frohmüller on 27.12.25.
//

#ifndef SONICFAKE_MAP_H
#define SONICFAKE_MAP_H

#include "game.h"

#define LVL_HEIGHT 16

#define AIR_TILE 0
#define GROUND_TILE 1

typedef struct level {
    int* map;
    short lvlWidth;
}level;

bool loadMap(game* game, int selectedLevel);
bool freeLevel(game* game);

#endif //SONICFAKE_MAP_H
