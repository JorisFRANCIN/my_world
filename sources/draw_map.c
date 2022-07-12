/*
** EPITECH PROJECT, 2022
** draw_map
** File description:
** draw isometric plan map
*/

#include "csfml.h"

int **rand_map(int map_size)
{
    int **map = malloc(sizeof(int *) * map_size);
    for (int i = 0; i != map_size; i++) {
        map[i] = malloc(sizeof(int) * map_size);
        for (int j = 0; j != map_size; j++) {
            map[i][j] = 0;
        }
    }
    map[map_size] = NULL;
    default_gen(map, map_size);
    return map;
}

sfVertexArray *create_line(sfVector2f *point1, sfVector2f *point2,
sfVector2i index, int size)
{
    sfColor color = sfColor_fromRGB(242,34,255);
    if ((index.x >= (size + 1) / 2 && index.x < size + 1) ||
        (index.y >= (size + 1) / 2 && index.y < size + 1))
        color = sfColor_fromRGB(1,97,232);
    if ((index.x >= size + 1 && index.x < (size + 1) * 2) ||
        (index.y >= size + 1 && index.y < (size + 1) * 2))
        color = sfColor_fromRGB(255, 1, 154);
    if (index.x >= (size + 1) * 2 || index.y >= (size + 1) * 2)
        color = sfColor_fromRGB(0, 241, 255);
    sfVertexArray *vertex_array = sfVertexArray_create();
    sfVertex vertex1 = {.position = *point1, .color = color};
    sfVertex vertex2 = {.position = *point2, .color = color};

    sfVertexArray_append(vertex_array, vertex1);
    sfVertexArray_append(vertex_array, vertex2);
    sfVertexArray_setPrimitiveType(vertex_array, sfLinesStrip);

    return(vertex_array);
}

int draw_2d_map(window_t *this_one, world_map_t *content)
{
    int map_size = content->map_size - 1;
    int **m = content->map;
    sfVector2f **d2_map = content->projected_map; 
    for (int i = 0; i != content->map_size - 1; i++) {
        for (int j = 0; j != content->map_size - 1; j++) {
            sfRenderWindow_drawConvexShape(this_one->window,
            content->tiles[i][j], NULL);
            sfRenderWindow_drawVertexArray(this_one->window, create_line(
            &d2_map[i][j], &d2_map[i + 1][j],
            (sfVector2i){m[i][j], m[i + 1][j]}, map_size), NULL);
            sfRenderWindow_drawVertexArray(this_one->window, create_line(
            &d2_map[i][j + 1], &d2_map[i][j],
            (sfVector2i){m[i][j + 1], m[i][j]}, map_size), NULL);
        }
        sfRenderWindow_drawVertexArray(this_one->window, create_line(
        &d2_map[map_size][i], &d2_map[map_size][i + 1],
        (sfVector2i){m[map_size][i], m[map_size][i + 1]}, map_size), NULL);
        sfRenderWindow_drawVertexArray(this_one->window, create_line(
        &d2_map[i][map_size], &d2_map[i + 1][map_size],
        (sfVector2i){m[i][map_size], m[i + 1][map_size]}, map_size), NULL);
    }
    return 0;
}

sfVector2f project_iso_point(int x, int y, int z)
{
    sfVector2f d2_point;

    d2_point.x = cos(ANGLE_X * M_PI / 180) * x - cos(ANGLE_X * M_PI / 180) * y;
    d2_point.y = sin(ANGLE_Y * M_PI / 180) * y +
    sin(ANGLE_Y * M_PI / 180) * x - z;

    return d2_point;
}

sfVector2f **create_2d_map(world_map_t *map_content)
{
    sfVector2f **d2_map = malloc(sizeof(sfVector2f *) * map_content->map_size);
    int pixel = map_content->pixel;

    for (int y = 0; y != map_content->map_size; y++) {
        d2_map[y] = malloc(sizeof(sfVector2f) * map_content->map_size);
        for (int x = 0; x != map_content->map_size; x++) {
            d2_map[y][x] = project_iso_point(x * pixel, y * pixel,
            map_content->map[y][x] * pixel / 6);
        }
    }
    return d2_map;
}
