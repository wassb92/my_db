/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** utils
*/

#include <stdlib.h>

void free_getline(char **getline)
{
    if (!getline)
        return;
    for (unsigned int i = 0; getline[i] != NULL; ++i) {
        free(getline[i]);
        getline[i] = NULL;
    }
    free(getline);
    getline = NULL;
}