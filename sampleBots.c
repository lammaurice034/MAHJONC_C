/*
MAHJONG_C - Sample Bot Code
See README.MD for details on compiling and importing bots.
*/

#include "mahjong_c.h"
#include <stdlib.h>

// custom strat functions - must take in these 3 parameters
short strat_A(struct GameInput *g, void *custom_data, struct Settings *s){
    // returns a random valid move
    return arr_get(&(g->possibleMoves), rand() % g->possibleMoves.size);    
}

short strat_B(struct GameInput *g, void *custom_data, struct Settings *s){
    // returns the legal move with the largest action code if *custom_data = 0, smallest otherwise
    if(*(int*)custom_data){
        return arr_get(&(g->possibleMoves), g->possibleMoves.size-1);
    }
    return arr_get(&(g->possibleMoves), 0);
}

// Parameters for Bot B
int param_B1 = 0;
int param_B2 = 1;

// all available bots in this plugin
static struct Bot bots[] = {
    {"Bot A", strat_A, NULL},
    {"Bot B1", strat_B, &param_B1},
    {"Bot B2", strat_B, &param_B2},
    {NULL, NULL, NULL} // KEEP THIS SENTINEL AT THE END
};

// required snippet for proper plugin loading
#ifdef _WIN32
__declspec(dllexport)
#endif
const struct Bot *mahjong_bot_init(void){return bots;}
