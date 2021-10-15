/*
** EPITECH PROJECT, 2022
** my lib
** File description:
** my lib
*/

#include <stdlib.h>
#include "my.h"

unsigned int my_strlen(char const *str)
{
    unsigned int i = 0;

    if (str == NULL || str[0] == '\0')
        return i;

    while (str[++i]);

    return i;
}

bool char_in_number(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i)
        if (!(str[i] >= '0' && str[i] <= '9'))
            return true;
    return false;
}

unsigned int my_intlen(int nb)
{
    unsigned int i = 0;

    nb == 0 ? ++i : 0;
    nb < 0 ? nb *= -1 : 0;

    if (nb > 0)
        for (; nb > 0; nb /= 10)
            ++i;

    return i;
}

char *my_strcat(char *dest, char *src, char *extra)
{
    unsigned int i = 0;
    size_t size = my_strlen(dest) + my_strlen(src) + my_strlen(extra) + LAST_CHAR;
    char *str = malloc(sizeof(char) * size);

    if (!str)
        return NULL;
    if (dest != NULL)
        for (int t = 0; dest[t] != '\0'; ++t, ++i)
            str[i] = dest[t];
    if (src != NULL)
        for (int t = 0; src[t] != '\0'; ++t, ++i)
            str[i] = src[t];
    if (extra != NULL)
        for (int t = 0; extra[t] != '\0'; ++t, ++i)
            str[i] = extra[t];
    str[i] = '\0';

    return str;
}

char **my_str_to_word_array(char *str, char const del)
{
    unsigned int count = 1;
    unsigned int d = 0;
    unsigned int k = 0;
    char **array = NULL;

    for (unsigned int i = 0; str[i] != '\0'; ++i)
        str[i] == del ? ++count : 0;
    array = malloc(sizeof(char *) * (count + LAST_CHAR));
    if (!array)
        return NULL;
    for (unsigned int a = 0; a < count; ++a, ++k) {
        array[a] = malloc(sizeof(char) * (my_strlen(str) + LAST_CHAR));
        for (d = 0; str[k] != del && str[k] != '\0'; ++k, ++d)
            array[a][d] = str[k];
        array[a][d] = '\0';
    }
    array[count] = NULL;
    return array;
}

unsigned int tablen(char const **array)
{
    unsigned int i = 0;

    if (!array)
        return i;

    for (; array[i] != NULL; ++i);

    return i;
}