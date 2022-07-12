/*
** EPITECH PROJECT, 2021
** window_object
** File description:
** init an object for window
*/

#include "csfml.h"

window_t *window_init(int height, int width)
{
    window_t *this_one = malloc(sizeof(window_t));

    this_one->mode.height = height;
    this_one->mode.width = width;
    this_one->mode.bitsPerPixel = 32;
    this_one->window = sfRenderWindow_create(this_one->mode, "My_World",
                sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(this_one->window, 144);
    this_one->clock = sfClock_create();
    this_one->music = sfMusic_createFromFile("images/MHz.ogg");
    this_one->background = create_object("images/background.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, this_one->mode.width,
    this_one->mode.height});
    this_one->corner_button = 0;
    this_one->tile_button = 0;
    sfMusic_setLoop(this_one->music, sfTrue);
    sfMusic_play(this_one->music);
    return this_one;
}
