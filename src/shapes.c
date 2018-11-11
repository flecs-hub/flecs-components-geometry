#include <include/shapes.h>
#include <string.h>

void EcsComponentsShapes(
    EcsWorld *world,
    int flags,
    void *handles_out)
{
    ECS_COMPONENT(world, EcsRectangle);
    ECS_COMPONENT(world, EcsSquare);
    ECS_COMPONENT(world, EcsCircle);

    EcsComponentShapesHandles *handles = handles_out;
    memset(handles, 0, sizeof(EcsComponentShapesHandles));

    handles->Rectangle = EcsRectangle_h;
    handles->Square = EcsSquare_h;
    handles->Circle = EcsCircle_h;
}
