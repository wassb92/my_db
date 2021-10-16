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
    static unsigned short i = 0;
    static unsigned short tmp = 0;

    for (; i <= (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD) / 2) - (my_intlen(id) / 2)) - my_intlen(id); ++i)
        printf(" ");
    printf("%lld", id);

    for (; i > 1; --i)
        printf(" ");
    printf("|");
}


void display(char const *data, float length)
{
    static unsigned short i = 0;

    for (; i <= (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD) / 2) - (my_strlen(data) / 2)) - 1; ++i)
        printf(" ");
    printf("%s", data);

    for (; i > 0; --i)
        printf(" ");
    printf("|");
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

//
    // db_t *db_data1 = {1, "Arthur", "Dupont", "Art123", "05/03/2000", "Paris", "06.05.04.03.02", "ArthurDupont@gmail.com", "arthur123", "03/10/2021"};
    // db_t *db_data2 = {2, "Arthurr", "Dupontt", "Art1234", "05/03/2001", "Pariss", "06.05.04.03.03", "ArthurDupont@gmail.comm", "arthur1234", "03/10/2022"};
    // db_t *db_data3 = {3, "Arthurrr", "Duponttt", "Art12345", "05/03/2002", "Parisss", "06.05.04.03.04", "ArthurDupont@gmail.commm", "arthur12345", "03/10/2023"};
    // db_t *db_data4 = {4, "Arthurrrr", "Dupontttt", "Art123456", "05/03/2003", "Parissss", "06.05.04.03.05", "ArthurDupont@gmail.commmm", "arthur123456", "03/10/2024"};
//
    // add_back(&tmp, &db_data1);
    // add_back(&tmp, &db_data2);
    // add_back(&tmp, &db_data3);
    // add_back(&tmp, &db_data4);
//
    // while (tmp) {
        // display_id((*db)->id, length);
        // printf("\n");
        // tmp = tmp->next;
    // }
    while (tmp) {
        printf("%lld\n", tmp->data->id);
        tmp = tmp->next;
    }
    // display((*db)->firstname, length);
    // display((*db)->lastname, length);
    // display((*db)->pseudonyme, length);
    // display((*db)->birthday, length);
    // display((*db)->city, length);
    // display((*db)->phone, length);
    // display((*db)->email, length);
    // display((*db)->password, length);
    // display((*db)->registeredAt, length);
    printf("\n");

    return true;
}