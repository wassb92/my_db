/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** my_getline
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "const.h"

char **my_getline(void)
{
    char *input = NULL;
    char **array = NULL;
    size_t size = 0;

    if (getline(&input, &size, stdin) == -1) {
        free(input);
        return NULL;
    }
    if (size == 0)
        return NULL;
    if (input[my_strlen(input) - 1] == '\n')
        input[my_strlen(input) - 1] = '\0';

    array = my_str_to_word_array(input, SPACE_DEL);
    free(input);
    if (!array || !*array) {
        free(array);
        return NULL;
    }
    return array;
}