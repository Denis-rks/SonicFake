//
// Created by Denis Frohmüller on 05.11.25.
//

#include "game.h"

#include "window.h"

void eventLoop(game* game);
void draw(sdlPointer* sdlPointer, game* game);
void handleInput(game* game);

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
    SDL_SetRenderDrawColor(sdlPointer->renderer, 255, 0, 0, 255);
    SDL_RenderClear(sdlPointer->renderer);

    SDL_SetRenderDrawColor(sdlPointer->renderer, 255, 255, 0, 255);
    SDL_RenderFillRect(sdlPointer->renderer, &game->box);

    SDL_RenderPresent(sdlPointer->renderer);
}

void handleInput(game* game) {
    switch (game->event.key.scancode) {
        case SDL_SCANCODE_W:
            game->box.y -= 5;
            break;
        case SDL_SCANCODE_S:
            game->box.y += 5;
            break;
        case SDL_SCANCODE_A:
            game->box.x -= 5;
            break;
        case SDL_SCANCODE_D:
            game->box.x += 5;
            break;
        default:
            break;
    }
}
