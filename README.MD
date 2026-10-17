  <!-- /\* Font Definitions \*/ @font-face {font-family:Wingdings; panose-1:5 0 0 0 0 0 0 0 0 0;} @font-face {font-family:PMingLiU; panose-1:2 2 5 0 0 0 0 0 0 0;} @font-face {font-family:Mangal; panose-1:2 4 5 3 5 2 3 3 2 2;} @font-face {font-family:"Cambria Math"; panose-1:2 4 5 3 5 4 6 3 2 4;} @font-face {font-family:"Aptos Display";} @font-face {font-family:Consolas; panose-1:2 11 6 9 2 2 4 3 2 4;} @font-face {font-family:"\\@PMingLiU"; panose-1:2 2 5 0 0 0 0 0 0 0;} /\* Style Definitions \*/ p.MsoNormal, li.MsoNormal, div.MsoNormal {margin-top:0cm; margin-right:0cm; margin-bottom:8.0pt; margin-left:0cm; font-size:11.0pt; font-family:"Times New Roman",serif;} p.MsoHeader, li.MsoHeader, div.MsoHeader {mso-style-link:"Header Char"; margin:0cm; font-size:11.0pt; font-family:"Times New Roman",serif;} p.MsoFooter, li.MsoFooter, div.MsoFooter {mso-style-link:"Footer Char"; margin:0cm; font-size:11.0pt; font-family:"Times New Roman",serif;} p.MsoListParagraph, li.MsoListParagraph, div.MsoListParagraph {margin-top:0cm; margin-right:0cm; margin-bottom:8.0pt; margin-left:36.0pt; font-size:11.0pt; font-family:"Times New Roman",serif;} p.MsoListParagraphCxSpFirst, li.MsoListParagraphCxSpFirst, div.MsoListParagraphCxSpFirst {margin-top:0cm; margin-right:0cm; margin-bottom:0cm; margin-left:36.0pt; font-size:11.0pt; font-family:"Times New Roman",serif;} p.MsoListParagraphCxSpMiddle, li.MsoListParagraphCxSpMiddle, div.MsoListParagraphCxSpMiddle {margin-top:0cm; margin-right:0cm; margin-bottom:0cm; margin-left:36.0pt; font-size:11.0pt; font-family:"Times New Roman",serif;} p.MsoListParagraphCxSpLast, li.MsoListParagraphCxSpLast, div.MsoListParagraphCxSpLast {margin-top:0cm; margin-right:0cm; margin-bottom:8.0pt; margin-left:36.0pt; font-size:11.0pt; font-family:"Times New Roman",serif;} span.HeaderChar {mso-style-name:"Header Char"; mso-style-link:Header; font-family:"Mangal",serif;} span.FooterChar {mso-style-name:"Footer Char"; mso-style-link:Footer; font-family:"Mangal",serif;} .MsoPapDefault {margin-bottom:8.0pt;} /\* Page Definitions \*/ @page WordSection1 {size:595.3pt 841.9pt; margin:72.0pt 72.0pt 72.0pt 72.0pt;} div.WordSection1 {page:WordSection1;} /\* List Definitions \*/ ol {margin-bottom:0cm;} ul {margin-bottom:0cm;} -->

**1\. Project Overview**

            This project, MAHJONG\_C, aims to provide a framework library for bot development on Hong Kong Mahjong as well as an emulation platform for said bots to play against each other. With various customizable options such as custom _faan_ scoring, whether the game uses flower tiles, along with a console and a GUI mode for the emulation, as well as the functionality of which the human user can play against other bots, this lightweight emulator and library project provides for both the back-end bot developers and the players of the game.

            The library, written exclusively in C, comes in two versions: a Linux-compatible distribution and a Windows-compatible distribution. The emulator application similarly is desigend to be cross-platform functional as well. The GUI portion of this project was written in Java. As such, the whole project is designed to run seamlessly regardless of your operating system.

**1.1**   **System Requirements**

\-        Operating System: Windows, Linux or MacOS.

\-        C Standards: C99 or later.

\-        Compilers: GCC (tested).

\-        Dependencies: None.

\-        (Optional, for GUI only): Java 8 or later.

