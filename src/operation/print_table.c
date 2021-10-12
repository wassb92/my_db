/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** print data's table
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_db.h"
#include "my.h"

void display_id1(float length, float width, db_t *db)
{
    printf("id\n");
    for (float i = 0; i < (TABLE_SIZE_Y(width) / 9); ++i)
    {
        for (float t = 0; t < (TABLE_SIZE_X(length) / 10); ++t)
        {
            if (i == 0)
                printf("-");
            else if (t == ((int)(TABLE_SIZE_X(length) / 10) - my_intlen(db->id)) / 2)
                printf("%d", db->id);
            else if ((t <= ((int)(TABLE_SIZE_X(length) / 10) - my_intlen(db->id)) / 2) ||
                (t >= ((int)(TABLE_SIZE_X(length) / 10) + my_intlen(db->id)) / 2))
                printf(" ");
        }
        printf("|\n");
    }
    printf("\n");
}

void print_in_middle(db_t *db, float t, float length, float width)
{
    if ((t <= ((int)(TABLE_SIZE_X(length) / 10) - my_intlen(db->id)) / 2) ||
        (t > ((int)(TABLE_SIZE_X(length) / 10) + my_intlen(db->id)) / 2))
        printf(" ");
    if (t == ((int)(TABLE_SIZE_X(length) / 10) - my_intlen(db->id)) / 2)
        printf("%d", db->id);
}

void display_id(float length, float width, db_t *db)
{
    printf("id\n");
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


void display_firstname(float length, float width, db_t *db)
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
    for (unsigned short int i = 0; i < NUMBER_FIELD; ++i)
        display_field[i](length, width, *db);
    printf("\n");

    return true;
}