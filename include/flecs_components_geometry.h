#ifndef FLECS_COMPONENTS_GEOMETRY_H
#define FLECS_COMPONENTS_GEOMETRY_H

#include <flecs-components-geometry/bake_config.h>

#ifdef __cplusplus
extern "C" {
#endif

ECS_STRUCT(EcsLine2, {
    ecs_vert2_t start;
    ecs_vert2_t stop;
});

ECS_STRUCT(EcsLine3, {
    ecs_vert3_t start;
    ecs_vert3_t stop;
});

ECS_STRUCT(EcsRectangle, {
    float width;
    float height;
});

ECS_STRUCT(EcsSquare, {
    float size;
});

ECS_STRUCT(EcsCircle, {
    float radius;
});

ECS_STRUCT(EcsPolygon8, {
    ecs_poly8_t value;
});

ECS_STRUCT(EcsMesh, {
    ecs_vert3_t *vertices;
    int32_t vertex_count;
});

ECS_STRUCT(EcsColor, {
    ecs_rgba_t value;
});

ECS_STRUCT(EcsLineColor, {
    ecs_rgba_t value;
});

ECS_STRUCT(EcsLineWidth, {
    float width;
});

typedef struct FlecsComponentsGeometry {
    ECS_DECLARE_ENTITY(EcsPoint);
    ECS_DECLARE_COMPONENT(EcsLine2);
    ECS_DECLARE_COMPONENT(EcsLine3);
    ECS_DECLARE_COMPONENT(EcsRectangle);
    ECS_DECLARE_COMPONENT(EcsSquare);
    ECS_DECLARE_COMPONENT(EcsCircle);
    ECS_DECLARE_COMPONENT(EcsPolygon8);
    ECS_DECLARE_COMPONENT(EcsMesh);
    ECS_DECLARE_COMPONENT(EcsColor);
    ECS_DECLARE_COMPONENT(EcsLineColor);
    ECS_DECLARE_COMPONENT(EcsLineWidth);
} FlecsComponentsGeometry;

FLECS_COMPONENTS_GEOMETRY_EXPORT
void FlecsComponentsGeometryImport(
    ecs_world_t *world);

#define FlecsComponentsGeometryImportHandles(handles)\
    ECS_IMPORT_ENTITY(handles, EcsPoint);\
    ECS_IMPORT_COMPONENT(handles, EcsLine2);\
    ECS_IMPORT_COMPONENT(handles, EcsLine3);\
    ECS_IMPORT_COMPONENT(handles, EcsRectangle);\
    ECS_IMPORT_COMPONENT(handles, EcsSquare);\
    ECS_IMPORT_COMPONENT(handles, EcsCircle);\
    ECS_IMPORT_COMPONENT(handles, EcsPolygon8);\
    ECS_IMPORT_COMPONENT(handles, EcsMesh);\
    ECS_IMPORT_COMPONENT(handles, EcsColor);\
    ECS_IMPORT_COMPONENT(handles, EcsLineColor);\
    ECS_IMPORT_COMPONENT(handles, EcsLineWidth);

#ifdef __cplusplus
}
#endif

#endif