**2\. Emulator Documentation**

The emulator is designed to be compatible with Windows and Linux distributions. To launch the application, change the directory of your command console to ./MAHJONG\_C, then launch using the command line below:

./MAHJC <gui=value> \[pauses=value\] \[maxrounds=value\] \[p0=value\] \[p1=value\] \[p2=value\] \[p3=value\]

(replace “MAHJC” with “MAHJC.EXE” if you are running on a Windows machine.)

Explanation of the parameters:

\-        <gui>: Required. 0 to launch under console mode, and 1 to launch with GUI. The user interface utilizes Java Swing and requires your machine to have JRE installed.

\-        Optional parameters for when using console mode (these could be configured in the GUI when gui=1):

o   \[pauses\]: Pauses between moves while emulating if pauses=1. Default=0.

o   \[maxrounds\]: Maximum rounds of games to emulate before exiting. Default=4.

o   \[gameStatusFile\]: File path to a previously saved game state. If left blank, a new game will be generated as usual.

o   \[p0\] to \[p3\]: Index of bots to use for emulation for non-GUI mode, for players #0 to #3 respectively. Default=0.

**2.1 Loading Bots for Emulation**

Once you have custom bot plugin .dll and/or .so file(s) (see ‘4. Creating Your Own Bot’ for details on bot development), place them in the PLUGINS folder. When the emulator is launched, depending on your machine’s platform, only .dll or .so files would be loaded automatically. To see what bots have been loaded, use MAHJC ? to get the help screen along with the list of indicies and names of bots. The emulator supports having 256 bots loaded within one instance.

There are also three default options, ‘Random’, ‘User Input’ and ‘Call Everything’, always occupying the first three indicies respectively. ‘Random’ selects any valid move at random, ‘Call Everything’ executes the move with the largest action code, while ‘User Input’ allows the user to make an inputting move on either the console or the GUI. Please be advised that having more than one ‘User Input’ player is only allowed in console mode and not GUI mode.

**2.1.1 Operating the ‘User Input’ bot**

            In console mode, whenever it is the user’s turn, the emulation pauses untill the it receives an numerical input representing the move. The list of legitimate codes will be displayed on screen along a description of the action. It is imperative to note that entering invalid values might cause unexpected behaviours.

            In GUI mode, if there is one user input bot in play, you will not be able to view the game from other players’ prespectives. Instead, you can play the game by clicking on the tile you wish to discard or buttons to form a meld, to win a game, or skip as applicable.

**2.2 Saving and Restoring Game Status**

            You might wish to export the game status for debugging puposes or have it continued in the future. Exporting a game status file is only available in GUI mode; while loading a game status file to have the bots continue from that position is available under both GUI and console modes. Restoring a game status in GUI mode will immediately override the ongoing game, while having  \[gameStatusFile\] set to your file path will result in the emulation of that game repeatedly. Please note that it is not necessary for you to select the same bots to continue playing from the game status file as the ones who achieved that position.

**2.3 Game Settings**

            To modify settings of the game such as minimum _faan_ requirements, points of each hand, whether the game plays with flowers, etc., access and modfiy MAHJONGC/settings.csv as deemed fit.

**3\. Library Documentation**

**3.1 Installing the Library**

            The library is designed to be portable. To include in your project, make a copy of the MahjC\_SDK\_WIN or MahjC\_SDK\_LINUX folder in your working directory.

Working Directory/

├── yourBotAlgorithm.c

└── MahjC\_SDK(\_WIN or \_LINUX)/

├── bot.h

├── game.h

├── libmahjong.a

├── mahjong\_c.h

├── player.h  
└── utils.h

_Exhibit 3.1: Sample directory tree_

See ‘4.3 Compiling your Bot Plugin’ for instructions on compiling your bots and ‘2.1 Loading Bots for Emulation’ for loading your newly built bots.

**3.2 Usage**

Calling #include “mahjong\_c.h” automatically includes all header files required in the library. The following pages includes documentation on public functions and constant declarations for bot development; there are also other undocumented functions available within the header files that are intended for internal use only.

The four header files are as listed below:

\-        UTILS.H

\-        PLAYER.H

\-        GAME.H

