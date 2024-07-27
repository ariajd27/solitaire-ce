#include <graphx.h>

#include "gfx/gfx.h"
#include "graphics.h"
#include "card.h"

#define CARD_BACK_HOFFSET 2
#define CARD_BACK_VOFFSET 2

#define FACE_CARD_RECT_HOFFSET 7
#define FACE_CARD_RECT_VOFFSET 6
#define FACE_CARD_RECT_WIDTH 19
#define FACE_CARD_RECT_HEIGHT 33
#define FACE_CARD_ART_HOFFSET 3
#define FACE_CARD_ART_VOFFSET 3

#define TOP_CORNER_DIGIT_HOFFSET 2
#define TOP_CORNER_DIGIT_VOFFSET 3
#define BOTTOM_CORNER_DIGIT_HOFFSET 26
#define BOTTOM_CORNER_DIGIT_VOFFSET 38
#define TOP_CORNER_SYMBOL_HOFFSET 3
#define TOP_CORNER_SYMBOL_VOFFSET 8
#define BOTTOM_CORNER_SYMBOL_HOFFSET 22
#define BOTTOM_CORNER_SYMBOL_VOFFSET 33
#define ACE_SYMBOL_HOFFSET 11
#define ACE_SYMBOL_VOFFSET 17

gfx_rletsprite_t *faceSprites[12];
gfx_sprite_t *digitSprites[11];
gfx_sprite_t *aceSprites[4];
gfx_sprite_t *smallSymbols[4];

void initCardSprites()
{
	faceSprites[0] = jack_hearts;
	faceSprites[1] = queen_hearts;
	faceSprites[2] = king_hearts;
	faceSprites[3] = jack_clubs;
	faceSprites[4] = queen_clubs;
	faceSprites[5] = king_clubs;
	faceSprites[6] = jack_diamonds;
	faceSprites[7] = queen_diamonds;
	faceSprites[8] = king_diamonds;
	faceSprites[9] = jack_spades;
	faceSprites[10] = queen_spades;
	faceSprites[11] = king_spades;

	digitSprites[1] = digit_ace;
	digitSprites[2] = digit_two;
	digitSprites[3] = digit_three;
	digitSprites[4] = digit_four;
	digitSprites[5] = digit_five;
	digitSprites[6] = digit_six;
	digitSprites[7] = digit_seven;
	digitSprites[8] = digit_eight;
	digitSprites[9] = digit_nine;
	digitSprites[10] = digit_ten;

	aceSprites[0] = heart_large;
	aceSprites[1] = club_large;
	aceSprites[2] = diamond_large;
	aceSprites[3] = spade_large;

	smallSymbols[0] = heart_small;
	smallSymbols[1] = club_small;
	smallSymbols[2] = diamond_small;
	smallSymbols[3] = spade_small;
}

void drawCard(const unsigned int x, const unsigned char y, const struct card_t card)
{
	// draw the blank card
	gfx_SetColor(COLOR_WHITE);
	for (unsigned char dy = 0; dy < CARD_HEIGHT; dy++)
	{
		unsigned char rowBezel;
		if (dy < CARD_BEZEL) rowBezel = CARD_BEZEL - dy;
		else if (dy >= CARD_HEIGHT - CARD_BEZEL) rowBezel = dy + CARD_BEZEL + 1 - CARD_HEIGHT;
		else rowBezel = 0;

		gfx_HorizLine(x + rowBezel, y + dy, CARD_WIDTH - 2 * rowBezel);
	}

	if (!card.faceUp)
	{
		gfx_Sprite(card_back, x + CARD_BACK_HOFFSET, y + CARD_BACK_VOFFSET);
	}
	else if (card.value >= VALUE_JACK)
	{
		// just draw the face; the corners are included

		// this is to draw the box on face cards-- currently removed but
		// could be worth putting in later for more compression?
		// gfx_SetColor(COLOR_BLACK);
		// gfx_Rectangle(x + FACE_CARD_RECT_HOFFSET, y + FACE_CARD_RECT_VOFFSET,
		//		FACE_CARD_RECT_WIDTH, FACE_CARD_RECT_HEIGHT);

		gfx_RLETSprite(faceSprites[card.suit * 3 + card.value - VALUE_JACK],
				x + FACE_CARD_ART_HOFFSET, y + FACE_CARD_ART_VOFFSET);
	}
	else
	{
		// draw the digits in the corners
		gfx_TempSprite(digitUpright, 5, 4);
		gfx_TempSprite(digitInverse, 5, 4);
		for (unsigned char i = 0; i < 20; i++)
		{
			if (digitSprites[card.value]->data[i] == COLOR_WHITE)
			{
				digitUpright->data[i] = COLOR_WHITE;
			}
			else digitUpright->data[i] = suitColors[card.suit];
		}
		gfx_RotateSpriteHalf(digitUpright, digitInverse);
		gfx_Sprite(digitUpright, x + TOP_CORNER_DIGIT_HOFFSET,
				y + TOP_CORNER_DIGIT_VOFFSET);
		gfx_Sprite(digitInverse, x + BOTTOM_CORNER_DIGIT_HOFFSET,
				y + BOTTOM_CORNER_DIGIT_VOFFSET);
		
		// draw the suit symbols in the corners
		gfx_TempSprite(symbolInverse, 3, 4);
		gfx_RotateSpriteHalf(smallSymbols[card.suit], symbolInverse);
		gfx_Sprite(smallSymbols[card.suit], x + TOP_CORNER_SYMBOL_HOFFSET,
				y + TOP_CORNER_SYMBOL_VOFFSET);
		gfx_Sprite(symbolInverse, x + BOTTOM_CORNER_SYMBOL_HOFFSET,
				y + BOTTOM_CORNER_SYMBOL_VOFFSET);

		if (card.value == VALUE_ACE)
		{
			gfx_Sprite(aceSprites[card.suit], x + ACE_SYMBOL_HOFFSET,
					y + ACE_SYMBOL_VOFFSET);
		}
		else
		{
			// draw the pattern of medium symbols
		}
	}
}

void drawPattern(const unsigned int x, const unsigned char y, const struct card_t card)
{

}
