/*
** EPITECH PROJECT, 2022
** advance_events
** File description:
** special events for my_world
*/

#include "csfml.h"

world_map_t *in_this_tile(world_map_t *content, window_t *this_one,
int i, int j)
{
    sfColor index_color = color_index(this_one);
    sfVector2f tile_pos = sfConvexShape_getPoint(content->tiles[i][j], 0);
    sfVector2f tile_pos1 = sfConvexShape_getPoint(content->tiles[i][j], 1);
    sfVector2f tile_pos2 = sfConvexShape_getPoint(content->tiles[i][j], 2);
    sfVector2f tile_pos3 = sfConvexShape_getPoint(content->tiles[i][j], 3);

    if (this_one->mouse.x <= tile_pos1.x && this_one->mouse.x >= tile_pos3.x
    && this_one->mouse.y <= tile_pos2.y && this_one->mouse.y >= tile_pos.y &&
    this_one->event.type == sfEvtMouseButtonPressed) {
        content->color[i][j] = index_color;
        content->projected_map = create_2d_map(content);
        center_it(content, this_one);
        content->tiles = create_tile(content);
    }
    return content;
}

world_map_t *in_this_corner(world_map_t *content, window_t *this_one,
int i, int j)
{
    int value = 0;
    if (this_one->corner_button == 1)
        value = 1;
    if (this_one->corner_button == 2)
        value = -1;
    sfVector2f corner = content->projected_map[i][j];
    if (this_one->mouse.x >= corner.x - 10 &&
    this_one->mouse.x <= corner.x + 8
    && this_one->mouse.y >= corner.y - 10 &&
    this_one->mouse.y <= corner.y + 8
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        content->map[i][j] += value;
        content->projected_map = create_2d_map(content);
        center_it(content, this_one);
        content->tiles = create_tile(content);
    }
    return content;
}

world_map_t *tile_event(window_t *this_one, world_map_t *content)
{
    for (int i = 0; i != content->map_size - 1; i++) {
        for (int j = 0; j != content->map_size - 1; j++) {
            in_this_tile(content, this_one, i, j);
        }
    }
    return content;
}

world_map_t *corner_event(window_t *this_one, world_map_t *content)
{
    for (int i = 0; i != content->map_size - 1; i++) {
        for (int j = 0; j != content->map_size - 1; j++) {
            in_this_corner(content, this_one, i, j);
        }
    }
    return content;
}

world_map_t *advance_events(window_t *this_one, world_map_t *content)
{
    if (this_one->tile_button >= 1) {
        tile_event(this_one, content);
    }
    if (this_one->corner_button == 1 || this_one->corner_button == 2) {
        corner_event(this_one, content);
    }
    return content;
}