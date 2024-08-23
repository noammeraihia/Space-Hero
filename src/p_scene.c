#include "p_scene.h"

/*
void pRenderSectorWall(_pWindow *__window, _pSector *__sectors, _pVec3f __wallsPoints[4], _pRGBAColor __color, _pSectorSurface __surface)
{

    i32 x, y;
    i32 dyb = __wallsPoints[1].y - __wallsPoints[0].y;
    i32 dyt = __wallsPoints[3].y - __wallsPoints[2].y;
    i32 dx = (__wallsPoints[1].x - __wallsPoints[0].x != 0.f ? __wallsPoints[1].x - __wallsPoints[0].x : 1.f);
    
    i32 xs = __wallsPoints[0].x;

    __wallsPoints[0].x = (__wallsPoints[0].x < 1.f ? 1.f : __wallsPoints[0].x);
    __wallsPoints[1].x = (__wallsPoints[1].x < 1.f ? 1.f : __wallsPoints[1].x);
    __wallsPoints[0].x = (__wallsPoints[0].x > __window->rWidth - 1 ? __window->rWidth - 1 : __wallsPoints[0].x);
    __wallsPoints[1].x = (__wallsPoints[1].x > __window->rWidth - 1 ? __window->rWidth - 1 : __wallsPoints[1].x);

    for (x = __wallsPoints[0].x; x < __wallsPoints[1].x; x++)
    {
        f32 y1 = dyb * (x - xs + 0.5f) / dx + __wallsPoints[0].y;
        f32 y2 = dyt * (x - xs + 0.5f) / dx + __wallsPoints[2].y;

        y1 = (y1 < 1.f ? 1.f : y1);
        y2 = (y2 < 1.f ? 1.f : y2);
        y1 = (y1 < __window->rHeight - 1 ? __window->rHeight - 1 : y1);
        y2 = (y2 < __window->rHeight - 1 ? __window->rHeight - 1 : y2);

        switch (__surface)
        {
        case P_SS_BOTTOM:
            __sectors->surf[x] = y1;
            break;

        case P_SS_TOP:
            __sectors->surf[x] = y2;
            break;

        case P_SS_RENDER_BOTTOM:
            for (y = __sectors->surf[x]; y < y1; y++)
                pRenderPixel(__window, P_VEC(_pVec2i, x, y), __sectors->bottomColor);
            break;

        case P_SS_RENDER_TOP:
            for (y = y2; y < __sectors->surf[x]; y++)
                pRenderPixel(__window, P_VEC(_pVec2i, x, y), __sectors->topColor);
            break;

        default:
            break;
        }

        for (y = y1; y < y2; y++)
        {
            pRenderPixel(__window, P_VEC(_pVec2i, x, y), __color);
        }
    }
}
*/


void pRenderSectorWall(_pWindow *__window, _pSector *__sectors, f32 __w1x, f32 __w1y, f32 __w2x, f32 __w2y, f32 __w3y, f32 __w4y, _pRGBAColor __color, _pSectorSurface __surface)
{
    i32 x, y;
    f32 dyb = __w2y - __w1y;
    f32 dyt = __w4y - __w3y;
    f32 dx = __w2x - __w1x;
    if (dx == 0.f) { dx = 1.f; }
    
    f32 xs = __w1x;

    if (__w1x < 1.f) { __w1x = 1.f; }
    if (__w2x < 1.f) { __w2x = 1.f; }
    if (__w1x > __window->rWidth - 1) { __w1x = __window->rWidth - 1; }
    if (__w2x > __window->rWidth - 1) { __w2x = __window->rWidth - 1; }

    for (x = __w1x; x < __w2x; x++)
    {
        f32 y1 = dyb * (x - xs + 0.5f) / dx + __w1y;
        f32 y2 = dyt * (x - xs + 0.5f) / dx + __w3y;

        if (y1 < 1.f) { y1 = 1.f; }
        if (y2 < 1.f) { y2 = 1.f; }
        if (y1 > __window->rHeight - 1) { y1 = __window->rHeight - 1; }
        if (y2 > __window->rHeight - 1) { y2 = __window->rHeight - 1; }
        /*
        switch (__surface)
        {
        case P_SS_BOTTOM:
            __sectors->surf[x] = y1;
            break;

        case P_SS_TOP:
            __sectors->surf[x] = y2;
            break;

        case P_SS_RENDER_BOTTOM:
            for (y = __sectors->surf[x]; y < y1; y++)
                pRenderPixel(__window, P_VEC(_pVec2i, x, y), __sectors->bottomColor);
            break;

        case P_SS_RENDER_TOP:
            for (y = y2; y < __sectors->surf[x]; y++)
                pRenderPixel(__window, P_VEC(_pVec2i, x, y), __sectors->topColor);
            break;

        default:
            break;
        }
        */

        if (__surface == P_SS_BOTTOM){__sectors->surf[x] = y1;}
        if (__surface == P_SS_TOP){__sectors->surf[x] = y2;}
        if (__surface == P_SS_RENDER_BOTTOM){
            for (y = __sectors->surf[x]; y < y1; y++)
            {
                pRenderPixel(__window, P_VEC(_pVec2i, x, y), __sectors->bottomColor);
            }
        }
        if (__surface == P_SS_RENDER_TOP){
            for (y = y2; y < __sectors->surf[x]; y++)
            {
                pRenderPixel(__window, P_VEC(_pVec2i, x, y), __sectors->topColor);
            }
        }

        for (y = y1; y < y2; y++)
        {
            pRenderPixel(__window, P_VEC(_pVec2i, x, y), __color);
        }
    }
}

