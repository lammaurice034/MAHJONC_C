#ifndef UTILS_H
#define UTILS_H

struct Player;
struct Game;
// settings

// constants
/*
To get a tile, do SUIT | NUMBER, 
e.g. BAMBOO | 7 == 7 of Bamboo
or the other constants for honours/flowers.

To get a set of 3 (a meld), 
if a pong/kong: do PONG/KONG | TILE, e.g. PONG | EAST = pong of east
if a chow: do CHOW | TILE, with TILE being the piece with the smallest #
e.g. CHOW | CIRCLE | 5 = Chow consisting 5, 6, 7 of Circles

2 bits for action - 2 bits for meld type - 3 bits for suit - 4 bits for tile #
*/
enum{
    CIRCLE = 16,
    BAMBOO = 32,
    MYRIAD = 48,
    HONOUR = 64,
    FLOWER = 80,

    EAST = HONOUR | 1,
    SOUTH = HONOUR | 2,
    WEST = HONOUR | 3,
    NORTH = HONOUR | 4,
    RED = HONOUR | 5,
    GREEN = HONOUR | 6,
    WHITE = HONOUR | 7,

    RED_FLOWER_1 = FLOWER | 1,
    RED_FLOWER_2 = FLOWER | 2,
    RED_FLOWER_3 = FLOWER | 3,
    RED_FLOWER_4 = FLOWER | 4,
    BLUE_FLOWER_1 = FLOWER | 5,
    BLUE_FLOWER_2 = FLOWER | 6,
    BLUE_FLOWER_3 = FLOWER | 7,
    BLUE_FLOWER_4 = FLOWER | 8,

    CHOW = 128,
    PONG = 256,
    KONG = 384,

    IGNORE = 0,
    DRAWTILE = 512,
    DISCARD = 1024,
    CALL = 1536,
    WIN = 2048,
    WIN_FROM_FLOWERS = 2049
};

extern const short ORPHANS[];

// scoring
extern const short total_point_types;
struct Faan{
    const char *id; short points;
};
struct Settings{
    char PLAY_WITH_FLOWERS;
    short POINTS_CAP;
    short POINTS_MIN;
    struct Faan POINTS_13_ORPHANS;
    struct Faan POINTS_ALL_CHOWS;
    struct Faan POINTS_ALL_PONGS;
    struct Faan POINTS_ALL_KONGS;
    struct Faan POINTS_ALL_CONCEALED_PONGS;
    struct Faan POINTS_MIXED_SUIT;
    struct Faan POINTS_CLEAN_SUIT;
    struct Faan POINTS_ALL_HONOURS;
    struct Faan POINTS_MIXED_ORPHANS;
    struct Faan POINTS_CLEAN_ORPHANS;
    struct Faan POINTS_NINE_GATES;
    struct Faan POINTS_SEAT_WIND;
    struct Faan POINTS_ROUND_WIND;
    struct Faan POINTS_RED_DRAGON;
    struct Faan POINTS_GREEN_DRAGON;
    struct Faan POINTS_WHITE_DRAGON;
    struct Faan POINTS_LITTLE_DRAGONS;
    struct Faan POINTS_GREAT_DRAGONS;
    struct Faan POINTS_LITTLE_WINDS;
    struct Faan POINTS_GREAT_WINDS;
    struct Faan POINTS_NO_FLOWERS;
    struct Faan POINTS_OWN_RED_FLOWER;
    struct Faan POINTS_OWN_BLUE_FLOWER;
    struct Faan POINTS_ALL_RED_FLOWERS;
    struct Faan POINTS_ALL_BLUE_FLOWERS;
    struct Faan POINTS_SEVEN_FLOWERS;
    struct Faan POINTS_EIGHT_FLOWERS;
    struct Faan POINTS_ALL_CONCEALED;
    struct Faan POINTS_SELF_PICK;
    struct Faan POINTS_LAST_TILE;
    struct Faan POINTS_WIN_ON_START;
    struct Faan POINTS_ROB_KONG;
    struct Faan POINTS_AFTER_KONG;
    struct Faan POINTS_AFTER_DOUBLE_KONG;
};
extern struct Settings defaultSettings;

// misc functions
short getSuit(short s);
short getTileNum(short s);
short getTile(short s);
short getMeldType(short s);
short getActionType(short s);

short upperSeat(short tile);
short lowerSeat(short tile);
short oppositeSeat(short tile);
int max(int a, int b);
int min(int a, int b);
char isOrphan(short tile);

void printTile(short x);
void printPlayer(struct Player *p);

struct ShortArr listAllTiles(short meld);
char is13Orphans(struct ShortArr *arr);

short canFormMeld(short tile1, short tile2, short tile3); // returns the meld it's forming if yes; 0 if no
char canWin(struct ShortArr *concealed_hand); // only checking if concealed hand is a winning hand

void listPointTypes(struct Faan **arr, struct Player *p, short roundWind, char winByFlowers, char selfPick, char robbedKong, char winAfterKongs, char winOnStart, struct Settings *s);
short calcPoints(struct Faan **arr); // FEED PARAMETERS FROM ABOVE
short readSettings(char*);

// array stuff
struct ShortArr{
    short* data;
    int size; 
};
void arr_init(struct ShortArr *arr);
void arr_init_zeros(struct ShortArr *arr, short count);
short arr_remove(struct ShortArr *arr, int pos);
void arr_add(struct ShortArr *arr, short data, int pos);
short arr_get(struct ShortArr *arr, int pos);
void arr_append(struct ShortArr *arr, short data);
int arr_count(struct ShortArr *arr, short data);
short arr_minIdx(struct ShortArr *arr);
short arr_maxIdx(struct ShortArr *arr);
void arr_scale(struct ShortArr *arr, short scalor);
void arr_vectorAdd(struct ShortArr *src, struct ShortArr *dest);
void arr_remove_instances(struct ShortArr *arr, short data, int count);
void arr_dispose(struct ShortArr *arr);
void arr_copy(struct ShortArr *src, struct ShortArr *dest);
void arr_set(struct ShortArr *arr, int pos, short data);
void arr_swap(struct ShortArr *arr, int index1, int index2);
void arr_sort(struct ShortArr *arr);
void arr_clear(struct ShortArr *arr);
void arr_removeDuplicates(struct ShortArr *arr);

#endif