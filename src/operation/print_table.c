#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_db.h"
#include "my.h"

static void display_long_string(char const *data, float length)
{
    for (unsigned short i = 0; i < ((int)(TABLE_SIZE_X(length) / NUMBER_FIELD)) - my_strlen(DOTS); ++i)
        printf("%c", data[i]);
    printf(DOTS);
    printf(PIPE);
}

static void display_id(unsigned long long int id, float length)
{
    unsigned short i = 2;
    unsigned int len = my_intlen(id);

    for (; i < (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD)) / 2) - (len / 2); ++i)
        printf(SPACE);
    printf("%lld", id);

    if (len % 2 == 0)
        ++i;

    for (; i > 1; --i)
        printf(SPACE);

    printf(PIPE);
}

static void display_field(char const *data, float length)
{
    short i = 0;
    int len = my_strlen(data);
    static unsigned short index = 1;
    ++index;

    if (len > ((int)(TABLE_SIZE_X(length) / NUMBER_FIELD)))
        return display_long_string(data, length);

    for (; i < (((int)(TABLE_SIZE_X(length) / NUMBER_FIELD)) / 2) - (len / 2); ++i)
        printf(SPACE);
    printf("%s", data);

    if (len % 2 == 0)
        ++i;

    for (; i > 0; --i)
        printf(SPACE);

    if (index != NUMBER_FIELD)
        printf(PIPE);
    else
        index = 1;
}

bool print_table(list_t **head, db_t **db, char **getline)
{
    const float *size = get_screen_size();
    const float length = size[0];
    const float width = size[1];
    list_t *tmp = *head;

    init_print_table(length);
    for (; tmp; tmp = tmp->next) {
        display_id(tmp->data->id, length);
        display_field(tmp->data->firstname, length);
        display_field(tmp->data->lastname, length);
        display_field(tmp->data->pseudonyme, length);
        display_field(tmp->data->birthday, length);
        display_field(tmp->data->city, length);
        display_field(tmp->data->phone, length);
        display_field(tmp->data->email, length);
        display_field(tmp->data->password, length);
        display_field(tmp->data->registeredAt, length);
        printf("\n");
    }
    printf("\n");

    return true;
}