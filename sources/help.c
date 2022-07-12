/*
** EPITECH PROJECT, 2021
** help
** File description:
** display -h option
*/

#include "csfml.h"

void help(void)
{
    my_printf("3d World created with CSFML.\n\n");
    my_printf("USAGE\n");
    my_printf("     ./my_world width height\n\n\n");
    my_printf("OPTIONS\n");
    my_printf("     -h  print the usage\n\n");
    my_printf("USER INTERACTIONS\n");
    my_printf("     LEFT_KEY move left.\n");
    my_printf("     RIGHT_KEY   move right\n");
    my_printf("     DOWN_KEY   move down\n");
    my_printf("     UP_KEY   move up\n");
    my_printf("     ESC/Button 'EXIT'     quit game\n");
    my_printf("     I_KEY/O_KEY   reduce/augment size\n");
    my_printf("     GREEN/BLUE button or SUBTRACT_KEY/ADD_KEY"
    " zoom out/zoom in\n");
    my_printf("     PURPLE/ORANGE button   rotate right/left\n");
    my_printf("     YELLOW/GREY button   select tile/corner\n\n");
}
