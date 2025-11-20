//
// Created by Denis Frohmüller on 17.11.25.
//
#include "player.h"
#include "../game.h"

int createPlayer(game* game) {
    if (game->player != NULL) {
        printf("Error: Already existing player!\n");
        return false;
    }

    game->player = calloc(1, sizeof(player));
    if (game->player == NULL) {
        printf("Error: Allocation of player failed!\n");
        return false;
    }

    game->player->hitbox = (SDL_FRect){100,1001,100,100};
    game->player->health = 100;

    return true;
}

int freePlayer(game* game) {
    if (game->player == NULL) {
        printf("Player Already Freed!\n");
        return false;
    }

    free(game->player);
    game->player = NULL;
    return true;
}
