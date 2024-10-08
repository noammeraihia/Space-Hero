#include <stdio.h>
#include <stdlib.h>

#include "gfx/p_window.h"
#include "p_scene.h"

int main(int argc, char** argv)
{
    _pWindow window = pWindow("Project Padinspi", 160, 120, 640, 480, 0, 60);
    _pScene scene = pScene(P_VEC(_pVec2f, 50.f, 50.f));

    while (window.isRunning)
    {
        while (pWindowPollEvent(&window))
        {
            switch (window.event.type)
            {
            case SDL_EVENT_KEY_DOWN:
                if (window.event.key.scancode == SDL_SCANCODE_ESCAPE)
                {
                    window.isRunning = pfalse;
                }
                break;

            case SDL_EVENT_QUIT:
                window.isRunning = pfalse;
                break;

            default:
                break;
            }
        }

        const u8* keyState = pWindowBeginFrame(&window);

        pUpdateScene(&scene, &window, keyState);

        pWindowEndFrame(&window);
    }

    pFreeWindow(&window);

    return 0;
}