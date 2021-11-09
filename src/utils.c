/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** utils
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
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
        if (strcasecmp(fct_name[i], str) == 0)
            return i;
    return -1;
}

float *get_screen_size(void)
{
    static float size[2] = {1920, 1080};
    char **array = NULL;
    char screen_size[64];

    if (access("/dimensions", F_OK) == -1) // Need to find out the dimensions file path
        return size;
    FILE *cmd = popen("xdpyinfo | awk '/dimensions/ {print $2}'", "r");

    while (fgets(screen_size, sizeof(screen_size), cmd) != NULL);
    pclose(cmd);

    array = my_str_to_word_array(screen_size, 'x');
    size[0] = atof(array[0]);
    size[1] = atof(array[1]);
    for (unsigned int i = 0; array[i] != NULL; ++i)
        free(array[i]);
    free(array);

    return size;
}