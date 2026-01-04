//
// Created by Denis Frohmüller on 05.11.25.

#include "game.h"

#include "map.h"
#include "entities/player.h"

SDL_FRect gameStartButton = {WINDOW_WIDTH/2-200,WINDOW_HEIGHT/2-75 , 400, 150};

static void eventLoop(game* game);
static void titleScreenEventLoop(game* game, SDL_Event event);
static void gameScreenEventLoop(game* game, SDL_Event event);
static void draw(const sdlPointer* sdlPointer, const game* game);
static void drawTitleScreen(const sdlPointer* sdlPointer);
static void drawGameScreen(const sdlPointer* sdlPointer,const game* game);
static void drawSettingsScreen(const sdlPointer* sdlPointer,const game* game);
static void handleInput(const game* game, SDL_Event event);
static void titleToGameScreen(game* game);

static int checkCollision(SDL_FRect box1,SDL_FRect box2);

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
        if (event.type == SDL_EVENT_QUIT) {
            game->running = 0;
        }else if (game->state == TITLE_SCREEN) {
            titleScreenEventLoop(game, event);
        }else if (game->state == GAME_SCREEN) {
            gameScreenEventLoop(game, event);
        }
    }
}

static void titleScreenEventLoop(game* game, SDL_Event event) {
    float x;
    float y;

    switch (event.type) {
        case SDL_EVENT_MOUSE_BUTTON_DOWN:
            SDL_GetMouseState(&x, &y);
            printf("Mouse button down: x=%f, y=%f\n", x, y);
            if (!checkCollision((SDL_FRect){x,y,5,5}, gameStartButton)) {
                titleToGameScreen(game);
            }
    }

}

static void gameScreenEventLoop(game *game, SDL_Event event) {
    switch (event.type) {
        case SDL_EVENT_KEY_DOWN:
            handleInput(game, event);
            break;
        default:
            printf("Unhandled event type: %d\n", event.type);
            break;
    }
}

static void draw(const sdlPointer* sdlPointer, const game* game) {
    if (game->state == TITLE_SCREEN) {
        drawTitleScreen(sdlPointer);
    }else if (game->state == GAME_SCREEN) {
        drawGameScreen(sdlPointer, game);
    }else if (game->state == SETTINGS_SCREEN) {
        drawSettingsScreen(sdlPointer, game);
    }
}

static void drawTitleScreen(const sdlPointer* sdlPointer) {

    SDL_SetRenderDrawColor(sdlPointer->renderer, 255,255, 0, 125);
    SDL_RenderClear(sdlPointer->renderer);

    SDL_SetRenderDrawColor(sdlPointer->renderer, 010, 010, 010, 255);
    SDL_RenderFillRect(sdlPointer->renderer, &gameStartButton);

    SDL_RenderPresent(sdlPointer->renderer);
}

static void drawGameScreen(const sdlPointer* sdlPointer,const game* game) {
    SDL_SetRenderDrawColor(sdlPointer->renderer, 255, 255, 255, 255);
    SDL_RenderClear(sdlPointer->renderer);

    for (int i = 0; i < game->level->lvlWidth * LVL_HEIGHT; i++) {
        if (game->level->map[i] == 1) {
            SDL_SetRenderDrawColor(sdlPointer->renderer, 0, 0, 0, 255);
            SDL_RenderFillRect(sdlPointer->renderer, &(SDL_FRect){i%game->level->lvlWidth + TILE_SIZE,i/game->level->lvlWidth + TILE_SIZE,TILE_SIZE,TILE_SIZE});
        }
    }

    SDL_SetRenderDrawColor(sdlPointer->renderer, 100, 100, 100, 255);
    SDL_RenderFillRect(sdlPointer->renderer, &game->player->hitbox);

    SDL_RenderPresent(sdlPointer->renderer);
}

static void drawSettingsScreen(const sdlPointer* sdlPointer,const game* game) {
    if (game != NULL) {
        printf("Servus");
    }

    SDL_SetRenderDrawColor(sdlPointer->renderer, 255,255, 0, 125);
    SDL_RenderClear(sdlPointer->renderer);

    SDL_RenderPresent(sdlPointer->renderer);
}
static void handleInput(const game* game,const SDL_Event event) {
    SDL_FRect testBox = game->player->hitbox;

    switch (event.key.scancode) {
        case SDL_SCANCODE_W:

            for (int i = 0; i <= 5; i++) {
                testBox.y -= (float)1;

                if (checkCollision(testBox, (SDL_FRect){0,0,0,0})) {
                    game->player->hitbox.y = testBox.y;
                }
            }
            break;
        case SDL_SCANCODE_S:

            for (int i = 0; i <= 5; i++) {
                testBox.y += (float)1;

                if (checkCollision(testBox, (SDL_FRect){0,0,0,0})) {
                    game->player->hitbox.y = testBox.y;
                }
            }

            break;
        case SDL_SCANCODE_A:

            for (int i = 0; i <= 5; i++) {
                testBox.x -= (float)1;

                if (checkCollision(testBox, (SDL_FRect){0,0,0,0})) {
                    game->player->hitbox.x = testBox.x;
                }
            }
            break;
        case SDL_SCANCODE_D:
            for (int i = 0; i <= 5; i++) {
                testBox.x += (float)1;

                if (checkCollision(testBox, (SDL_FRect){0,0,0,0})) {
                    game->player->hitbox.x = testBox.x;
                }
            }

            break;
        default:
            break;
    }
}

static int checkCollision(const SDL_FRect box1,const SDL_FRect box2) {

    if (box1.x < box2.x + box2.w
        && box1.x + box1.w > box2.x
        && box1.y < box2.y + box2.h
        && box1.y + box1.h > box2.y) {
        return false;
    }

    return true;
}

static void titleToGameScreen(game* game) {

    game->state = GAME_SCREEN;
    if (!loadMap(game, 1)) {
        printf("Error Loading Map\n");
        game->running = false;
    }


}