void pClipBehindSceneCamera(_pVec3f* __vector1, _pVec3f* __vector2)
{
    f32 d = __vector1->y - __vector2->y;
    if (d == 0.f)
    {
        d = 1.f;
    }
    f32 s = __vector1->y / (d);

    __vector1->x += s * (__vector2->x - __vector1->x);
    __vector1->y += s * (__vector2->y - __vector1->y); 
    __vector1->y = (__vector1->y == 0 ? 1.f : __vector1->y);

    __vector1->z += s * (__vector2->z - __vector2->z);
}

void pRenderCamera(_pWindow *__window, _pCamera *__camera, _pSectorWall __walls[], _pSector __sectors[], i32 __wallsCount, i32 __sectorsCount)
{
    _pVec3f wallsPoints[4];

    // Bubble sorting => TODO : upgrade this shi
    for (i32 s = 0; s < __sectorsCount - 1; s++)
    {
        for (i32 w = 0; w < __sectorsCount - s - 1; w++)
        {
            if (__sectors[w].distance < __sectors[w + 1].distance)
            {
                _pSector tmpSector = __sectors[w];
                __sectors[w] = __sectors[w + 1];
                __sectors[w + 1] = tmpSector;
            }
        }
    }

    for (i32 s = 0; s < __sectorsCount; s++)
    {
        __sectors[s].distance = 0;
        if (__camera->position.z > __sectors[s].bottomHeight)
            {__sectors[s].surfaceType = P_SS_BOTTOM; }
        else if (__camera->position.z < __sectors[s].topHeight)
            {__sectors[s].surfaceType = P_SS_TOP; }
        else
            {__sectors[s].surfaceType = P_SS_NONE;}

        for (i32 i = 0; i < 2; i++)
        {
            for (i32 w = __sectors[s].index; w < __sectors[s].index + __sectors[s].wallsCount; w++)
            {
                _pVec2f p1 = pSubV_v2f(__walls[w].startingPoint, P_VEC(_pVec2f, __camera->position.x, __camera->position.y));
                _pVec2f p2 = pSubV_v2f(__walls[w].endingPoint, P_VEC(_pVec2f, __camera->position.x, __camera->position.y));

                if (i == 0)
                {
                    i32 swp = p1.x;
                    p1.x = p2.x;
                    p2.x = swp;
                    swp = p1.y;
                    p1.y = p2.y;
                    p2.y = swp;
                }

                wallsPoints[0].x = p1.x * cos(__camera->rotation) - p1.y * sin(__camera->rotation);
                wallsPoints[1].x = p2.x * cos(__camera->rotation) - p2.y * sin(__camera->rotation);
                wallsPoints[2].x = wallsPoints[0].x;
                wallsPoints[3].x = wallsPoints[1].x;

                wallsPoints[0].y = p1.y * cos(__camera->rotation) + p1.x * sin(__camera->rotation);
                wallsPoints[1].y = p2.y * cos(__camera->rotation) + p2.x * sin(__camera->rotation);
                wallsPoints[2].y = wallsPoints[0].y;
                wallsPoints[3].y = wallsPoints[1].y;

                _pVec2f tmp = P_VEC(_pVec2f, (wallsPoints[0].x + wallsPoints[1].x) / 2, (wallsPoints[0].y + wallsPoints[1].y) / 2);
                __sectors[s].distance = pDist_v2f(P_VEC(_pVec2f, 0.f, 0.f), tmp);

                wallsPoints[0].z = __sectors[s].bottomHeight - __camera->position.z + ((__camera->look * wallsPoints[0].y) / 32.f);
                wallsPoints[1].z = __sectors[s].bottomHeight - __camera->position.z + ((__camera->look * wallsPoints[1].y) / 32.f);
                wallsPoints[2].z = wallsPoints[0].z + __sectors[s].topHeight;
                wallsPoints[3].z = wallsPoints[1].z + __sectors[s].topHeight;

                if (wallsPoints[0].y < 1 && wallsPoints[1].y < 1)
                {
                    continue;
                }

                if (wallsPoints[0].y < 1)
                {
                    pClipBehindSceneCamera(&wallsPoints[0], &wallsPoints[1]);
                    pClipBehindSceneCamera(&wallsPoints[2], &wallsPoints[3]);
                }

                if (wallsPoints[1].y < 1)
                {
                    pClipBehindSceneCamera(&wallsPoints[1], &wallsPoints[0]);
                    pClipBehindSceneCamera(&wallsPoints[3], &wallsPoints[2]);
                }

                /*for (u8 i = 0; i < 4; i++)
                {
                    wallsPoints[i].x = wallsPoints[i].x * 200 / wallsPoints[i].y + ((f32)__window->rWidth / 2);
                    wallsPoints[i].y = wallsPoints[i].z * 200 / wallsPoints[i].y + ((f32)__window->rHeight / 2);
                }
                */
               wallsPoints[0].x = wallsPoints[0].x * 200 / wallsPoints[0].y + ((f32)__window->rWidth / 2);
               wallsPoints[1].x = wallsPoints[1].x * 200 / wallsPoints[1].y + ((f32)__window->rWidth / 2);

               wallsPoints[0].y = wallsPoints[0].z * 200 / wallsPoints[0].y + ((f32)__window->rHeight / 2);
               wallsPoints[1].y = wallsPoints[1].z * 200 / wallsPoints[1].y + ((f32)__window->rHeight / 2);
               
               wallsPoints[2].x = wallsPoints[2].x * 200 / wallsPoints[2].y + ((f32)__window->rWidth / 2);
               wallsPoints[3].x = wallsPoints[3].x * 200 / wallsPoints[3].y + ((f32)__window->rWidth / 2);
               
               wallsPoints[2].y = wallsPoints[2].z * 200 / wallsPoints[2].y + ((f32)__window->rHeight / 2);
               wallsPoints[3].y = wallsPoints[3].z * 200 / wallsPoints[3].y + ((f32)__window->rHeight / 2);

                pRenderSectorWall(__window, &__sectors[s], wallsPoints[0].x, wallsPoints[0].y, wallsPoints[1].x, wallsPoints[1].y, wallsPoints[2].y, wallsPoints[3].y, __walls[w].color, __sectors[s].surfaceType);
            }
            __sectors[s].distance /= (__sectors[s].wallsCount);
            __sectors[s].surfaceType *= -1;
        }
    }
}

