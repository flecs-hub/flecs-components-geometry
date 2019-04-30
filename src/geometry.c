#include <include/geometry.h>
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

    ECS_SET_ENTITY(handles, EcsDot);
    ECS_SET_COMPONENT(handles, EcsLine);
    ECS_SET_COMPONENT(handles, EcsRectangle);
    ECS_SET_COMPONENT(handles, EcsSquare);
    ECS_SET_COMPONENT(handles, EcsCircle);
    ECS_SET_COMPONENT(handles, EcsTriangle);
    ECS_SET_COMPONENT(handles, EcsPolygon8);
}