\-        BOT.H.

**3.3.1 Code Documentation - UTILS.H**

Tiles, melds & actions constants:

\-        All tiles, melds, and actions are stored as short types. The lowest 4 bits are for the tile number/rank, then 3 bits for the suit, 2 bit for the meld type and the uppermost 2 bits for the action, if applicable.

\-        For instance, the 7 of Bamboo is BAMBOO|7 = 39. The honour tiles, East, South, West, North, Red Dragon, Green Dragon, White Dragon, are stored as HONOUR|1 through 7 respectively. The red flowers 1 to 4 and the blue flowers 1 to 4 are FLOWER|1 through 4 and FLOWER|5 through 8 respectively.

\-        A pong of east winds = PONG|EAST, and a chow of 5-6-7 Circle is CHOW|CIRCLE|5, with the number 5 indicating the meld’s tile with the smallest rank.

\-        To indicate the action of discarding a 5 of Bamboo, the code will be DISCARD|BAMBOO|5; and to claim a Chow of 1-2-3 of Myraids from a discarded 2, the code is CALL|CHOW|MYRIAD|2.

\-        The enum values are as follows:

o       CIRCLE – 16, BAMBOO – 32, MYRIAD – 48, HONOUR – 64, FLOWER – 80

o       EAST, SOUTH, WEST, NORTH, RED, GREEN, WHITE – HONOUR|1 to 7 respectively

o       RED\_FLOWER\_1, RED\_FLOWER\_2, RED\_FLOWER\_3, RED\_FLOWER\_4 – FLOWER|1 to 4 respectively

o       BLUE\_FLOWER\_1, BLUE\_FLOWER\_2, BLUE\_FLOWER\_3, BLUE\_FLOWER\_4 – FLOWER|5 to 8 respectively

o       CHOW – 128, PONG – 256, KONG – 384

o       IGNORE – 0, DRAWTILE – 512, DISCARD – 1536, WIN – 2048, WIN\_FROM\_FLOWERS – 2049

\-        Const short ORPHANS\[\] includes all 13 orphan tiles (i.e. 1, 9 of all suits and all honour tiles).

Scoring (_Faan_):

\-        struct Faan: stores the scoring criteria name and points that it awards if achieved. Variable names within the struct as below:

o       const char \*id

o       short points

\-        const short total\_point\_types: how many available _faan_ criterias there are.

\-        void listPointTypes(struct Faan \*\*arr, struct Player \*p, short roundWind, char winByFlowers, char selfPick, char robbedKong, char winAfterKongs, char winOnStart, struct Settings \*s): modifies \*\*arr. arr should be defined as struct Faan \*arr\[total\_point\_types\]. This would then be modified to include a list of qualifying _faans_ and trailing NULLs if applicable. This also assumes the hand the player has is a legitimate winning hand.

\-        short calcPoints(struct Faan \*\*arr): returns the calculated amount of _faans_ in the winning hand. Feed the output value from above only.

\-        struct Settings: a list of adjustable settings, including the minimum requirement and maximum points of a winning hand, whether the game includes flower tiles and how many _faan_ per each scoring criteria. All customisable and will automatically be loaded from ‘settings.csv’ by the emulator at launching of the application. Variables included as below:

o       char PLAY\_WITH\_FLOWERS

o       short POINTS\_CAP

o       short POINTS\_MIN

o       struct Faan POINTS\_13\_ORPHANS

o       struct Faan POINTS\_ALL\_CHOWS

o       struct Faan POINTS\_ALL\_PONGS

o       struct Faan POINTS\_ALL\_KONGS

o       struct Faan POINTS\_ALL\_CONCEALED\_PONGS

o       struct Faan POINTS\_MIXED\_SUIT

o       struct Faan POINTS\_CLEAN\_SUIT

o       struct Faan POINTS\_ALL\_HONOURS

o       struct Faan POINTS\_MIXED\_ORPHANS

o       struct Faan POINTS\_CLEAN\_ORPHANS

o       struct Faan POINTS\_NINE\_GATES

o       struct Faan POINTS\_SEAT\_WIND

o       struct Faan POINTS\_ROUND\_WIND

o       struct Faan POINTS\_RED\_DRAGON

