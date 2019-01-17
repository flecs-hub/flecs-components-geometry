#ifndef REFLECS_COMPONENTS_GEOMETRY_H
#define REFLECS_COMPONENTS_GEOMETRY_H

#include "bake_config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsRectangle {
    float width;
    float height;
} EcsRectangle;

typedef struct EcsSquare {
    float size;
} EcsSquare;

typedef struct EcsCircle {
    float radius;
} EcsCircle;

typedef struct EcsTriangle {
    float width;
    float height;
} EcsTriangle;

typedef struct EcsComponentsGeometryHandles {
    EcsEntity Rectangle;
    EcsEntity Square;
    EcsEntity Circle;
    EcsEntity Triangle;
} EcsComponentsGeometryHandles;

void EcsComponentsGeometry(
    EcsWorld *world,
    int flags,
    void *handles_out);

#define EcsComponentsGeometry_DeclareHandles(handles)\
    EcsDeclareHandle(handles, Rectangle);\
    EcsDeclareHandle(handles, Square);\
    EcsDeclareHandle(handles, Circle);\
    EcsDeclareHandle(handles, Triangle);

#ifdef __cplusplus
}
#endif

#endif
