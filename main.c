#include <_stdlib.h>

#include "window.h"
#include "game.h"

int main() {
    int exitStatus = EXIT_FAILURE;

    sdlPointer sdlPointer = {};
    game game = {};

    if (gameInitSdl(&sdlPointer) == 0) {
        exitStatus = EXIT_SUCCESS;
        game.running = 1;
    }

    gameLoop(&sdlPointer, &game);

    SDL_Delay(3000);

    gameFree(&sdlPointer);
    return exitStatus;
}