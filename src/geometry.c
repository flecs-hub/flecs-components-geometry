#include <include/geometry.h>
#include <string.h>

void EcsComponentsGeometry(
    EcsWorld *world,
    int flags,
    void *handles_out)
{
    ECS_COMPONENT(world, EcsRectangle);
    ECS_COMPONENT(world, EcsSquare);
    ECS_COMPONENT(world, EcsCircle);
    ECS_COMPONENT(world, EcsTriangle);

    EcsComponentsGeometryHandles *handles = handles_out;
    memset(handles, 0, sizeof(EcsComponentsGeometryHandles));

    handles->Rectangle = EcsRectangle_h;
    handles->Square = EcsSquare_h;
    handles->Circle = EcsCircle_h;
    handles->Triangle = EcsTriangle_h;
}
