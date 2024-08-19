#include "utils/p_math.h"

#define P_MATH_DECLARE_V2_FUNCS(__tsuf, __type)\
    _pVec2##__tsuf pAddS_v2##__tsuf(_pVec2##__tsuf __vector, __type __scalar) { return (_pVec2##__tsuf){ __vector.x + __scalar, __vector.y + __scalar }; }\
    _pVec2##__tsuf pSubS_v2##__tsuf(_pVec2##__tsuf __vector, __type __scalar) { return (_pVec2##__tsuf){ __vector.x - __scalar, __vector.y - __scalar }; }\
    _pVec2##__tsuf pMulS_v2##__tsuf(_pVec2##__tsuf __vector, __type __scalar) { return (_pVec2##__tsuf){ __vector.x * __scalar, __vector.y * __scalar }; }\
    _pVec2##__tsuf pDivS_v2##__tsuf(_pVec2##__tsuf __vector, __type __scalar) { return (_pVec2##__tsuf){ __vector.x / __scalar, __vector.y / __scalar }; }\
    \
    _pVec2##__tsuf pAddV_v2##__tsuf(_pVec2##__tsuf __vector1, _pVec2##__tsuf __vector2) { return (_pVec2##__tsuf){ __vector1.x + __vector2.x, __vector1.y + __vector2.y }; }\
    _pVec2##__tsuf pSubV_v2##__tsuf(_pVec2##__tsuf __vector1, _pVec2##__tsuf __vector2) { return (_pVec2##__tsuf){ __vector1.x - __vector2.x, __vector1.y - __vector2.y }; }\
    _pVec2##__tsuf pMulV_v2##__tsuf(_pVec2##__tsuf __vector1, _pVec2##__tsuf __vector2) { return (_pVec2##__tsuf){ __vector1.x * __vector2.x, __vector1.y * __vector2.y }; }\
    _pVec2##__tsuf pDivV_v2##__tsuf(_pVec2##__tsuf __vector1, _pVec2##__tsuf __vector2) { return (_pVec2##__tsuf){ __vector1.x / ((__vector2.x != 0) ? __vector2.x : (__type) 1), __vector1.y / ((__vector2.y != 0) ? __vector2.y : (__type) 1) }; }\
    \
    __type pDot_v2##__tsuf(_pVec2##__tsuf __vector1, _pVec2##__tsuf __vector2) { return ((__vector1.x * __vector2.x) + (__vector1.y * __vector2.y)) ; }\

#define P_MATH_DECLARE_V3_FUNCS(__tsuf, __type)\
    _pVec3##__tsuf pAddS_v3##__tsuf(_pVec3##__tsuf __vector, __type __scalar) { return (_pVec3##__tsuf){ __vector.x + __scalar, __vector.y + __scalar, __vector.z + __scalar }; }\
    _pVec3##__tsuf pSubS_v3##__tsuf(_pVec3##__tsuf __vector, __type __scalar) { return (_pVec3##__tsuf){ __vector.x - __scalar, __vector.y - __scalar, __vector.z - __scalar }; }\
    _pVec3##__tsuf pMulS_v3##__tsuf(_pVec3##__tsuf __vector, __type __scalar) { return (_pVec3##__tsuf){ __vector.x * __scalar, __vector.y * __scalar, __vector.z * __scalar }; }\
    _pVec3##__tsuf pDivS_v3##__tsuf(_pVec3##__tsuf __vector, __type __scalar) { return (_pVec3##__tsuf){ __vector.x / __scalar, __vector.y / __scalar, __vector.z / __scalar }; }\
    \
    _pVec3##__tsuf pAddV_v3##__tsuf(_pVec3##__tsuf __vector1, _pVec3##__tsuf __vector2) { return (_pVec3##__tsuf){ __vector1.x + __vector2.x, __vector1.y + __vector2.y, __vector1.z + __vector2.z }; }\
    _pVec3##__tsuf pSubV_v3##__tsuf(_pVec3##__tsuf __vector1, _pVec3##__tsuf __vector2) { return (_pVec3##__tsuf){ __vector1.x - __vector2.x, __vector1.y - __vector2.y, __vector1.z - __vector2.z }; }\
    _pVec3##__tsuf pMulV_v3##__tsuf(_pVec3##__tsuf __vector1, _pVec3##__tsuf __vector2) { return (_pVec3##__tsuf){ __vector1.x * __vector2.x, __vector1.y * __vector2.y, __vector1.z * __vector2.z }; }\
    _pVec3##__tsuf pDivV_v3##__tsuf(_pVec3##__tsuf __vector1, _pVec3##__tsuf __vector2) { return (_pVec3##__tsuf){ __vector1.x / ((__vector2.x != 0) ? __vector2.x : (__type) 1), __vector1.y / ((__vector2.y != 0) ? __vector2.y : (__type) 1), __vector1.z / ((__vector2.z != 0) ? __vector2.z : (__type) 1) }; }\
    \
    __type pDot_v3##__tsuf(_pVec3##__tsuf __vector1, _pVec3##__tsuf __vector2) { return ((__vector1.x * __vector2.x) + (__vector1.y * __vector2.y) + (__vector1.z * __vector2.z)) ; }\

P_MATH_DECLARE_V2_FUNCS(i, i32)
P_MATH_DECLARE_V2_FUNCS(f, f32)
P_MATH_DECLARE_V3_FUNCS(i, i32)
P_MATH_DECLARE_V3_FUNCS(f, f32)