/*
** EPITECH PROJECT, 2022
** update
** File description:
** update the current changes that reside in the program
*/

#include "csfml.h"

world_map_t *move(world_map_t *content, int mx, int my)
{
    for (int y = 0; y != content->map_size; y++) {
        for (int x = 0; x != content->map_size; x++) {
            content->projected_map[y][x].x += mx;
            content->projected_map[y][x].y += my;
        }
    }
    return content;
}

void update(window_t *this_one, board_t *panel, world_map_t *map_content)
{
    movement_ctrl(map_content, this_one);
    transformation(this_one, map_content, panel);
    advance_events(this_one, map_content);
}