_pScene pScene(_pVec3f __cameraPos)
{
    _pScene scene = {
        .walls = {0},
        .sectors = {0},
        .camera = {
            .position = __cameraPos,
            .rotation = 0.f,
            .look = 0
        },
        .debugMode = ptrue,
        .wallsCount = 16,
        .sectorsCount = 4,
    };

    u8 loadSectors[4][8] = {
        {0, 4, 0, 40, SEC2_CLR1},
        {4, 8, 0, 40, SEC1_CLR1},
        {8, 12, 0, 40, SEC4_CLR1},
        {12, 16, 0, 40, SEC3_CLR1}};

    u8 loadWalls[16][8] = {
        {0,
         0,
         32,
         0,
         SEC1_CLR2},
        {32,
         0,
         32,
         32,
         SEC1_CLR1},
        {32,
         32,
         0,
         32,
         SEC1_CLR2},
        {0,
         32,
         0,
         0,
         SEC1_CLR1},

        {64,
         0,
         96,
         0,
         SEC2_CLR1},
        {96,
         0,
         96,
         32,
         SEC2_CLR2},
        {96,
         32,
         64,
         32,
         SEC2_CLR1},
        {64,
         32,
         64,
         0,
         SEC2_CLR2},

        {64,
         64,
         96,
         64,
         SEC3_CLR1},
        {96,
         64,
         96,
         96,
         SEC3_CLR2},
        {96,
         96,
         64,
         96,
         SEC3_CLR1},
        {64,
         96,
         64,
         64,
         SEC3_CLR2},

        {0,
         64,
         32,
         64,
         SEC4_CLR1},
        {32,
         64,
         32,
         96,
         SEC4_CLR2},
        {32,
         96,
         0,
         96,
         SEC4_CLR1},
        {0,
         96,
         0,
         64,
         SEC4_CLR2}

    };

    for (i32 s = 0; s < 4; s++)
    {
        for (int i = 0; i < scene.sectorsCount; i++)
        {
            scene.sectors[s].index = loadSectors[s][0];
            scene.sectors[s].wallsCount = (loadSectors[s][1]) - loadSectors[s][0];
            scene.sectors[s].bottomHeight = loadSectors[s][2];
            scene.sectors[s].topHeight = loadSectors[s][3] - loadSectors[s][2];
            //scene.sectors[s].topHeight = loadSectors[s][3];
            u8 endColors[4] = {0};
            for (i32 i = 0; i < 4; i++)
            {
                endColors[0] = loadSectors[s][4 + i];
            }
            scene.sectors[s].topColor = scene.sectors[s].bottomColor = P_RGBA(endColors[0], endColors[1], endColors[2], endColors[3]);

            for (i32 i = 0; i < 160; i++)
            {
                scene.sectors[s].surf[i] = 0;
            }
        }
    }

    for (i32 w = 0; w < scene.wallsCount; w++)
    {
        scene.walls[w].startingPoint.x = loadWalls[w][0];
        scene.walls[w].startingPoint.y = loadWalls[w][1];
        scene.walls[w].endingPoint.x = loadWalls[w][2];
        scene.walls[w].endingPoint.y = loadWalls[w][3];

        u8 color[4] = {0};

        for (i32 i = 0; i < 4; i++)
        {
            color[i] = loadWalls[w][4 + i];
        }

        scene.walls[w].color = P_RGBA(color[0], color[1], color[2], color[3]);
    }

    return scene;
}

