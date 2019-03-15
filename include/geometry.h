#ifndef FLECS_COMPONENTS_GEOMETRY_H
#define FLECS_COMPONENTS_GEOMETRY_H

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
    ECS_DECLARE_COMPONENT(EcsRectangle);
    ECS_DECLARE_COMPONENT(EcsSquare);
    ECS_DECLARE_COMPONENT(EcsCircle);
    ECS_DECLARE_COMPONENT(EcsTriangle);
} EcsComponentsGeometryHandles;

void EcsComponentsGeometry(
    EcsWorld *world,
    int flags,
    void *handles_out);

#define EcsComponentsGeometry_DeclareHandles(handles)\
    ECS_IMPORT_COMPONENT(handles, EcsRectangle);\
    ECS_IMPORT_COMPONENT(handles, EcsSquare);\
    ECS_IMPORT_COMPONENT(handles, EcsCircle);\
    ECS_IMPORT_COMPONENT(handles, EcsTriangle);

#ifdef __cplusplus
}
#endif

#endif
