#ifndef graphics_include_file
#define graphics_include_file

#define COLOR_WHITE 0
#define COLOR_BLACK 1
#define COLOR_GREEN 2
#define COLOR_RED 3
#define COLOR_BLUE 4
#define COLOR_ORANGE 5

#define CARD_WIDTH 33
#define CARD_HEIGHT 45
#define CARD_BEZEL 2

extern const unsigned char suitColors[4];

void drawBackground();
void drawGame();

#endif
