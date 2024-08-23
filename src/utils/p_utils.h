#ifndef P_UTILS_h
#define P_UTILS_h

#include "utils/p_math.h"
#include "utils/p_types.h"

#include <math.h>

typedef struct s_pRGBAColor
{
    union
    {
        struct {
            u8 a, b, g, r;
        };
        u32 handle;
    };

} _pRGBAColor;

#define P_RGBA(__r, __g, __b, __a)\
    (_pRGBAColor) { .r = __r, .g = __g, .b = __b, .a = __a }

#endif