o       struct Faan POINTS\_GREEN\_DRAGON

o       struct Faan POINTS\_WHITE\_DRAGON

o       struct Faan POINTS\_LITTLE\_DRAGONS

o       struct Faan POINTS\_GREAT\_DRAGONS

o       struct Faan POINTS\_LITTLE\_WINDS

o       struct Faan POINTS\_GREAT\_WINDS

o       struct Faan POINTS\_NO\_FLOWERS

o       struct Faan POINTS\_OWN\_RED\_FLOWER

o       struct Faan POINTS\_OWN\_BLUE\_FLOWER

o       struct Faan POINTS\_ALL\_RED\_FLOWERS

o       struct Faan POINTS\_ALL\_BLUE\_FLOWERS

o       struct Faan POINTS\_SEVEN\_FLOWERS

o       struct Faan POINTS\_EIGHT\_FLOWERS

o       struct Faan POINTS\_ALL\_CONCEALED

o       struct Faan POINTS\_SELF\_PICK

o       struct Faan POINTS\_LAST\_TILE

o       struct Faan POINTS\_WIN\_ON\_START

o       struct Faan POINTS\_ROB\_KONG

o       struct Faan POINTS\_AFTER\_KONG

o       struct Faan POINTS\_AFTER\_DOUBLE\_KONG

ShortArr (Custom array of shorts with dynamic size):

\-        struct ShortArr: able to store a list of data (shorts) of dynamic size. Resizes automatically. Variables within the struct are as below:

o       short\* data

o       int size

o       _Note that it is not necessary to manually manipulate these values. Please use the provided functions as below._

\-        void arr\_init(struct ShortArr \*arr): initializes the ShortArr.

\-        void arr\_init\_zeros(struct ShortArr \*arr, short count): initalizes array with prefilled amount of zeros.

\-        void arr\_dispose(struct ShortArr \*arr): disposes the array and frees up memory.

\-        short arr\_remove(struct ShortArr \*arr, int pos): removes item at specific index. Returns the value of removed item.

\-        void arr\_add(struct ShortArr \*arr, short data, int pos): inserts item at specific index. All items with index >= pos in the original array will have their indices increased by one.

\-        void arr\_append(struct ShortArr \*arr, short data): adds an item at the end of the list.

\-        short arr\_get(struct ShortArr \*arr, int pos): returns value of item at a certain index.

\-        int arr\_count(struct ShortArr \*arr, short data): returns the count of instances of an item.

\-        short arr\_minIdx(struct ShortArr \*arr): returns the index of the smallest item in the list.

\-        short arr\_maxIdx(struct ShortArr \*arr): returns the index of the largest item in the list.

\-        void arr\_scale(struct ShortArr \*arr, short scalor): all items within the list is multiplied by the scalor.

\-        void arr\_vectorAdd(struct ShortArr \*src, struct ShortArr \*dest): assuming \*src and \*dest have the same amount of items, dest\[i\] = src\[i\] + dest\[i\] for all indicies.

\-        void arr\_remove\_instances(struct ShortArr \*arr, short data, int count): removes the first # instances from the array.

\-        void arr\_copy(struct ShortArr \*src, struct ShortArr \*dest): assuming \*dest is already initialized, the function clears \*dest and all items in \*src will be copied over to \*dest with the same order.

\-        void arr\_set(struct ShortArr \*arr, int pos, short data): changes value of an item at the specified index.

\-        void arr\_swap(struct ShortArr \*arr, int index1, int index2): within the array, values at index1 and index2 will be swapped.

\-        void arr\_sort(struct ShortArr \*arr): sorts the array in ascending order.

\-        void arr\_clear(struct ShortArr \*arr): sets \*arr.size to 0 and clears all data.

\-        void arr\_removeDuplicates(struct ShortArr \*arr): all duplicated items are removed except the first instance.

Getter functions:

\-        short getSuit(short s): returns either CIRCLE, BAMBOO, MYRIAD, HONOUR or FLOWER of the provided tile/meld/action.

