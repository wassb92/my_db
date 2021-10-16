#include <stdio.h>
#include <string.h>
#include "my_db.h"
#include "my.h"

static void print_field_name(char const *str, float length)
{
    static unsigned short t = 0;
    unsigned short i = 0;
    unsigned short tmp = 0;

    if (t == NUMBER_FIELD) {
        t = 0;
        return;
    }
    if (strcmp(str, field_name[0]) == 0)
        i = 2;
    for (; i <= (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD) / 2) - (my_strlen(str) / 2)) - 1; ++i)
        printf(SPACE);
    printf("%s", str);
    if (t > 0 && my_strlen(str) % 2 == 0)
        printf(SPACE);
    for (; i > 0; --i)
        printf(SPACE);
    if (t + 1 < NUMBER_FIELD)
        printf(PIPE);
    print_field_name(field_name[++t], length);
}

static void print_separator(char const *str, float length)
{
    unsigned short i = 0;
    unsigned short tmp = 0;

    if (strcmp(str, field_name[0]) == 0)
        i = 2;
    for (; i <= (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD) / 2) - (my_strlen(str) / 2)) - 1; ++i)
        printf(HYPHEN);
    for (unsigned short t = 0; t < my_strlen(str); ++t)
        printf(HYPHEN);
    tmp = i;
    for (; i > 0; --i)
        printf(HYPHEN);
    if (strcmp(str, field_name[0]) != 0 && my_strlen(str) % 2 == 0)
        printf(HYPHEN);
    if (strcmp(str, field_name[NUMBER_FIELD - 1]) != 0)
        printf(PLUS);
}

void init_print_table(float length)
{
    for (unsigned int i = 0; i < ((TABLE_SIZE_X(length) / 2) - (my_strlen(table_name)) / 2); ++i)
        printf(SPACE);
    printf("%s\n", table_name);
    for (unsigned int i = 0; i < TABLE_SIZE_X(length); ++i)
        printf(HYPHEN);
    printf("\n\n\n");
    print_field_name(field_name[0], length);
    printf("\n");
    for (unsigned short int i = 0; i < NUMBER_FIELD; ++i)
        print_separator(field_name[i], length);
    printf("\n");
}