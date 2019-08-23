#include <flecs_components_geometry.h>
#include <string.h>

void FlecsComponentsGeometryImport(
    ecs_world_t *world,
    int flags)
{
    ECS_MODULE(world, FlecsComponentsGeometry);

    ECS_TAG(world, EcsDot);
    ECS_COMPONENT(world, EcsLine);
    ECS_COMPONENT(world, EcsRectangle);
    ECS_COMPONENT(world, EcsSquare);
    ECS_COMPONENT(world, EcsCircle);
    ECS_COMPONENT(world, EcsTriangle);
    ECS_COMPONENT(world, EcsPolygon8);

    ECS_SET_ENTITY(EcsDot);
    ECS_SET_COMPONENT(EcsLine);
    ECS_SET_COMPONENT(EcsRectangle);
    ECS_SET_COMPONENT(EcsSquare);
    ECS_SET_COMPONENT(EcsCircle);
    ECS_SET_COMPONENT(EcsTriangle);
    ECS_SET_COMPONENT(EcsPolygon8);
}
