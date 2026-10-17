#ifndef BOT_H
#define BOT_H
#include "utils.h"
#include "player.h"
#include "game.h"
#include <stdlib.h>
#include <stdio.h>

typedef short (*BotStrat)(struct GameInput *g, void* customData, struct Settings *s);

struct Bot{
    const char* name;
    BotStrat chooseMove;
    void* customData;
};

struct Bot bot_init(const char* name, BotStrat chooseMove, void* customData);

short bot_move(struct Bot *bot, struct GameInput *g, struct Settings *s);

// not part of the api
extern struct Bot defaultBots[3];
short strat_random(struct GameInput *g, void *custom_data, struct Settings *s);
short strat_callAll(struct GameInput *g, void *customData, struct Settings *s);
short strat_console(struct GameInput *g, void *custom_data, struct Settings *s);


#endif