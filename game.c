//
// Created by Denis Frohmüller on 05.11.25.
//

#include "game.h"

#include "window.h"

SDL_FRect gegner = {300,120,70,70};// wird später wieder entferntgi

void eventLoop(game* game);
void draw(sdlPointer* sdlPointer, game* game);
void handleInput(game* game);
int checkCollision(const SDL_FRect* box1, const SDL_FRect* box2);

void gameLoop(sdlPointer* sdlPointer, game* game) {
    while (game->running) {

        eventLoop(game);

        draw(sdlPointer, game);

        SDL_Delay(16);
    }
}

void eventLoop(game* game) {
    while (SDL_PollEvent(&game->event)) {
            switch (game->event.type) {
                case SDL_EVENT_QUIT:
                    game->running = 0;
                    break;
                case SDL_EVENT_KEY_DOWN:
                    handleInput(game);
                    break;
                default:
                    printf("Unhandled event type: %d\n", game->event.type);
                    break;
            }
        }
}

void draw(sdlPointer* sdlPointer, game* game) {
    SDL_SetRenderDrawColor(sdlPointer->renderer, 255, 255, 255, 255);
    SDL_RenderClear(sdlPointer->renderer);

    SDL_SetRenderDrawColor(sdlPointer->renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(sdlPointer->renderer, &game->box);

    SDL_SetRenderDrawColor(sdlPointer->renderer, 0, 255, 255, 255);
    SDL_RenderFillRect(sdlPointer->renderer, &gegner);

    SDL_RenderPresent(sdlPointer->renderer);
}

void handleInput(game* game) {

    SDL_FRect testBox = game->box;

    switch (game->event.key.scancode) {
        case SDL_SCANCODE_W:

            for (int i = 0; i <= 5; i++) {
                testBox.y -= (float)1;

                if (!checkCollision(&testBox, &gegner)) {
                    game->box.y = testBox.y;
                }
            }
            break;
        case SDL_SCANCODE_S:

            for (int i = 0; i <= 5; i++) {
                testBox.y += (float)1;

                if (!checkCollision(&testBox, &gegner)) {
                    game->box.y = testBox.y;
                }
            }

            break;
        case SDL_SCANCODE_A:

            for (int i = 0; i <= 5; i++) {
                testBox.x -= (float)1;

                if (!checkCollision(&testBox, &gegner)) {
                game->box.x = testBox.x;
                }
            }

            break;
        case SDL_SCANCODE_D:
            for (int i = 0; i <= 5; i++) {
                testBox.x += (float)1;

                if (!checkCollision(&testBox, &gegner)) {
                    game->box.x = testBox.x;
                }
            }

            break;
        default:
            break;
    }
}

int checkCollision(const SDL_FRect* box1, const SDL_FRect* box2) {

    if (box1->x < box2->x + box2->w
        && box1->x + box1->w > box2->x
        && box1->y < box2->y + box2->h
        && box1->y + box1->h > box2->y) {
        return 1;
    }

    return 0;
}
