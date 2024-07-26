#include <graphx.h>

#include "gfx/gfx.h"
#include "graphics.h"
#include "card.h"

#define CARD_WIDTH 33
#define CARD_HEIGHT 45
#define CARD_BEZEL 2
#define CARD_BACK_HOFFSET 2
#define CARD_BACK_VOFFSET 2
#define FACE_CARD_ART_HOFFSET 3
#define FACE_CARD_ART_VOFFSET 3

gfx_rletsprite_t *face_sprites[12]; 

void initCardSprites()
{
	face_sprites[0] = jack_hearts;
	face_sprites[1] = queen_hearts;
	face_sprites[2] = king_hearts;
	face_sprites[3] = jack_clubs;
	face_sprites[4] = queen_clubs;
	face_sprites[5] = king_clubs;
	face_sprites[6] = jack_diamonds;
	face_sprites[7] = queen_diamonds;
	face_sprites[8] = king_diamonds;
	face_sprites[9] = jack_spades;
	face_sprites[10] = queen_spades;
	face_sprites[11] = king_spades;
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
		gfx_RLETSprite(face_sprites[card.suit * 3 + card.value - VALUE_JACK],
				x + FACE_CARD_ART_HOFFSET, y + FACE_CARD_ART_VOFFSET);
	}
	else
	{
		// draw the value in the corners

		if (card.value == VALUE_ACE)
		{
			// draw the large symbol
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
