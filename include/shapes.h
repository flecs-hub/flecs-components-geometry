#ifndef REFLECS_COMPONENTS_SHAPES_H
#define REFLECS_COMPONENTS_SHAPES_H

#include <reflecs/reflecs.h>

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

typedef struct EcsComponentsShapesHandles {
    EcsHandle Rectangle;
    EcsHandle Square;
    EcsHandle Circle;
} EcsComponentShapesHandles;

void EcsComponentsShapes(
    EcsWorld *world,
    int flags,
    void *handles_out);

#ifdef __cplusplus
}
#endif

#endif
