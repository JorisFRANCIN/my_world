/*
** EPITECH PROJECT, 2021
** render
** File description:
** render window
*/

#include "csfml.h"

void display_panel(window_t *this_one, board_t *panel)
{
    for (int i = 0; panel->buttons[i] != NULL; i++) {
        sfRenderWindow_drawRectangleShape(this_one->window,
        panel->buttons[i]->rect, NULL);
    }
}

void render(window_t *this_one, board_t *panel, world_map_t *map_content)
{
    sfRenderWindow_drawSprite(this_one->window,
    this_one->background->sprite, NULL);
    draw_2d_map(this_one, map_content);
    display_panel(this_one, panel);
}
