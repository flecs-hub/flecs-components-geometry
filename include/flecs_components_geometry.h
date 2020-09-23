#ifndef FLECS_COMPONENTS_GEOMETRY_H
#define FLECS_COMPONENTS_GEOMETRY_H

#include <flecs-components-geometry/bake_config.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct EcsLine2 {
    vec3 start;
    vec3 stop;
} EcsLine2;

typedef struct EcsLine3 {
    vec3 start;
    vec3 stop;
} EcsLine3;

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

ECS_STRUCT(EcsBox, {
    float width;
    float height;
    float depth;
});

typedef struct EcsMesh {
    vec3 *vertices;
    int32_t vertex_count;
} EcsMesh;

typedef struct EcsLineColor {
    ecs_rgba_t value;
} EcsLineColor;

typedef struct EcsLineWidth {
    float width;
} EcsLineWidth;

typedef struct FlecsComponentsGeometry {
    ECS_DECLARE_ENTITY(EcsPoint);
    ECS_DECLARE_COMPONENT(EcsLine2);
    ECS_DECLARE_COMPONENT(EcsLine3);
    ECS_DECLARE_COMPONENT(EcsRectangle);
    ECS_DECLARE_COMPONENT(EcsBox);
    ECS_DECLARE_COMPONENT(EcsCircle);
    ECS_DECLARE_COMPONENT(EcsSquare);
    ECS_DECLARE_COMPONENT(EcsMesh);
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
    ECS_IMPORT_COMPONENT(handles, EcsBox);\
    ECS_IMPORT_COMPONENT(handles, EcsMesh);\
    ECS_IMPORT_COMPONENT(handles, EcsLineColor);\
    ECS_IMPORT_COMPONENT(handles, EcsLineWidth);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

namespace flecs {
namespace components {

class geometry : FlecsComponentsGeometry {
public:
    using Line2 = EcsLine2;
    using Line3 = EcsLine3;
    using Rectangle = EcsRectangle;
    using Square = EcsSquare;
    using Circle = EcsCircle;
    using Box = EcsBox;
    using Mesh = EcsMesh;
    using Color =  EcsColor;
    using LineColor = EcsLineColor;
    using LineWidth = EcsLineWidth;

    geometry(flecs::world& ecs) {
        FlecsComponentsGeometryImport(ecs.c_ptr());

        ecs.module<flecs::components::geometry>();

        ecs.pod_component<Line2>("flecs::components::geometry::Line2");
        ecs.pod_component<Line3>("flecs::components::geometry::Line3");
        ecs.pod_component<Rectangle>("flecs::components::geometry::Rectangle");
        ecs.pod_component<Square>("flecs::components::geometry::Square");
        ecs.pod_component<Circle>("flecs::components::geometry::Circle");
        ecs.pod_component<Box>("flecs::components::geometry::Box");
        ecs.pod_component<Mesh>("flecs::components::geometry::Mesh");
        ecs.pod_component<LineColor>("flecs::components::geometry::LineColor");
        ecs.pod_component<LineWidth>("flecs::components::geometry::LineWidth");
    }
};

}
}

#endif

#endif
