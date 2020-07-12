#include <flecs_components_geometry.h>
#include <string.h>

ECS_COPY(EcsMesh, dst, src, {
    if (dst->vertices) {
        ecs_os_free(dst->vertices);
    }

    if (src->vertices) {
        size_t size = sizeof(ecs_vert3_t) * src->vertex_count;
        dst->vertices = ecs_os_malloc(size);
        dst->vertex_count = src->vertex_count;
        memcpy(dst->vertices, src->vertices, size);
    } else {
        dst->vertices = NULL;
        dst->vertex_count = 0;
    }
});

ECS_MOVE(EcsMesh, dst, src, {
    if (dst->vertices) {
        ecs_os_free(dst->vertices);
    }

    dst->vertices = src->vertices;
    dst->vertex_count = src->vertex_count;
    src->vertices = NULL;
    src->vertex_count = 0;
});

ECS_DTOR(EcsMesh, ptr, {
    ecs_os_free(ptr->vertices);
});

void FlecsComponentsGeometryImport(
    ecs_world_t *world)
{
    ECS_MODULE(world, FlecsComponentsGeometry);

    ecs_set_name_prefix(world, "Ecs");

    ECS_IMPORT(world, FlecsMeta);
    ECS_IMPORT(world, FlecsComponentsGraphics);

    ECS_TAG(world, EcsPoint);
    ECS_META(world, EcsLine2);
    ECS_META(world, EcsLine3);
    ECS_META(world, EcsRectangle);
    ECS_META(world, EcsSquare);
    ECS_META(world, EcsCircle);
    ECS_META(world, EcsPolygon8);
    ECS_META(world, EcsMesh);
    ECS_META(world, EcsColor);
    ECS_META(world, EcsLineColor);
    ECS_META(world, EcsLineWidth);

    ECS_EXPORT_ENTITY(EcsPoint);
    ECS_EXPORT_COMPONENT(EcsLine2);
    ECS_EXPORT_COMPONENT(EcsLine3);
    ECS_EXPORT_COMPONENT(EcsRectangle);
    ECS_EXPORT_COMPONENT(EcsSquare);
    ECS_EXPORT_COMPONENT(EcsCircle);
    ECS_EXPORT_COMPONENT(EcsPolygon8);
    ECS_EXPORT_COMPONENT(EcsColor);
    ECS_EXPORT_COMPONENT(EcsLineColor);
    ECS_EXPORT_COMPONENT(EcsLineWidth);

    ecs_set_component_actions(world, EcsMesh, {
        .copy = ecs_copy(EcsMesh),
        .move = ecs_move(EcsMesh),
        .dtor = ecs_dtor(EcsMesh)
    });
}
