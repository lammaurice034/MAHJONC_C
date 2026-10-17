#ifndef GAME_H
#define GAME_H
#include "utils.h"
#include "player.h"

struct ActionNode{ //node of a list of actions
    short player;
    short move;
    struct ActionNode *next; //DO NOT TOUCH
    struct ActionNode *prev;
};

struct Game{
    struct ActionNode *action_head;
    struct ActionNode *action_end;
    struct Player players[4];
    short availableTiles[144];
    short remainingTiles;
    short roundWind;
    short availableTilesPointer;
    short eastPlayer;
};

struct GameInput{
    struct ActionNode *action_head;
    struct ActionNode *action_end;
    short roundWind;
    short seatWind;
    short playerNum;
    short remainingTiles;
    struct Player self;
    struct Player upper;
    struct Player lower;
    struct Player opposite;
    struct ShortArr possibleMoves;
};

void game_init(struct Game *g);
void game_dispose(struct Game *g);
void game_masked_copy(struct Game *src, struct GameInput *dest, short playerPos, struct Settings *s);
void gameinput_dispose(struct GameInput *g);
void gameinput_copy(struct GameInput *dest, struct GameInput *src); // ASSUME DEST NOT INIT'D
void masked_copy_addAction(struct GameInput *g, short player, short move);

void game_list_faan(struct Faan **arr, struct Game *g, struct Settings *s);
void game_newGame(struct Game *g, char eastPlayer, char roundWind, struct Settings *s);
char game_valid_action(struct Game *g, short player, short move, struct Settings *s);
void game_addAction(struct Game *g, short player, short move, struct Settings *s);
char game_ended(struct Game *g, struct Settings *s);

char* gameStateToText(char *str, struct Game *g);
void textToGameState(struct Game *g, char* str, struct Settings *s); // assume g initd

void getDiscardedList(struct ShortArr *arr, struct ActionNode *head); // assumes arr initd
#endif