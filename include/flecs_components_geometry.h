#ifndef FLECS_COMPONENTS_GEOMETRY_H
#define FLECS_COMPONENTS_GEOMETRY_H

#include <flecs-components-geometry/bake_config.h>

// Reflection system boilerplate
#undef ECS_META_IMPL
#ifndef FLECS_COMPONENTS_GEOMETRY_IMPL
#define ECS_META_IMPL EXTERN // Ensure meta symbols are only defined once
#endif

FLECS_COMPONENTS_GEOMETRY_API
ECS_STRUCT(EcsDrawDistance, {
    float far_;
});

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

FLECS_COMPONENTS_GEOMETRY_API
ECS_STRUCT(EcsStrokeWidth, {
    float value;
    float left;
    float right;
    float top;
    float bottom;
});

FLECS_COMPONENTS_GEOMETRY_API
extern ECS_COMPONENT_DECLARE(EcsStrokeColor);
typedef EcsRgb EcsStrokeColor;

FLECS_COMPONENTS_GEOMETRY_API
ECS_STRUCT(EcsCornerRadius, {
    float value;
    float top_left;
    float top_right;
    float bottom_left;
    float bottom_right;
});

typedef EcsRectangle ecs_rect_t;

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

FLECS_COMPONENTS_GEOMETRY_API
extern ECS_DECLARE(EcsGeometry);

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
    using StrokeWidth = EcsStrokeWidth;
    using CornerRadius = EcsCornerRadius;
    using Circle = EcsCircle;
    using Box = EcsBox;

    struct StrokeColor {
        float r;
        float g;
        float b;
    };

    geometry(flecs::world& ecs) {
        // Load module contents
        FlecsComponentsGeometryImport(ecs);

        // Bind C++ types with module contents
        ecs.module<flecs::components::geometry>();
        ecs.component<Line2>();
        ecs.component<Line3>();
        ecs.component<Rectangle>();
        ecs.component<Circle>();
        ecs.component<Box>();
        ecs.component<StrokeWidth>();
        ecs.component<StrokeColor>();
    }
};

}
}
#endif
#endif

#endif
