#ifndef PLAYER_H
#define PLAYER_H
#include "utils.h"

struct Player{
    short seat;
    struct ShortArr concealedHand;
    struct ShortArr exposedHand;
    struct ShortArr flowers;
};

void player_init(struct Player *p, short seat);
void player_copy(struct Player *src, struct Player *dest);
void player_dispose(struct Player *p);
char player_drawtile(struct Player *p, short tile); // returns 0 if flower drawn; 1 if not
char player_discard(struct Player *p, short tile); // 1 if successful; 0 if not
char player_canCall(struct Player *p, short meld, short discardedTile, short fromSeat);
char player_call(struct Player *p, short meld, short discardedTile, short fromSeat); // returns 1 if successful; 0 if not
void player_reset(struct Player *p, short seat);    
void player_sortConcealed(struct Player *p);
#endif