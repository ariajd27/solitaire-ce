#include "gfx.h"
#include <fileioc.h>

#define PATCEGFX_HEADER_SIZE 0

unsigned char *PATCEGFX_appvar[25] =
{
    (unsigned char*)0,
    (unsigned char*)123,
    (unsigned char*)150,
    (unsigned char*)164,
    (unsigned char*)287,
    (unsigned char*)314,
    (unsigned char*)328,
    (unsigned char*)451,
    (unsigned char*)478,
    (unsigned char*)492,
    (unsigned char*)615,
    (unsigned char*)642,
    (unsigned char*)656,
    (unsigned char*)1751,
    (unsigned char*)2822,
    (unsigned char*)3889,
    (unsigned char*)4937,
    (unsigned char*)5992,
    (unsigned char*)7047,
    (unsigned char*)8142,
    (unsigned char*)9182,
    (unsigned char*)10303,
    (unsigned char*)11406,
    (unsigned char*)12518,
    (unsigned char*)13619,
};

unsigned char PATCEGFX_init(void)
{
    unsigned int data, i;
    uint8_t appvar;

    appvar = ti_Open("PATCEGFX", "r");
    if (appvar == 0)
    {
        return 0;
    }

    data = (unsigned int)ti_GetDataPtr(appvar) - (unsigned int)PATCEGFX_appvar[0] + PATCEGFX_HEADER_SIZE;
    for (i = 0; i < 25; i++)
    {
        PATCEGFX_appvar[i] += data;
    }

    ti_Close(appvar);

    return 1;
}

