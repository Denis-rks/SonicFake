//
// Created by Denis Frohmüller on 05.11.25.
//

#include "game.h"

#include "window.h"

void eventLoop(game* game);
void draw(sdlPointer* sdlPointer);

void gameLoop(sdlPointer* sdlPointer, game* game) {
    while (game->running) {

        eventLoop(game);

        draw(sdlPointer);

        SDL_Delay(16);
    }
}

void eventLoop(game* game) {
    while (SDL_PollEvent(&game->event)) {
            switch (game->event.type) {
                case SDL_EVENT_QUIT:
                    game->running = 0;
                    break;
                default:
                    printf("Unhandled event type: %d\n", game->event.type);
                    break;
            }
        }
}

void draw(sdlPointer* sdlPointer) {
    SDL_SetRenderDrawColor(sdlPointer->renderer, 255, 0, 0, 255);
    SDL_RenderClear(sdlPointer->renderer);
    SDL_RenderPresent(sdlPointer->renderer);
}
