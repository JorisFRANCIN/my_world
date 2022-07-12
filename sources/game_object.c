/*
** EPITECH PROJECT, 2021
** game_object
** File description:
** Init game objects
*/

#include "csfml.h"

struct game_object *create_object(const char *p, sfVector2f po, sfIntRect rect)
{

    asset *obj = malloc(sizeof(asset));
    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(p, NULL);
    obj->pos = po;
    obj->rect = rect;

    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setPosition(obj->sprite, obj->pos);
    return obj;
}
