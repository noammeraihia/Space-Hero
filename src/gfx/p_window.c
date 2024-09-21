#include "gfx/p_window.h"

_pWindow pWindow(const char *__name, u16 __logicalWidth, u16 __logicalHeight, u16 __width, u16 __height, SDL_WindowFlags __wF, u16 __framerate)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "%s\n", SDL_GetError());
        return (_pWindow){0};
    }

    _pWindow window = {
        .rWidth = __logicalWidth,
        .rHeight = __logicalHeight,
        .hWidth = __width,
        .hHeight = __height,

        .handle = NULL,
        .renderer = NULL,
        .frameRate = __framerate,
        .frameDelay = 1000 / __framerate,
        .isRunning = ptrue};

    window.handle = SDL_CreateWindow(__name, __width, __height, __wF);
    if (!window.handle)
    {
        fprintf(stderr, "%s", SDL_GetError());
        return (_pWindow){0};
    }

    window.renderer = SDL_CreateRenderer(window.handle, NULL);
    if (!window.renderer)
    {
        fprintf(stderr, "%s\n", SDL_GetError());
        return (_pWindow){0};
    }

    SDL_SetRenderLogicalPresentation(window.renderer, __logicalWidth, __logicalHeight, SDL_LOGICAL_PRESENTATION_STRETCH, SDL_SCALEMODE_NEAREST);

    return window; 
}

void pFreeWindow(_pWindow *__window)
{
    SDL_DestroyRenderer(__window->renderer);
    SDL_DestroyWindow(__window->handle);
}


b8 pWindowPollEvent(_pWindow *__window)
{
    return SDL_PollEvent(&__window->event);
}

const u8* pWindowBeginFrame(_pWindow *__window)
{
    __window->frameStart = SDL_GetTicks();
    SDL_SetRenderDrawColor(__window->renderer, 0, 0, 25, 255);
    SDL_RenderClear(__window->renderer);
    
    return SDL_GetKeyboardState(NULL);
}

void pWindowEndFrame(_pWindow *__window)
{
    SDL_RenderPresent(__window->renderer);
    __window->frameTime = SDL_GetTicks() - __window->frameStart;

    if (__window->frameDelay > __window->frameTime)
    {
        SDL_Delay(__window->frameDelay - __window->frameTime);
    }
}


void pRenderPixel(_pWindow *__window, _pVec2f __pos, _pRGBAColor __color)
{
    SDL_SetRenderDrawColor(__window->renderer, __color.r, __color.g, __color.b, __color.a);
    SDL_RenderPoint(__window->renderer, __pos.x, __pos.y);
}

void pRenderLine(_pWindow *__window, _pVec2f __startPos, _pVec2f __endPos, _pRGBAColor __color)
{
    SDL_SetRenderDrawColor(__window->renderer, __color.r, __color.g, __color.b, __color.a);
    SDL_RenderLine(__window->renderer, __startPos.x, __startPos.y, __endPos.x, __endPos.y);
}