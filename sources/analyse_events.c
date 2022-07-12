/*
** EPITECH PROJECT, 2021
** analyses_event
** File description:
** Detect which "event" is it
*/

#include "csfml.h"

void zoom_event(sfMouseButtonEvent event, board_t *panel,
window_t *this_one, world_map_t *content)
{
    if (sfIntRect_contains(&panel->buttons[1]->hitbox,
        event.x, event.y) == sfTrue && content->pixel <= 160) {
        content->pixel += 16;
        content->projected_map = create_2d_map(content);
        center_it(content, this_one);
        content->tiles = create_tile(content);
    }
    if (sfIntRect_contains(&panel->buttons[2]->hitbox,
        event.x, event.y) == sfTrue && content->pixel >= 32) {
        content->pixel -= 16;
        content->projected_map = create_2d_map(content);
        center_it(content, this_one);
        content->tiles = create_tile(content);
    }
}

void rotate_event(sfMouseButtonEvent event, board_t *panel,
window_t *this_one, world_map_t *content)
{
    if (sfIntRect_contains(&panel->buttons[4]->hitbox,
        event.x, event.y) == sfTrue) {
        rotate_left(content, content->map_size, content->map_size - 1);
        content->projected_map = create_2d_map(content);
        center_it(content, this_one);
        content->tiles = create_tile(content);
    }
    if (sfIntRect_contains(&panel->buttons[3]->hitbox,
        event.x, event.y) == sfTrue) {
        rotate_right(content, content->map_size, content->map_size - 1);
        content->projected_map = create_2d_map(content);
        center_it(content, this_one);
        content->tiles = create_tile(content);
    }
}

void mouse_event(sfMouseButtonEvent event, board_t *panel,
window_t *this_one) {
    if (sfIntRect_contains(&panel->buttons[5]->hitbox,
        event.x, event.y) == sfTrue) {
        this_one->tile_button += 1;
        this_one->corner_button = 0;
        if (this_one->tile_button == 8)
            this_one->tile_button = 1;
    }
    if (sfIntRect_contains(&panel->buttons[6]->hitbox,
        event.x, event.y) == sfTrue) {
        this_one->tile_button = 0;
        this_one->corner_button += 1;
        if (this_one->corner_button == 3)
            this_one->corner_button = 1;
    }
}

int manage_mouse_click(sfMouseButtonEvent event, board_t *panel,
window_t *this_one, world_map_t *content)
{
    if (sfIntRect_contains(&panel->buttons[0]->hitbox,
        event.x, event.y) == sfTrue) {
        sfRenderWindow_close(this_one->window);
    }
    zoom_event(event, panel, this_one, content);
    rotate_event(event, panel, this_one, content);
    mouse_event(event, panel, this_one);
    return 0;
}

sfMouseButtonEvent analyse_events(window_t *this_one, board_t *panel,
world_map_t *content)
{
    if (sfRenderWindow_pollEvent(this_one->window, &this_one->event)) {
        if (this_one->event.type == sfEvtMouseButtonPressed) {
            manage_mouse_click(this_one->event.mouseButton, panel, this_one,
            content);
        }
        if (this_one->event.type == sfEvtClosed ||
            sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(this_one->window);
    }
    return this_one->event.mouseButton;
}
