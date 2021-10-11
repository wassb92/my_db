/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** utils
*/

#include <stdlib.h>
#include <string.h>

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

unsigned short find_index(char const *str, char const **fct_name)
{
    for (unsigned short i = 0; fct_name[i] != NULL; ++i)
        if (strcmp(fct_name[i], str) == 0)
            return i;
    return -1;
}