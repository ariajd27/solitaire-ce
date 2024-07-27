#ifndef stack_include_file
#define stack_include_file

#define STACK_DRAW 0
#define STACK_DISCARD 1
#define STACK_FOUNDATION 2
#define STACK_FREECELL 3
#define STACK_TABLEAU 4

struct stack_t
{
	unsigned char type;
	unsigned int x;
	unsigned char y;
	signed char splay_x;
	signed char splay_y;
	struct card_t *cards;
	unsigned char maxCards;
};

extern unsigned char numStacks;
extern struct stack_t * stacks;
unsigned char callocStacks(const unsigned char num);
unsigned char callocCards(struct stack_t *stack, const unsigned char numCards);
void freeStacks();

void drawStack(unsigned char stackIndex);

#endif
