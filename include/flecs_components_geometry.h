#ifndef FLECS_COMPONENTS_GEOMETRY_H
#define FLECS_COMPONENTS_GEOMETRY_H

#include <flecs-components-geometry/bake_config.h>

// Reflection system boilerplate
#undef ECS_META_IMPL
#ifndef FLECS_COMPONENTS_GEOMETRY_IMPL
#define ECS_META_IMPL EXTERN // Ensure meta symbols are only defined once
#endif

FLECS_COMPONENTS_GEOMETRY_API
ECS_STRUCT(EcsLine2, {
    vec3 start;
    vec3 stop;
});

FLECS_COMPONENTS_GEOMETRY_API
ECS_STRUCT(EcsLine3, {
    vec3 start;
    vec3 stop;
});

FLECS_COMPONENTS_GEOMETRY_API
ECS_STRUCT(EcsRectangle, {
    float width;
    float height;
});

typedef EcsRectangle ecs_rect_t;

FLECS_COMPONENTS_GEOMETRY_API
ECS_STRUCT(EcsSquare, {
    float size;
});

FLECS_COMPONENTS_GEOMETRY_API
ECS_STRUCT(EcsCircle, {
    float radius;
});

FLECS_COMPONENTS_GEOMETRY_API
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

class geometry {
public:
    using Line2 = EcsLine2;
    using Line3 = EcsLine3;
    using Rectangle = EcsRectangle;
    using Square = EcsSquare;
    using Circle = EcsCircle;
    using Box = EcsBox;

    geometry(flecs::world& ecs) {
        // Load module contents
        FlecsComponentsGeometryImport(ecs);

        // Bind C++ types with module contents
        ecs.module<flecs::components::geometry>();
        ecs.component<Line2>();
        ecs.component<Line3>();
        ecs.component<Rectangle>();
        ecs.component<Square>();
        ecs.component<Circle>();
        ecs.component<Box>();
    }
};

}
}
#endif
#endif

#endif
