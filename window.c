//
// Created by Denis Frohmüller on 05.11.25.
//

#include "window.h"

int gameInitSdl(sdlPointer *sdlPointer) {
    if (!SDL_Init(SDL_FLAGS)) {
        fprintf(stderr, "Failed to initialize SDL %s\n", SDL_GetError());
        return -1;
    }

    sdlPointer->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_HIGH_PIXEL_DENSITY);

    if (!sdlPointer->window) {
        fprintf(stderr, "Failed to create window %s\n", SDL_GetError());
        return -1;
    }

    sdlPointer->renderer = SDL_CreateRenderer(sdlPointer->window, NULL);

    if (!sdlPointer->renderer) {
        fprintf(stderr, "Failed to create renderer %s\n", SDL_GetError());
        return -1;
    }

    return 0;
}

void gameFree(sdlPointer *sdlPointer) {
    if (sdlPointer->window) {
        SDL_DestroyWindow(sdlPointer->window);
        sdlPointer->window = NULL;
    }

    if (sdlPointer->renderer) {
        SDL_DestroyRenderer(sdlPointer->renderer);
        sdlPointer->renderer = NULL;
    }
    SDL_Quit();

    printf("Resources have been released\n");
}
