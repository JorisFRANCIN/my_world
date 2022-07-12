/*
** EPITECH PROJECT, 2022
** init_button
** File description:
** create button
*/

#include "csfml.h"

button_t *init_button(sfVector2f position, sfVector2f size, char *filename)
{
    button_t *button = malloc(sizeof(button_t));
    sfIntRect rectangle;
    rectangle.top = 0;
    rectangle.left = position.x;
    rectangle.width = size.x;
    rectangle.height = size.y;
    button->hitbox = rectangle;
    button->rect = sfRectangleShape_create();
    sfTexture *texture = sfTexture_createFromFile(filename, NULL);

    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setTexture(button->rect, texture, sfFalse);
    return button;
}
