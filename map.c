//
// Created by Denis Frohmüller on 27.12.25.
//

#include "map.h"

#include <stdlib.h>

static bool freeMap(level* level);

bool loadMap(game* game,const int selectedLevel) {

    if (game->level != NULL) {
        freeMap(game->level);
    }else {
        game->level = calloc(1,sizeof(level));
    }

    switch (selectedLevel) {
        case 0:
            game->level->map = malloc(sizeof(int) *1 );//hier level size welche ausgelesen werden müsste vorher
            game->level->lvlWidth = 0;
            return true;
        case 1:

            break;
        default:
            printf("There is no such level!");
            return false;
    }

    return false;
}

static bool freeMap(level* level) {

    if (level->map != NULL) {
        free(level->map);
        level->lvlWidth = -1;
        return true;
    }

    printf("map is NULL");
    return false;
}

bool freeLevel(game* game) {

    if (game->level != NULL) {
        free(game->level);
        game->level = NULL;
        return true;
    }

    printf("level is NULL");
    return false;
}







