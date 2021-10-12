/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** utils
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "my.h"

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

short find_index(char const *str, char const **fct_name)
{
    for (unsigned short i = 0; fct_name[i] != NULL; ++i)
        if (strcmp(fct_name[i], str) == 0)
            return i;
    return -1;
}

float *get_screen_size(void)
{
    static float size[2];
    char **array = NULL;

    FILE *cmd = popen("xdpyinfo | awk '/dimensions/ {print $2}'", "r");

    char screen_size[64];
    while (fgets(screen_size, sizeof(screen_size), cmd) != NULL);
    pclose(cmd);
    array = my_str_to_word_array(screen_size, 'x');
    size[0] = atof(array[0]);
    size[1] = atof(array[1]);
    size[2] = -1;
    for (unsigned int i = 0; array[i] != NULL; ++i)
        free(array[i]);
    free(array);

    return size;
}