void pCameraDebugModeInput(_pCamera *__camera, const u8* __keyState)
{
    if (__keyState[SDL_SCANCODE_A])
    {
        __camera->rotation -= P_PI / 180.f;
    }
    else if (__keyState[SDL_SCANCODE_D])
    {
        __camera->rotation += P_PI / 180.f;
    }

    if (__keyState[SDL_SCANCODE_W])
    {
        __camera->position.x += sin(__camera->rotation) * 5.f;
        __camera->position.y += cos(__camera->rotation) * 5.f;
    }
    else if (__keyState[SDL_SCANCODE_S])
    {
        __camera->position.x -= sin(__camera->rotation) * 5.f;
        __camera->position.y -= cos(__camera->rotation) * 5.f;
    }

    if (__keyState[SDL_SCANCODE_K])
    {
        __camera->look -= 1;
    }
    else if (__keyState[SDL_SCANCODE_I])
    {
        __camera->look += 1;
    }

    if (__keyState[SDL_SCANCODE_UP])
    {
        __camera->position.z -= 1.f;
    }
    else if (__keyState[SDL_SCANCODE_DOWN])
    {
        __camera->position.z += 1.f;
    }

    if (__keyState[SDL_SCANCODE_LEFT])
    {
        __camera->position.x -= cos(__camera->rotation) * 5.f;
        __camera->position.y += sin(__camera->rotation) * 5.f;
    }
    else if (__keyState[SDL_SCANCODE_RIGHT])
    {
        __camera->position.x += cos(__camera->rotation) * 5.f;
        __camera->position.y -= sin(__camera->rotation) * 5.f;
    }
}

void pUpdateScene(_pScene* __scene, _pWindow* __window, const u8* ____keyState)
{   
    if (__scene->debugMode)
    {
        pCameraDebugModeInput(&__scene->camera, ____keyState);
    }
    pRenderCamera(__window, &__scene->camera, __scene->walls, __scene->sectors, __scene->wallsCount, __scene->sectorsCount);
}