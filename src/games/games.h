#ifndef games_include_file
#define games_include_file

#define GAME_CALCULATION 0
#define GAME_FREECELL 1
#define NUM_GAMES 2

extern unsigned char (*setup[NUM_GAMES])();

unsigned char calculation_setup();
unsigned char freecell_setup();

#endif