\-        short getTileNum(short s): returns a value from 1-9 indicating the numerical value of the tile/tile with lowest number in the meld/action regarding that tile. 1-7 for East, South, West, North, Red Dragon, Green Dragon and White Dragon respectively for honours, 1-4 for red flowers and 5-8 for blue flowers.

\-        short getTile(short s): returns getSuit(s) && getTileNum(s), i.e. the numerical representative of the smallest tile within the meld or the action regarding it.

\-        short getMeldType(short s): returns CHOW, PONG or KONG provided s is a meld or a calling action.

\-        short getActionType(short s): returns IGNORE, DRAWTILE, DISCARD, CALL or WIN provided s is an action. Note that getActionType(WIN\_FROM\_FLOWERS) returns WIN.

\-        short upperSeat(short tile): input must be EAST, SOUTH, WEST or NORTH; returns the previous wind of the parameter (e.g. upperSeat(SOUTH) à EAST).

\-        short lowerSeat(short tile): input must be EAST, SOUTH, WEST or NORTH; returns the proceeding wind of the parameter (e.g. lowerSeat(NORTH) à EAST).

\-        short oppositeSeat(short tile) input must be EAST, SOUTH, WEST or NORTH; returns the opposite wind of the parameter (e.g. oppositeSeat(EAST) à WEST).

\-        struct ShortArr listAllTiles(short meld): returns a ShortArr with either 3 or 4 tiles representing the tiles that makes up the meld.

Value validation functions:

\-        char isOrphan(short tile): returns 1 if tile is an honour, or is 1 or 9 of circles, bamboo or myriads. 

\-        char is13Orphans(struct ShortArr \*arr): returns 1 if arr is the concealed hand of a valid winning 13 Orphans hand.

\-        short canFormMeld(short tile1, short tile2, short tile3): returns the meld the three tiles could form if those three tiles can form a valid meld. 0 otherwise.

\-        char canWin(struct ShortArr \*concealed\_hand): Checks whether the concealed hand is a valid winning hand regardless of _faan_ requirements.

Miscellaneous:

\-        void printTile(short x): prints a two character code to the console indicating the tile: first character indicating the suit and the second indicating the numerical value. E.g. M3 = 3 of Myraids, H4 = North.

\-        void printPlayer(struct Player \*p): prints out all data regarding the player to console.

\-        int max(int a, int b): returns the larger of a and b.

\-        int min(int a, int b): returns the smaller of a and b.

**3.3.2 Code Documentation - PLAYER.H**

struct Player: stores all information regarding a player’s hand. Contains:

\-        short seat (could be EAST, SOUTH, WEST or NORTH, for the seat wind of the player)

\-        struct ShortArr concealedHand (an array of numbers indicating the concealed hand)

\-        struct ShortArr exposedHand (an array of numbers indicating the melds exposed)

\-        struct ShortArr flowers (an array of numbers showing all flowers drawn by the player)

void player\_init(struct Player \*p, short seat): initializes \*p to be usable.

void player\_dispose(struct Player \*p): frees memory used to store \*p.

void player\_copy(struct Player \*src, struct Player \*dest): copies all data from src to dest.

char player\_drawtile(struct Player \*p, short tile): adds tile to p’s concealed hand. Returns 0 if tile is a flower.

char player\_discard(struct Player \*p, short tile): removes tile from the concealed hand. Returns 1 if tile successfully removed; 0 if not.

char player\_canCall(struct Player \*p, short meld, short discardedTile, short fromSeat): see if the player can form the exposed meld meld as player with seat wind fromSeat discards discardedTile. Returns 1 if true, 0 if not.

char player\_call(struct Player \*p, short meld, short discardedTile, short fromSeat): similar to above, but this modifies \*p.concealedHand and \*p.exposedHand to mimmick calling of the meld. Returns 1 if successful; 0 if not.

void player\_reset(struct Player \*p, short seat): clear all the arrays within the struct player and assign a new seat wind for the player.

void player\_sortConcealed(struct Player \*p): sorts the concealed hand of the player.

**3.3.3 Code Documentation - GAME.H**

struct ActionNode: an item node within a list of actions. Contains:

\-        short player (0-3, indicating which player did the action)

\-        short move (The action code)

\-        struct ActionNode \*next (Action performed before, could be NULL). Do not modify manually.

