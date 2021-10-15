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

void print_in_middle(db_t *db, float t, float length, float width)
{
    if ((t <= ((int)(TABLE_SIZE_X(length) / 10) - my_intlen(db->id)) / 2) ||
        (t > ((int)(TABLE_SIZE_X(length) / 10) + my_intlen(db->id)) / 2))
        printf(" ");
    if (t == ((int)(TABLE_SIZE_X(length) / 10) - my_intlen(db->id)) / 2)
        printf("%lld", db->id);
}

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

void print_separator1(float length)
{
    printf("\n");
    for (unsigned short i = 0; i < (TABLE_SIZE_X(length)); ++i)
        i %NUMBER_FIELD == 0 ? printf("+") : printf("-");
    printf("\n");
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

void display_id(float length, float width, db_t *db)
{

}
void display_id1(float length, float width, db_t *db)
{
    print_field_name("id", length);
    for (float i = 0; i < (TABLE_SIZE_Y(width) / 9); ++i)
    {
        for (float t = 0; t < (TABLE_SIZE_X(length) / 10); ++t)
        {
            if (i == 0)
                printf("-");
            else print_in_middle(db, t, length, width);
        }
        printf("|\n");
    }
    printf("\n");
}

void display_firstname1(float length, float width, db_t *db)
{
    printf("firstname\n");
    for (float i = 0; i < (TABLE_SIZE_Y(width) / 9); ++i)
    {
        for (float t = 0; t < (TABLE_SIZE_X(length) / 10); ++t)
        {
            if (i == 0)
                printf("-");
            else if (t == ((int)(TABLE_SIZE_X(length) / 10) - my_strlen(db->firstname)) / 2)
                printf("%s", db->firstname);
            else if ((t <= ((int)(TABLE_SIZE_X(length) / 10) - my_strlen(db->firstname)) / 2) ||
                (t >= ((int)(TABLE_SIZE_X(length) / 10) + my_strlen(db->firstname)) / 2))
                printf(" ");
        }
        printf("|\n");
    }
    printf("\n");
}

void display_id10(unsigned long long int id, float length)
{
    static unsigned short i = 2;
    static unsigned short tmp = 0;

    for (; i <= (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD) / 2) - (my_intlen(id) / 2)) - 1; ++i)
        printf(" ");
    printf("%lld", id);
    tmp = i;

        --i;
    for (; i > 0; --i)
        printf(" ");
        printf("|");
}


void display(char const *data, float length)
{
    static unsigned short i = 0;
    static unsigned short tmp = 0;

    if (strcmp(data, field_name[0]) == 0)
        i = 2;
    for (; i <= (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD) / 2) - (my_strlen(data) / 2)) - 1; ++i)
        printf(" ");
    printf("%s", data);
    tmp = i;

    if (strcmp(data, field_name[0]) == 0)
        --i;
    for (; i > 0; --i)
        printf(" ");
        printf("|");
}


void display_firstname(float length, float width, db_t *db)
{
    // printf("firstname\n");
    // for (float i = 0; i < (TABLE_SIZE_Y(width) / 9); ++i)
    // {
    //     for (float t = 0; t < (TABLE_SIZE_X(length) / 10); ++t)
    //     {
    //         if (i == 0)
    //             printf("-");
    //         else if (t == ((int)(TABLE_SIZE_X(length) / 10) - my_strlen(db->firstname)) / 2)
    //             printf("%s", db->firstname);
    //         else if ((t <= ((int)(TABLE_SIZE_X(length) / 10) - my_strlen(db->firstname)) / 2) ||
    //             (t >= ((int)(TABLE_SIZE_X(length) / 10) + my_strlen(db->firstname)) / 2))
    //             printf(" ");
    //     }
    //     printf("|\n");
    // }
    // printf("\n");
}

void display_lastname(float length, float width, db_t *db)
{
}

void display_pseudonyme(float length, float width, db_t *db)
{
}

void display_birthday(float length, float width, db_t *db)
{
}

void display_city(float length, float width, db_t *db)
{
}

void display_phone(float length, float width, db_t *db)
{
}

void display_email(float length, float width, db_t *db)
{
}

void display_password(float length, float width, db_t *db)
{
}

void display_registeredAt(float length, float width, db_t *db)
{
}

bool print_table(list_t **head, db_t **db)
{
    const float *size = get_screen_size();
    const float length = size[0];
    const float width = size[1];
    const char table_name[16] = "Register_table";

    for (unsigned int i = 0; i < ((TABLE_SIZE_X(length) / 2) - (my_strlen((char *)table_name)) / 2); ++i)
        printf(" ");
    printf("%s\n", table_name);
    for (unsigned int i = 0; i < TABLE_SIZE_X(length); ++i)
        printf("-");
    printf("\n\n\n");
    // for (unsigned short int i = 0; i < NUMBER_FIELD; ++i)
        // display_field[i](length, width, *db);

    print_field_name(field_name[0], length);
    printf("\n");
    for (unsigned short int i = 0; i < NUMBER_FIELD; ++i) {
        print_separator(field_name[i], length);
    }
    printf("\n");
    display_id10((*db)->id, length);
    display((*db)->firstname, length);
    display((*db)->lastname, length);
    display((*db)->pseudonyme, length);
    display((*db)->birthday, length);
    display((*db)->city, length);
    display((*db)->phone, length);
    display((*db)->email, length);
    display((*db)->password, length);
    display((*db)->registeredAt, length);
    printf("\n");

    return true;
}