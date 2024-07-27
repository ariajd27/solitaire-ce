#include "gfx.h"
#include <fileioc.h>

#define PATCEGFX_HEADER_SIZE 0

unsigned char *PATCEGFX_appvar[26] =
{
    (unsigned char*)0,
    (unsigned char*)22,
    (unsigned char*)200,
    (unsigned char*)242,
    (unsigned char*)276,
    (unsigned char*)454,
    (unsigned char*)496,
    (unsigned char*)530,
    (unsigned char*)708,
    (unsigned char*)750,
    (unsigned char*)784,
    (unsigned char*)962,
    (unsigned char*)1004,
    (unsigned char*)1038,
    (unsigned char*)1955,
    (unsigned char*)2909,
    (unsigned char*)3845,
    (unsigned char*)4753,
    (unsigned char*)5701,
    (unsigned char*)6671,
    (unsigned char*)7660,
    (unsigned char*)8601,
    (unsigned char*)9561,
    (unsigned char*)10498,
    (unsigned char*)11464,
    (unsigned char*)12419,
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
    for (i = 0; i < 26; i++)
    {
        PATCEGFX_appvar[i] += data;
    }

    ti_Close(appvar);

    return 1;
}

