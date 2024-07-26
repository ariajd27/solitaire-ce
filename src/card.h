#ifndef card_include_file
#define card_include_file

#include <graphics.h>

#define NUM_CARDS 52

#define VALUE_ACE 1
#define VALUE_JACK 11
#define VALUE_QUEEN 12
#define VALUE_KING 13

#define SUIT_HEARTS 0
#define SUIT_CLUBS 1
#define SUIT_DIAMONDS 2
#define SUIT_SPADES 3

void initCardSprites();

struct card_t
{
	unsigned char exists : 1;
	unsigned char faceUp : 1;
	unsigned char suit : 2;
	unsigned char value : 4;
};

void drawCard(const unsigned int x, const unsigned char y, const struct card_t card);
void drawPattern(const unsigned int x, const unsigned char y, const struct card_t card);

#endif
