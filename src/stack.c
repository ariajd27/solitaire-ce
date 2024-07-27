#include "card.h"
#include "stack.h"
#include <stdlib.h>

unsigned char numStacks;
struct stack_t* stacks;

unsigned char callocStacks(const unsigned char num)
{
	numStacks = num;
	stacks = (struct stack_t*)calloc(numStacks, sizeof(struct stack_t));
	return stacks == NULL;
}

unsigned char callocCards(struct stack_t *stack, const unsigned char numCards)
{
	stack->cards = (struct card_t*)calloc(numCards, sizeof(struct card_t));
	stack->maxCards = numCards;
	return stack->cards == NULL;
}

void freeStacks()
{
	for (struct stack_t *stack = stacks; stack <= &stacks[numStacks]; stack += sizeof(struct stack_t))
	{
		free(stack->cards);
	}

	free(stacks);
}

void drawStack(unsigned char stackIndex)
{
	const struct stack_t *stack = &stacks[stackIndex];

	if (stack->splay_x == 0 && stack->splay_y == 0)
	{
		// we only need to draw the top card
		for (unsigned char cardIndex = stack->maxCards; 1; cardIndex--)
		{
			const struct card_t card = stack->cards[cardIndex];
			if (card.exists)
			{
				drawCard(stack->x, stack->y, card);
				break;
			}

			if (cardIndex == 0) break; // cardIndex is unsigned...
		}
	}

	for (unsigned char cardIndex = 0; cardIndex < stack->maxCards; cardIndex++)
	{
		const struct card_t card = stack->cards[cardIndex];
		if (!card.exists) break; // no more cards

		const unsigned int x = stack->x + stack->splay_x * cardIndex;
		const unsigned char y = stack->y + stack->splay_y * cardIndex;

		drawCard(x, y, card);
	}
}
