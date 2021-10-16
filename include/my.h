/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** include
*/

#ifndef MY_H_INCLUDED
#define MY_H_INCLUDED

#include <stdbool.h>

static const int LAST_CHAR = 1;

unsigned int my_strlen(char const *str);
bool char_in_number(char const *str);
unsigned int my_intlen(int nb);
char *my_strcat(char *dest, char *src, char *extra);
char **my_str_to_word_array(char *str, char const del);
char **my_getline(void);
unsigned int tablen(char const **array);

#endif /* !MY_H_ */