\-        struct ActionNode \*prev (Action performed after, could be NULL). Do not modify manually.

struct GameInput: all the information available to a player during a point in the game where the player is required to make a move. Contains:

\-        struct ActionNode \*action\_head (First action performed after the initial dealing of tiles, could be NULL)

\-        struct ActionNode \*action\_end (Most recent action performed after the initial dealing of tiles, could be NULL)

\-        short roundWind (could either be EAST, SOUTH, WEST or NORTH. Indicates which round the game is in.)

\-        short seatWind (same as above; could be EAST, SOUTH, WEST or NORTH, for the player’s seat wind)

\-        short playerNum (0-3, indicating which player are you playing as)

\-        short remainingTiles (amount of remaining tiles undrawn)

\-        struct Player self (contains information regarding your own hand)

\-        struct Player upper, lower, opposite (struct Player’s containing information regrading each player’s hands. Note all these players have their concealed hands masked)

\-        struct ShortArr possibleMoves (A list of all possible moves to be made)

void gameinput\_dispose(struct GameInput \*g): disposes pointer g to free up memory. Note: within your bot strategy function, you will receive struct GameInput \*g as one of the parameters from the emulator. The emulator will automatically clean up the memory and it is unnecessary to call this function in that scenario.

void gameinput\_copy(struct GameInput \*dest, struct GameInput \*src): makes a clean copy to dest. This works assuming \*dest is not initialized.

**3.3.4 Code Documentation - BOT.H**

Building blocks for a bot:

\-        typedef short (\*BotStrat)(struct GameInput \*g, void\* customData): the format of your main strategy function. It should take two parameters, GameInput \*g for all the information available during a certain point in the game, and void\* customData, any extra customizations your algorithm might depend on. This returns a short value representing the move that the bot takes.

\-        struct Bot: contains 3 parameters as below:

o   const char\* name: name of the bot

o   BotStrat chooseMove: your strategy function

o   void\* customData: extra parameters for your bot if needed (could be NULL)

\-        struct Bot bot\_init(const char\* name, BotStrat chooseMove, void\* customData): function to create a struct Bot with the respective parameters.

static struct Bot defaultBots\[\]: contains 3 bots, as below:

\-        defaultBots\[0\]: allows the user to manually input a move

\-        defaultBots\[1\]: plays a random valid move

\-        defaultBots\[2\]: tries to win if possible; if not, tries to call any tiles it can

See ‘4. Creating Your Own Bot’ for more details.

**4\. Creating Your Own Bot**

            Prior to developing your first bot, you will need to include the library in your working directory. See ‘3.1 Installing the Library’ for installation instructions.

**4.1 Code requirements**

A custom bot takes the form of a struct Bot, of which it contains 3 variables: const char\* name, BotStrat chooseMove and void\* customData. name would be the displaying name of your bot, chooseMove being a function that returns a short indicating the action it desires to take and customData is a void pointer for any custom data such as parameters the bots would use, if needed. ‘Code Documentation – BOTS.H’ contains more detailed information regarding operations on struct Bot.

            To create your own bot, you must compile a plugin file (.DLL or .SO for Windows and Linux respectively), which would then be loaded by the emulator dynamically. This plugin file, compiled from a .c file, must contain a static array under the identifier static struct Bot bots\[\], which would be the array of all available bots in your plugin. This array must also end with a sentinel value {NULL, NULL, NULL}.

static struct Bot bots\[\] = {

{"MY BOT #1", mybot\_strat\_1, NULL},

{"MY BOT #2", mybot\_strat\_2, &someParameterVar},

{NULL, NULL, NULL} // KEEP AT END  
};

_Exhibit 4.1: Sample of array of bots available in your plugin_

            In addition, this snippet of the code is also required for the emulator to load plugins properly:

#ifdef \_WIN32

\_\_declspec(dllexport)

#endif

const struct Bot \*mahjong\_bot\_init(void){return bots;}

_Exhibit 4.2: Sample of array of bots available in your plugin_

