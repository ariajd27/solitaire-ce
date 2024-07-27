#include "gfx.h"
#include <fileioc.h>

#define PATCEGFX_HEADER_SIZE 0

unsigned char *PATCEGFX_appvar[36] =
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
    (unsigned char*)1060,
    (unsigned char*)1082,
    (unsigned char*)1104,
    (unsigned char*)1126,
    (unsigned char*)1148,
    (unsigned char*)1170,
    (unsigned char*)1192,
    (unsigned char*)1214,
    (unsigned char*)1236,
    (unsigned char*)1258,
    (unsigned char*)2175,
    (unsigned char*)3129,
    (unsigned char*)4065,
    (unsigned char*)4973,
    (unsigned char*)5921,
    (unsigned char*)6891,
    (unsigned char*)7880,
    (unsigned char*)8821,
    (unsigned char*)9781,
    (unsigned char*)10718,
    (unsigned char*)11684,
    (unsigned char*)12639,
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
    for (i = 0; i < 36; i++)
    {
        PATCEGFX_appvar[i] += data;
    }

    ti_Close(appvar);

    return 1;
}

