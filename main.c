#include "window.h"
#include "game.h"
#include "entities/player.h"


int main(void) {


    int exitStatus = EXIT_FAILURE;

    sdlPointer sdlPointer = {0};
    game game = {0};

    if (gameInitSdl(&sdlPointer) == 0) {
        exitStatus = EXIT_SUCCESS;
        game.running = 1;
    }

    if (!createPlayer(&game)) {
        exitStatus = EXIT_FAILURE;
        game.running = 0;
        printf("Failed to create player!\n");
    }

    //todo hier soll ca das level erstmal geladen werden fürs erste ein level statisch vlt auch doch nicht hier
    gameLoop(&sdlPointer, &game);

    freePlayer(&game);
    gameFree(&sdlPointer);
    return exitStatus;
}