**4.2 Bot Strategy Function**

            Your strategy function, with type declared as typedef short (\*BotStrat)(struct GameInput \*g, void\* customData, struct Settings \*s);, will take three parameters. g passes all available details regarding the game for your bot to decide on an action; while custom\_data points to any configurations you might have set. s is a list of game rules applied on the game such as minimum points requirement (see ‘3.3.1 Code Documentation – UTILS.H’ for further information).

short strat\_random(struct GameInput \*g, void \*custom\_data, struct Settings \*s){

return arr\_get(&(g->possibleMoves),

rand() % g->possibleMoves.size);  
}

_Exhibit 4.3: The main strategy function for playing randomly_

Shall the strategy function return an invalid value (i.e. a value not listed in g->possibleMoves, the action with the smallest code will be executed automatically.

**4.2.1 Remarks on Memory Management**

There is no need for memory management regarding GameInput \*g, i.e. do not call gameinput\_dispose() on g. This applies to Settings \*s as well. You shan’t be concerned about integrity of the data within \*g as it is disposed in the emulator loop immediately after your bot returns a move (i.e. you might modify data within \*g as deem required). Any other variables that you have initialized during the calculation process, however, would require cleaning up; the emulator is not set up to prevent memory leaks from user-created bots.

While the emulator also did not provide a reliable way of disposing \*custom\_data on closing of the application, it is notable that modern operating systems are able to handle that and should not cause a memory leak. This issue is acknowledged by the developer and it poses no pratical troubles.

**4.3 Compiling your Bot Plugin**

            To compile, launch the following commands from your working directory depending on which platform your machine is on:

\-        Windows: gcc -shared -o \[botPackageName\].dll \[yourFiles\].c -I MahjC\_SDK\_WIN -L MahjC\_SDK\_WIN -lmahjong

\-        Linux: gcc -shared -fPIC -o \[botPackageName\].so \[yourFiles\].c -I  Mahjc\_SDK\_LINUX -L Mahjc\_SDK\_LINUX -lmahjong

            Once you have your .dll or .so file(s) ready, refer to ‘2.1 Loading Bots for Emulation’.

_See also: Appendix 6.1 for sample code._

**5\. Credits and Acknowledgements**

MAHJONC\_C: HK Mahjong emulator and bot development framework.

Created by Maurice Lam, 2026.

Licensed under CC BY-SA 4.0.

Certain images have been adapted from the below sources in creation of the tiles used in the GUI:

Cangjie6 (2022). Kanji var mj.svg \[Image\]. Wikimedia Commons. https://commons.wikimedia.org/wiki/File:Kanji\_var\_mj.svg. Licensed under CC BY-SA 4.0.

**6\. Appendix**

**6.1 Sample project code**

MyBotCollection/

├── myBots.c

└── MahjC\_SDK\_WIN/

├── bot.h

├── game.h

├── libmahjong.a

├── mahjong\_c.h

├── player.h  
└── utils.h

_Exhibit 6.1: Sample directory tree_

myBots.c:

#include "mahjong\_c.h"

#include "<stdlib.h>"

// custom strat functions - must take in these 3 parameters

short strat\_A(struct GameInput \*g, void \*custom\_data, struct Settings \*s){

    // returns a random valid move

    return arr\_get(&(g->possibleMoves), rand() % g->possibleMoves.size);    

}

short strat\_B(struct GameInput \*g, void \*custom\_data, struct Settings \*s){

    // returns the legal move with the largest action code if \*custom\_data = 0, smallest otherwise

    if((int)\*custom\_data){

        return arr\_get(&(g->possibleMoves), g->possibleMoves.size-1);

    }

    return arr\_get(&(g->possibleMoves), 0);

}

// Parameters for Bot B

int param\_B1 = 0;

int param\_B2 = 1;

// all available bots in this plugin

static struct Bot bots\[\] = {

    {"Bot A", strat\_A, NULL},

    {"Bot B1", strat\_B, &param\_B1},

    {"Bot B2", strat\_B, &param\_B2},

    {NULL, NULL, NULL} // KEEP THIS SENTINEL AT THE END

};

// required snippet for proper plugin loading

#ifdef \_WIN32

\_\_declspec(dllexport)

#endif

const struct Bot \*mahjong\_bot\_init(void){return bots;}

_Exhibit 6.2: Code of myBots.c_