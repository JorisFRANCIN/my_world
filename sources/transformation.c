/*
** EPITECH PROJECT, 2022
** transformation
** File description:
** control of the map
*/

#include "csfml.h"

world_map_t *map_size(world_map_t *map_content, window_t *this_one)
{
    if (sfKeyboard_isKeyPressed(sfKeyI) && map_content->map_size >= 8) {
        map_content->map = rand_map(map_content->map_size - 2);
        map_content->color = color_select(map_content->map_size - 2);
        map_content->map_size = map_content->map_size - 2;
        map_content->pixel = 64;
        map_content->projected_map = create_2d_map(map_content);
        center_it(map_content, this_one);
        map_content->tiles = create_tile(map_content);
    }
    if (sfKeyboard_isKeyPressed(sfKeyO) && map_content->map_size <= 26) {
        map_content->map = rand_map(map_content->map_size + 2);
        map_content->color = color_select(map_content->map_size + 2);
        map_content->map_size = map_content->map_size + 2;
        map_content->pixel = 64;
        map_content->projected_map = create_2d_map(map_content);
        center_it(map_content, this_one);
        map_content->tiles = create_tile(map_content);
    }
    return map_content;
}

world_map_t *movement_ctrl(world_map_t *map_content, window_t *this_one)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        move(map_content,  -(map_content->pixel / 12), 0);
        map_content->tiles = create_tile(map_content);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        move(map_content,  map_content->pixel / 12, 0);
        map_content->tiles = create_tile(map_content);
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        move(map_content,  0, -(map_content->pixel / 12));
        map_content->tiles = create_tile(map_content);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        move(map_content, 0, map_content->pixel / 12);
        map_content->tiles = create_tile(map_content);
    }
    map_size(map_content, this_one);
    return map_content;
}

world_map_t *transformation(window_t *this_one, world_map_t *map_content,
board_t *panel)
{
    if (sfKeyboard_isKeyPressed(sfKeyAdd) && map_content->pixel <= 128) {
        map_content->pixel += 2;
        map_content->projected_map = create_2d_map(map_content);
        center_it(map_content, this_one);
        map_content->tiles = create_tile(map_content);
    }
    if (sfKeyboard_isKeyPressed(sfKeySubtract) && map_content->pixel >= 14) {
        map_content->pixel -= 2;
        map_content->projected_map = create_2d_map(map_content);
        center_it(map_content, this_one);
        map_content->tiles = create_tile(map_content);
    }
    if (sfKeyboard_isKeyPressed(sfKeyR)) {
        map_content->projected_map = create_2d_map(map_content);
        center_it(map_content, this_one);
        map_content->tiles = create_tile(map_content);
    }
    analyse_events(this_one, panel, map_content);
    return map_content;
}
