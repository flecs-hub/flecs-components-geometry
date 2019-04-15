#include <include/geometry.h>
#include <string.h>

void EcsComponentsGeometry(
    ecs_world_t *world,
    int flags,
    void *handles_out)
{
    ECS_COMPONENT(world, EcsRectangle);
    ECS_COMPONENT(world, EcsSquare);
    ECS_COMPONENT(world, EcsCircle);
    ECS_COMPONENT(world, EcsTriangle);
    ECS_COMPONENT(world, EcsPolygon8);

    EcsComponentsGeometryHandles *handles = handles_out;
    memset(handles, 0, sizeof(EcsComponentsGeometryHandles));

    ECS_SET_COMPONENT(handles, EcsRectangle);
    ECS_SET_COMPONENT(handles, EcsSquare);
    ECS_SET_COMPONENT(handles, EcsCircle);
    ECS_SET_COMPONENT(handles, EcsTriangle);
    ECS_SET_COMPONENT(handles, EcsPolygon8);
}
