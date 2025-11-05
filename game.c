//
// Created by Denis Frohmüller on 05.11.25.
//

#include "game.h"

#include "window.h"

void gameLoop(sdlPointer* sdlPointer) {

    int running = 1;
    while (running) {

        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                running = 0;
            }
        }

        SDL_SetRenderDrawColor(sdlPointer->renderer, 255, 0, 0, 255);
        SDL_RenderClear(sdlPointer->renderer);
        SDL_RenderPresent(sdlPointer->renderer);
    }
}
