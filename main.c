#include <_stdlib.h>

#include "window.h"
#include "game.h"

int main() {
    int exitStatus = EXIT_FAILURE;

    sdlPointer sdlPointer = {};

    if (gameInitSdl(&sdlPointer) == 0) {
        exitStatus = EXIT_SUCCESS;
    }

    gameLoop(&sdlPointer);

    SDL_Delay(3000);

    gameFree(&sdlPointer);
    return exitStatus;
}