#ifndef P_SCENE_h
#define P_SCENE_h

#include "utils/p_utils.h"
#include "gfx/p_window.h"

typedef struct s_pPlayer
{
    _pVec2f position;
    _pVec2f look;
    _pVec2f nextPosition;
    f32 rotation;

} _pPlayer;

typedef struct s_pScene
{
    _pPlayer player;

} _pScene;

_pScene pScene(_pVec2f __playerPos);
void pUpdateScene(_pScene* __scene, _pWindow* __window, const u8* ____keyState);

#endif