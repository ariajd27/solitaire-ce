#include <stdlib.h>

#include "stack.h"
#include "card.h"
#include "games/games.h"

#include <debug.h>

#define DECK_X 27
#define DECK_Y 25
#define STACK_SPACING 38
#define FOUNDATIONS_X 87
#define FOUNDATIONS_Y DECK_Y
#define TABLEAU_X FOUNDATIONS_X
#define TABLEAU_Y 65
#define TABLEAU_SPLAY 11

unsigned char calculation_setup()
{
	dbg_printf("setting up CALCULATION... ");

	if (callocStacks(9)) return 1; // insufficient memory

	// set up draw pile
	stacks[0].type = STACK_DRAW;
	stacks[0].x = DECK_X;
	stacks[0].y = DECK_Y;
	if (callocCards(&stacks[0], 48)) return 1;

	// set up foundations
	for (unsigned char stackIndex = 1; stackIndex < 5; stackIndex++)
	{
		stacks[stackIndex].type = STACK_FOUNDATION;
		stacks[stackIndex].x = FOUNDATIONS_X + stackIndex * STACK_SPACING - STACK_SPACING;
		stacks[stackIndex].y = FOUNDATIONS_Y;
		
		if (callocCards(&stacks[stackIndex], 48)) return 1;
	}

	// set up tableau
	for (unsigned char stackIndex = 5; stackIndex < 9; stackIndex++)
	{
		stacks[stackIndex].type = STACK_TABLEAU;
		stacks[stackIndex].x = TABLEAU_X + stackIndex * STACK_SPACING - STACK_SPACING;
		stacks[stackIndex].y = TABLEAU_Y;
		stacks[stackIndex].splay_y = TABLEAU_SPLAY;

		if (callocCards(&stacks[stackIndex], 13)) return 1;
	}
	// start foundations
	for (unsigned char stackIndex = 1; stackIndex < 5; stackIndex++)
	{
		struct card_t *firstCard = &stacks[stackIndex].cards[0];

		firstCard->exists = 1;
		firstCard->faceUp = 1;
		firstCard->value = stackIndex;
		firstCard->suit = rand() % 4;
	}

	// shuffle deck
	for (unsigned char nextValue = VALUE_ACE; nextValue <= VALUE_KING; nextValue++)
	{
		for (unsigned char nextSuit = 0; nextSuit < 4; nextSuit++)
		{
			// make sure we don't duplicate foundation cards
			if (nextValue < 5)
			{
				if (stacks[nextValue].cards[0].suit == nextSuit) continue;
			}

			// find an empty slot to put the card
			struct card_t *card;
			do card = stacks[0].cards + (rand() % 48) * sizeof(struct card_t);
			while (card->exists);
			
			// put the card in place!
			card->exists = 1;
			card->faceUp = 0;
			card->value = nextValue;
			card->suit = nextSuit;
		}
	}

	dbg_printf("done!\n");

	return 0;
};
