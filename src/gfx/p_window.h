#ifndef P_WINDOW_h
#define P_WINDOW_h

#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL.h>

#include "utils/p_utils.h"

typedef struct s_pWindow
{
    SDL_Window *handle;
    SDL_Renderer *renderer;
    u16 hWidth, hHeight;
    u16 rWidth, rHeight;

    SDL_Event event;

    int frameRate;
    int frameDelay;
    int frameStart;
    int frameTime;

    b8 isRunning;

} _pWindow;

_pWindow pWindow(const char *__name, u16 __logicalWidth, u16 __logicalHeight, u16 __width, u16 __height, SDL_WindowFlags __wF, SDL_RendererFlags __rF, u16 __framerate);
void pFreeWindow(_pWindow *__window);

b8 pWindowPollEvent(_pWindow *__window);
const u8* pWindowBeginFrame(_pWindow *__window);
void pWindowEndFrame(_pWindow *__window);

void pRenderPixel(_pWindow *__window, _pVec2i __pos, _pRGBAColor __color);

#endif