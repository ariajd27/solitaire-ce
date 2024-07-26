#ifndef card_include_file
#define card_include_file

#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

#define HEARTS 0
#define CLUBS 1
#define DIAMONDS 2
#define SPADES 3

struct card_t {
	unsigned short faceUp : 1;
	unsigned short suit : 2;
	unsigned short value : 4;
	unsigned short index : 4;
	unsigned short stack : 5;
};

extern struct card_t cards[52];

#endif
