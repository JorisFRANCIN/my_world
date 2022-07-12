/*
** EPITECH PROJECT, 2022
** launch_game
** File description:
** launch the game
*/

#include "csfml.h"

void free_all(window_t *this_one, board_t *panel, world_map_t *content)
{
    for (int i = 0; panel->buttons[i] != NULL; i++) {
        sfRectangleShape_destroy(panel->buttons[i]->rect);
    }
    sfSprite_destroy(this_one->background->sprite);
    sfClock_destroy(this_one->clock);
    sfMusic_destroy(this_one->music);
    sfRenderWindow_destroy(this_one->window);
    free(this_one);
    free(panel);
    free(content);
}

void launch_game(window_t *this_one, int map_size)
{
    board_t *panel = init_board(this_one);
    world_map_t *map_content = init_map(map_size, this_one);

    while (sfRenderWindow_isOpen(this_one->window)) {
        this_one->mouse = sfMouse_getPositionRenderWindow(this_one->window);
            sfRenderWindow_clear(this_one->window, sfBlack);
            render(this_one, panel, map_content);
            update(this_one, panel, map_content);
            sfRenderWindow_display(this_one->window);
            sfClock_restart(this_one->clock);
    }
    free_all(this_one, panel, map_content);
}

