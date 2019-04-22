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

typedef struct EcsPolygon8 {
    uint8_t point_count;
    EcsPoint2D points[8];
} EcsPolygon8;

typedef struct FlecsComponentsGeometry {
    ECS_DECLARE_ENTITY(EcsDot);
    ECS_DECLARE_COMPONENT(EcsRectangle);
    ECS_DECLARE_COMPONENT(EcsSquare);
    ECS_DECLARE_COMPONENT(EcsCircle);
    ECS_DECLARE_COMPONENT(EcsTriangle);
    ECS_DECLARE_COMPONENT(EcsPolygon8);
} FlecsComponentsGeometry;

void FlecsComponentsGeometryImport(
    ecs_world_t *world,
    int flags);

#define FlecsComponentsGeometryImportHandles(handles)\
    ECS_IMPORT_ENTITY(handles, EcsDot);\
    ECS_IMPORT_COMPONENT(handles, EcsRectangle);\
    ECS_IMPORT_COMPONENT(handles, EcsSquare);\
    ECS_IMPORT_COMPONENT(handles, EcsCircle);\
    ECS_IMPORT_COMPONENT(handles, EcsTriangle);\
    ECS_IMPORT_COMPONENT(handles, EcsPolygon8);

#ifdef __cplusplus
}
#endif

#endif
