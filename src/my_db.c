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

void do_action(list_t **head, db_t **db, char **getline)
{
    short index = find_index(getline[0], action);
    if (1 == 2)
        print_table(head, db);
    if (index == -1) {
        printf(COMMAND_NOT_FOUND);
        return;
    }
    if (index == 0)
        assign_value(db, getline);
    operation[index](head, db);
}

bool main_loop(list_t **head, db_t **db)
{
    char **getline = NULL;

    while (1) {
        getline = my_getline();
        if (!getline || !*getline || (strcmp(getline[0], "END") == 0) || (strcmp(getline[0], "QUIT") == 0)) {
            free_getline(getline);
            free_list(head);
            break;
        }
        do_action(head, db, getline);
        free_getline(getline);
    }
    return true;
}

bool insert_into(list_t **head, db_t **db)
{
    printf("insert_into\n");
    return true;
}


bool drop(list_t **head, db_t **db)
{
    printf("drop\n");
    return true;
}


bool delete_table(list_t **head, db_t **db)
{
    printf("delete_table\n");
    return true;
}