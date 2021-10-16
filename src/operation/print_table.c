/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** print data's table
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_db.h"
#include "my.h"

void print_field_name(char const *str, float length)
{
    static unsigned short i = 0;
    static unsigned short t = 0;
    static unsigned short tmp = 0;

    if (t == NUMBER_FIELD)
        return;

    if (strcmp(str, field_name[0]) == 0)
        i = 2;
    for (; i <= (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD) / 2) - (my_strlen(str) / 2)) - 1; ++i)
        printf(" ");
    printf("%s", str);
    tmp = i;

    if (strcmp(str, field_name[0]) == 0)
        --i;
    for (; i > 0; --i)
        printf(" ");
    if (t + 1 < NUMBER_FIELD)
        printf("|");

    print_field_name(field_name[++t], length);
}

void print_separator(char const *str, float length)
{
    static unsigned short i = 0;
    static unsigned short tmp = 0;

    if (strcmp(str, field_name[0]) == 0)
        i = 2;
    for (; i <= (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD) / 2) - (my_strlen(str) / 2)) - 1; ++i)
        printf("-");
    for (unsigned short t = 0; t < my_strlen(str); ++t)
        printf("-");
    tmp = i;
    if (strcmp(str, field_name[0]) == 0)
        --i;
    for (; i > 0; --i)
        printf("-");
    if (strcmp(str, field_name[NUMBER_FIELD - 1]) != 0)
        printf("+");
}

void display_id(unsigned long long int id, float length)
{
    static unsigned short i = 1;
    static unsigned short tmp = 0;

    for (; i <= (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD) / 2) - (my_intlen(id) / 2)) - my_intlen(id) - 1; ++i)
        printf(" ");
    printf("%lld", id);

    for (; i > 1; --i)
        printf(" ");
    printf("|");
}

void display_str_field(char const *data, float length)
{
    unsigned short i = 0;
    static unsigned short status = 0;

    if (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD) / 2) - (my_strlen(data) / 2) > 100)
        for (; i <= (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD) / 2) - (my_strlen(data) / 2)); ++i)
            printf(" ");
    printf("%s", data);

    for (; i > 0; --i)
        printf(" ");
    ++status;

    if (status == 9) {
        printf("\n");
        status = 0;
        return;
    }
    printf("\n");
}

bool print_table(list_t **head, db_t **db)
{
    const float *size = get_screen_size();
    const float length = size[0];
    const float width = size[1];
    list_t *tmp = *head;

    for (unsigned int i = 0; i < ((TABLE_SIZE_X(length) / 2) - (my_strlen((char *)table_name)) / 2); ++i)
        printf(" ");
    printf("%s\n", table_name);
    for (unsigned int i = 0; i < TABLE_SIZE_X(length); ++i)
        printf("-");
    printf("\n\n\n");
    print_field_name(field_name[0], length);
    printf("\n");
    for (unsigned short int i = 0; i < NUMBER_FIELD; ++i)
        print_separator(field_name[i], length);
    printf("\n");

    // for (; tmp; tmp = tmp->next) {
    //     display_id(tmp->data->id, length);
    //     display_str_field(tmp->data->firstname, length);
    //     display_str_field(tmp->data->lastname, length);
    //     display_str_field(tmp->data->pseudonyme, length);
    //     display_str_field(tmp->data->birthday, length);
    //     display_str_field(tmp->data->city, length);
    //     display_str_field(tmp->data->phone, length);
    //     // display_str_field(tmp->data->email, length);
    //     display_str_field(tmp->data->password, length);
    //     display_str_field(tmp->data->registeredAt, length);
    // }

     for (; tmp; tmp = tmp->next) {
        display_id(tmp->data->id, length);
        display_str_field(tmp->data->firstname, length);
    }
    printf("\n");

    return true;
}