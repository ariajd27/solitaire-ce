#include <graphx.h>

#include "graphics.h"
#include "stack.h"

#include <debug.h>

#define TOP_BAR_HEIGHT 15

const unsigned char suitColors[] = {
	COLOR_RED, COLOR_BLUE, COLOR_ORANGE, COLOR_BLACK
};

void drawBackground()
{
	gfx_FillScreen(COLOR_GREEN);

	gfx_SetColor(COLOR_WHITE);
	gfx_FillRectangle(0, 0, GFX_LCD_WIDTH, TOP_BAR_HEIGHT);
}

void drawGame()
{
	drawBackground();

	for (unsigned char stackIndex = 0; stackIndex < numStacks; stackIndex++)
	{
		drawStack(stackIndex);
	}

	gfx_BlitBuffer();
}
