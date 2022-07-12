/*
** EPITECH PROJECT, 2022
** default_gen
** File description:
** gen a rand map which keeps its form natural
*/

#include "csfml.h"

int choose_altitude(int index, int map_size)
{
    int val = 0;

    if (index == 0)
        val = map_size / 2;
    if (index == 1)
        val = map_size;
    if (index == 2)
        val = map_size * 2;

    return val;
}

int **default_gen(int **map, int map_size)
{
    for (int i = 1; i != map_size - 1; i++) {
        map[i][1] = choose_altitude(rand() % 3, map_size);
        map[1][i] = choose_altitude(rand() % 3, map_size);
    }

    return map;
}
