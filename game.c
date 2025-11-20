//
// Created by Denis Frohmüller on 05.11.25.

#include "game.h"
#include "entities/player.h"

static void eventLoop(game* game);
static void draw(const sdlPointer* sdlPointer, const game* game);
static void handleInput(game* game, SDL_Event event);
static int checkCollision(SDL_FRect box1, SDL_FRect box2);

void gameLoop(const sdlPointer* sdlPointer, game* game) {
    while (game->running) {

        eventLoop(game);

        draw(sdlPointer, game);

        SDL_Delay(16);
    }
}

static void eventLoop(game* game) {

    SDL_Event event = {0};

    while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    game->running = 0;
                    break;
                case SDL_EVENT_KEY_DOWN:
                    handleInput(game, event);
                    break;
                default:
                    printf("Unhandled event type: %d\n", event.type);
                    break;
            }
        }
}

static void draw(const sdlPointer* sdlPointer,const game* game) {
    SDL_SetRenderDrawColor(sdlPointer->renderer, 255, 255, 255, 255);
    SDL_RenderClear(sdlPointer->renderer);

    SDL_SetRenderDrawColor(sdlPointer->renderer, 100, 100, 100, 255);
    SDL_RenderFillRect(sdlPointer->renderer, &game->player->hitbox);

    /*while (game->entities != NULL) {
        entity const* ent = *game->entities;
        SDL_SetRenderDrawColor(sdlPointer->renderer, 255, 255, 0, 255);
        SDL_RenderFillRect(sdlPointer->renderer, &ent->hitbox);
        game->entities++;
    }*/


    SDL_RenderPresent(sdlPointer->renderer);
}

static void handleInput(game* game, SDL_Event event) {

    SDL_FRect testBox = game->player->hitbox;

    switch (event.key.scancode) {
        case SDL_SCANCODE_W:

            for (int i = 0; i <= 5; i++) {
                testBox.y -= (float)1;

                //if (!checkCollision(&testBox, &gegner)) {
                    game->player->hitbox.y = testBox.y;
                //}
            }
            break;
        case SDL_SCANCODE_S:

            for (int i = 0; i <= 5; i++) {
                testBox.y += (float)1;

                //if (!checkCollision(&testBox, &gegner)) {
                    game->player->hitbox.y = testBox.y;
                //}
            }

            break;
        case SDL_SCANCODE_A:

            for (int i = 0; i <= 5; i++) {
                testBox.x -= (float)1;

                //if (!checkCollision(&testBox, &gegner)) {
                    game->player->hitbox.x = testBox.x;
                //}
            }

            break;
        case SDL_SCANCODE_D:
            for (int i = 0; i <= 5; i++) {
                testBox.x += (float)1;

                //if (!checkCollision(&testBox, &gegner)) {
                    game->player->hitbox.x = testBox.x;
                //}
            }

            break;
        default:
            break;
    }
}

static int checkCollision(SDL_FRect box1, SDL_FRect box2) {

    if (box1.x < box2.x + box2.w
        && box1.x + box1.w > box2.x
        && box1.y < box2.y + box2.h
        && box1.y + box1.h > box2.y) {
        return 1;
    }

    return 0;
}
