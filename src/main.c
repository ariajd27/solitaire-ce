#include <graphx.h>
#include <keypadc.h>
#include <sys/rtc.h>

#include "graphics.h"
#include "gfx/gfx.h"
#include "stack.h"
#include "card.h"
#include "games/games.h"

#include <debug.h>

int main(void)
{
	srand(rtc_Time());

	PATCEGFX_init();
	initCardSprites();

	gfx_Begin();
	gfx_SetPalette(global_palette, sizeof_global_palette, 0);
	gfx_SetDrawBuffer();

	(*setup[GAME_CALCULATION])();

	drawGame();

	dbg_printf("waiting for keypress... ");

	while (!kb_AnyKey());

	dbg_printf("done!\n");

	freeStacks();

	gfx_End();

	return 0;
}
