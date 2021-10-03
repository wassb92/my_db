/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** my_db
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_db.h"
#include "my.h"

void do_action(db_t **db, char **getline)
{
    if (tablen(getline) > 4)
        assign_value(db, getline);
}

bool main_loop(list_t **head, db_t **db)
{
    char **getline = NULL;

    while (1) {
        getline = my_getline();
        if (!getline || !*getline || (strcmp(getline[0], "END") == 0) || (strcmp(getline[0], "QUIT") == 0)) {
            free_getline(getline);
            break;
        }
        do_action(db, getline);
        free_getline(getline);
    }
    return true;
}

bool INSERT_INTO(list_t **head, db_t **db)
{
    return true;
}

bool add_elements_to_database(list_t **head, db_t **db)
{
    return true;
}