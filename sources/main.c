/*
** EPITECH PROJECT, 2022
** main
** File description:
** init program
*/

#include "csfml.h"

int main(int argc, char **argv)
{
    int height = 0;
    int width = 0;
    int map_size = 10;

    argc == 2 && my_strcmp(argv[1], "-h") == 0 ? help() : 0;
    if (argc == 1) {
        height = 1080;
        width = 1920;
    } else if (argc == 3 && my_getnbr(argv[2]) >= 600 &&
        my_getnbr(argv[2]) <= 1080 && my_getnbr(argv[1]) >= 900 &&
        my_getnbr(argv[1]) <= 1920) {
        height = my_getnbr(argv[2]);
        width = my_getnbr(argv[1]);
    } else {
        return ERROR_ARG;
    }
    window_t *this_one = window_init(height, width);
    launch_game(this_one, map_size);
    return 0;
}