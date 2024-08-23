#ifndef P_SCENE_h
#define P_SCENE_h

#include "utils/p_utils.h"
#include "gfx/p_window.h"

#define SEC1_CLR1 \
    0, 0, 255, 255
#define SEC1_CLR2 \
    0, 255, 255, 255
#define SEC2_CLR1 \
    255, 0, 0, 255
#define SEC2_CLR2 \
    255, 100, 0, 255
#define SEC3_CLR1 \
    125, 0, 255, 255
#define SEC3_CLR2 \
    255, 0, 125, 255
#define SEC4_CLR1 \
    0, 0, 0, 255
#define SEC4_CLR2 \
    255, 255, 255, 255

typedef enum {
    P_SS_NONE = 0, 
    P_SS_BOTTOM = 1,
    P_SS_TOP = 2,
    P_SS_RENDER_BOTTOM = (-1),
    P_SS_RENDER_TOP = (-2),

} _pSectorSurface;

typedef struct s_pCamera 
{
    _pVec3f position;
    f32 rotation;
    i32 look;

} _pCamera;

typedef struct s_pSectorWall
{
    _pVec2f startingPoint;
    _pVec2f endingPoint;
    _pRGBAColor color;

} _pSectorWall;

typedef struct s_pSector
{
    u8 index;
    u8 wallsCount;
    _pVec2f position;
    f32 distance;
    f32 bottomHeight, topHeight;
    _pRGBAColor bottomColor, topColor;
    i32 surf[160];
    _pSectorSurface surfaceType;

} _pSector;

typedef struct s_pScene
{
    _pSectorWall walls[30];
    _pSector sectors[30];
    _pCamera camera;
    b8 debugMode;

    i32 wallsCount;
    i32 sectorsCount;

} _pScene;

_pScene pScene(_pVec3f __cameraPos);
void pUpdateScene(_pScene* __scene, _pWindow* __window, const u8* ____keyState);

#endif