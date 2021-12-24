#ifndef FLECS_COMPONENTS_GEOMETRY_H
#define FLECS_COMPONENTS_GEOMETRY_H

#include <flecs-components-geometry/bake_config.h>

// Reflection system boilerplate
#undef ECS_META_IMPL
#ifndef FLECS_COMPONENTS_GEOMETRY_IMPL
#define ECS_META_IMPL EXTERN // Ensure meta symbols are only defined once
#endif

ECS_STRUCT(EcsLine2, {
    vec3 start;
    vec3 stop;
});

ECS_STRUCT(EcsLine3, {
    vec3 start;
    vec3 stop;
});

ECS_STRUCT(EcsRectangle, {
    float width;
    float height;
});

typedef EcsRectangle ecs_rect_t;

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

extern ECS_DECLARE(EcsStaticGeometry);

// Not yet supported
typedef struct EcsMesh {
    vec3 *vertices;
    int32_t vertex_count;
} EcsMesh;

#ifdef __cplusplus
extern "C" {
#endif

FLECS_COMPONENTS_GEOMETRY_API
void FlecsComponentsGeometryImport(
    ecs_world_t *world);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#ifndef FLECS_NO_CPP

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

    geometry(flecs::world& ecs) {
        FlecsComponentsGeometryImport(ecs);

        ecs.module<flecs::components::geometry>();

        ecs.pod_component<Line2>("flecs::components::geometry::Line2");
        ecs.pod_component<Line3>("flecs::components::geometry::Line3");
        ecs.pod_component<Rectangle>("flecs::components::geometry::Rectangle");
        ecs.pod_component<Square>("flecs::components::geometry::Square");
        ecs.pod_component<Circle>("flecs::components::geometry::Circle");
        ecs.pod_component<Box>("flecs::components::geometry::Box");
    }
};

}
}
#endif
#endif

#endif
