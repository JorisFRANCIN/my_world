/*
** EPITECH PROJECT, 2022
** init_map
** File description:
** init struct map
*/

#include "csfml.h"

sfColor **color_select(int map_size)
{
    sfColor **color = malloc(sizeof(sfColor *) * map_size - 1);
    for (int i = 0; i != map_size - 1; i++) {
        color[i] = malloc(sizeof(sfColor) * map_size - 1);
        for (int j = 0; j != map_size - 1; j++) {
            color[i][j] = sfBlack;
        }
    }
    color[map_size - 1] = NULL;
    return color;
}

sfConvexShape ***create_tile(world_map_t *content)
{
    sfVector2f **map = content->projected_map;
    sfConvexShape ***tiles = malloc(sizeof(sfConvexShape **) *
    content->map_size - 1);
    for (int i = 0; i != content->map_size - 1; i++) {
        tiles[i] = malloc(sizeof(sfConvexShape *) * content->map_size - 1);
        for (int j = 0; j != content->map_size - 1; j++) {
            tiles[i][j] = sfConvexShape_create();
            sfConvexShape_setPointCount(tiles[i][j], 4);
            sfConvexShape_setPoint(tiles[i][j], 0, map[i][j]);
            sfConvexShape_setPoint(tiles[i][j], 1, map[i][j + 1]);
            sfConvexShape_setPoint(tiles[i][j], 2, map[i + 1][j + 1]);
            sfConvexShape_setPoint(tiles[i][j], 3, map[i + 1][j]);
            sfConvexShape_setFillColor(tiles[i][j], content->color[i][j]);
        }
    }

    return tiles;
}

world_map_t *center_it(world_map_t *content, window_t *this_one)
{
    int map_size = content->map_size;
    int length = this_one->mode.height -
    content->projected_map[map_size - 1][map_size - 1].y;
    for (int y = 0; y != content->map_size; y++) {
        for (int x = 0; x != content->map_size; x++) {
            content->projected_map[y][x].x += this_one->mode.width / 2;
            content->projected_map[y][x].y += length / 2;
        }
    }
    return content;
}

world_map_t *init_map(int map_size, window_t *this_one)
{
    world_map_t *map_content = malloc(sizeof(world_map_t));
    map_content->map = rand_map(map_size);
    map_content->color = color_select(map_size);
    map_content->map_size = map_size;
    map_content->pixel = 64;
    map_content->projected_map = create_2d_map(map_content);
    center_it(map_content, this_one);
    map_content->tiles = create_tile(map_content);

    return map_content;
}
