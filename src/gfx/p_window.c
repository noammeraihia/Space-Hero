#include "gfx/p_window.h"

_pWindow pWindow(const char *__name, u16 __logicalWidth, u16 __logicalHeight, u16 __width, u16 __height, SDL_WindowFlags __wF, SDL_RendererFlags __rF, u16 __framerate)
{
    printf("bloh");
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "%s", SDL_GetError());
        return (_pWindow){0};
    }
    printf("bleh");

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

    window.handle = SDL_CreateWindow(__name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, __width, __height, __wF);
    if (!window.handle)
    {
        fprintf(stderr, "%s", SDL_GetError());
        return (_pWindow){0};
    }

    window.renderer = SDL_CreateRenderer(window.handle, -1, __rF);
    if (!window.renderer)
    {
        fprintf(stderr, "%s", SDL_GetError());
        return (_pWindow){0};
    }

    SDL_RenderSetLogicalSize(window.renderer, __logicalWidth, __logicalHeight);

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


void pRenderPixel(_pWindow *__window, _pVec2i __pos, _pRGBAColor __color)
{
    SDL_SetRenderDrawColor(__window->renderer, __color.r, __color.g, __color.b, __color.a);
    SDL_RenderDrawPointF(__window->renderer, __pos.x, __pos.y);
}