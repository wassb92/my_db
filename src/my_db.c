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
    unsigned short index = find_index(getline[0], action);
    if (1 == 2)
        print_table(*db);
    // if (tablen(getline) > 4)
        // assign_value(db, getline);
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

bool insert_into(list_t **head, db_t **db)
{
    return true;
}


bool drop(list_t **head, db_t **db)
{
    return true;
}


bool delete_table(list_t **head, db_t **db)
{
    return true;
}


bool add_elements_to_database(list_t **head, db_t **db)
{
    return true;
}