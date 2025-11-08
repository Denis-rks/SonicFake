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

    game.box = (SDL_FRect) { 100, 100, 100, 100 };
    //todo hier soll ca das level erstmal geladen werden fürs erste ein level statisch
    gameLoop(&sdlPointer, &game);

    gameFree(&sdlPointer);
    return exitStatus;
}