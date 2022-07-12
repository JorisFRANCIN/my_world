/*
** EPITECH PROJECT, 2021
** my_h
** File description:
** Contains all the prototype of my library
*/

#include <stdlib.h>

#ifndef MY_H_
    #define MY_H_
void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
int my_put_nbr2(unsigned int nb);
char *my_strdup(char const *str);
int my_put_nbr_base(unsigned int nb, int flag2);
int my_put_nbr_hex(unsigned int nb, char flag);
int my_putstr2(char const *tr, int flag2);
int my_put_nbr_binary(unsigned int nb);
void *my_printf(char const *format, ...);
#endif  /* MY_H_ */
