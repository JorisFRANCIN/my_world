/*
** EPITECH PROJECT, 2022
** color_index
** File description:
** color_index chosen
*/

#include "csfml.h"

sfColor color_index(window_t *this_one)
{
    sfColor color;
    if (this_one->tile_button == 1)
        color = sfColor_fromRGB(255,211,25);
    if (this_one->tile_button == 2)
        color = sfColor_fromRGB(255,144,31);
    if (this_one->tile_button == 3)
        color = sfColor_fromRGB(255,41,117);
    if (this_one->tile_button == 4)
        color = sfColor_fromRGB(242,34,255);
    if (this_one->tile_button == 5)
        color = sfColor_fromRGB(140,30,255);
    if (this_one->tile_button == 6)
        color = sfBlack;
    return color;
}