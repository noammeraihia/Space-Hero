#include "p_scene.h"

void pRenderCamera(_pWindow *__window, _pPlayer *__player)
{
    pRenderLine(__window, __player->position, __player->nextPosition, P_RGBA(0, 255, 255, 255));
    pRenderPixel(__window, __player->position, P_RGBA(255, 0, 255, 255));
}

_pScene pScene(_pVec2f __playerPos)
{
    _pScene scene = {
        .player = {
            .position = __playerPos,
            .look = __playerPos,
            .nextPosition = __playerPos,
            .rotation = 0.f,
        },
    };

    return scene;
}

void pPlayerInput(_pPlayer *__player, const u8* __keyState)
{
    static u8 speed = 2.f;
    if (__keyState[SDL_SCANCODE_A])
    {
        __player->rotation += P_RAD * 6;
    }
    else if (__keyState[SDL_SCANCODE_D])
    {
        __player->rotation -= P_RAD * 6;
    }

    __player->look = P_VEC(_pVec2f, sin(__player->rotation) * speed, cos(__player->rotation) * speed);
    __player->nextPosition = pAddV_v2f(__player->position, __player->look);

    if (__keyState[SDL_SCANCODE_W])
    {
        __player->position = __player->nextPosition;
    }
}

void pUpdateScene(_pScene* __scene, _pWindow* __window, const u8* ____keyState)
{   
    pPlayerInput(&__scene->player, ____keyState);
    pRenderCamera(__window, &__scene->player);
}