/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** my_strcpy
*/

#include "runner_includes.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
