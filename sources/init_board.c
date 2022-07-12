/*
** EPITECH PROJECT, 2022
** init_board
** File description:
** display the panel wich contains all the button
*/

#include "csfml.h"

board_t *init_board(window_t *this_one)
{
    sfVector2f size = {this_one->mode.width / 10, this_one->mode.height / 12};
    board_t *panel = malloc(sizeof(board_t));
    panel->buttons = malloc(sizeof(button_t *) * 8);
    panel->buttons[0] = init_button(
    (sfVector2f){this_one->mode.width - size.x, 0}, size, "images/exit.png");
    panel->buttons[1] = init_button(
    (sfVector2f){size.x, 0}, size, "images/zoomin.png");
    panel->buttons[2] = init_button((sfVector2f){0, 0}, size,
    "images/zoomout.png");
    panel->buttons[3] = init_button(
    (sfVector2f){(size.x) * 2, 0}, size,
    "images/rotate_right.png");
    panel->buttons[4] = init_button(
    (sfVector2f){(size.x) * 3, 0}, size, "images/rotate_left.png");
    panel->buttons[5] = init_button(
    (sfVector2f){(size.x) * 5, 0}, size, "images/tile.png");
    panel->buttons[6] = init_button(
    (sfVector2f){(size.x) * 6, 0}, size, "images/corner.png");
    panel->buttons[7] = NULL;
    return panel;
}