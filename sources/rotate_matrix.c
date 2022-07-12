/*
** EPITECH PROJECT, 2022
** rotate_matrix
** File description:
** rotate either left or right the matrix
*/

#include "csfml.h"

world_map_t *rotate_left(world_map_t *content, int map_size, int map_size2)
{
    int **map = content->map;
    sfColor **color = content->color;
    for (int i = 0; i != map_size / 2; i++) {
        for (int j = i; j != map_size - i - 1; j++) {
            int tmp = map[i][j];
            map[i][j] = map[map_size - 1 - j][i];
            map[map_size - 1 - j][i] = map[map_size - 1 - i][map_size - 1 - j];
            map[map_size - 1 - i][map_size - 1 - j] = map[j][map_size - 1 - i];
            map[j][map_size - 1 - i] = tmp;
        }
    }
    for (int i = 0; i != map_size2 / 2; i++) {
        for (int j = i; j != map_size2 - i - 1; j++) {
            sfColor tmp2 = color[i][j];
            color[i][j] = color[map_size2 - 1 - j][i];
            color[map_size2 - 1 - j][i] = color[map_size2 - 1 - i][map_size2 - 1 - j];
            color[map_size2 - 1 - i][map_size2 - 1 - j] = color[j][map_size2 - 1 - i];
            color[j][map_size2 - 1 - i] = tmp2;
        }
    }
    return content;
}

world_map_t *rotate_right(world_map_t *content, int map_size, int map_size2)
{
    int **map = content->map;
    sfColor **c = content->color;
    for (int i = 0; i != map_size / 2; i++) {
        for (int j = i; j != map_size - i - 1; j++) {
            int tmp = map[i][j];
            map[i][j] = map[j][map_size - 1 - i];
            map[j][map_size - 1 - i] = map[map_size - 1 - i][map_size - 1 - j];
            map[map_size - 1 - i][map_size - 1 - j] = map[map_size - 1 - j][i];
            map[map_size - 1 - j][i] = tmp;
        }
    }
    for (int i = 0; i != map_size2 / 2; i++) {
        for (int j = i; j != map_size2 - i - 1; j++) {
            sfColor tmp2 = c[i][j];
            c[i][j] = c[j][map_size2 - 1 - i];
            c[j][map_size2 - 1 - i] = c[map_size2 - 1 - i][map_size2 - 1 - j];
            c[map_size2 - 1 - i][map_size2 - 1 - j] = c[map_size2 - 1 - j][i];
            c[map_size2 - 1 - j][i] = tmp2;
        }
    }
    return content;
}