#ifndef P_MATH_H
#define P_MATH_H

#include "utils/p_types.h"
#include <math.h>

#define P_PI 3.14159265358979f
#define P_RAD P_PI / 180.f

#define P_MATH_INIT_VECTOR_TYPE(__suffix, __type, ...)\
    typedef struct s_pVec##__suffix\
    { \
        __type __VA_ARGS__;\
    } _pVec##__suffix;\
    \
    _pVec##__suffix pAddS_v##__suffix(_pVec##__suffix __vector, __type __scalar);\
    _pVec##__suffix pSubS_v##__suffix(_pVec##__suffix __vector, __type __scalar);\
    _pVec##__suffix pMulS_v##__suffix(_pVec##__suffix __vector, __type __scalar);\
    _pVec##__suffix pDivS_v##__suffix(_pVec##__suffix __vector, __type __scalar);\
    \
    _pVec##__suffix pAddV_v##__suffix(_pVec##__suffix __vector1, _pVec##__suffix __vector2);\
    _pVec##__suffix pSubV_v##__suffix(_pVec##__suffix __vector1, _pVec##__suffix __vector2);\
    _pVec##__suffix pMulV_v##__suffix(_pVec##__suffix __vector1, _pVec##__suffix __vector2);\
    _pVec##__suffix pDivV_v##__suffix(_pVec##__suffix __vector1, _pVec##__suffix __vector2);\
    \
    __type pDot_v##__suffix(_pVec##__suffix __vector1, _pVec##__suffix __vector2);\
    f32 pDist_v##__suffix(_pVec##__suffix __vector1, _pVec##__suffix __vector2);\

#define P_VEC(__type, ...) \
    (__type) { __VA_ARGS__ }

P_MATH_INIT_VECTOR_TYPE(2f, f32, x, y);
P_MATH_INIT_VECTOR_TYPE(3f, f32, x, y, z);
P_MATH_INIT_VECTOR_TYPE(2i, i32, x, y);
P_MATH_INIT_VECTOR_TYPE(3i, i32, x, y, z);

#endif