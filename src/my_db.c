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

static void do_action(list_t **head, db_t **db, char **getline)
{
    short index = find_index(getline[0], action);
    if (index == -1) {
        printf(COMMAND_NOT_FOUND);
        return;
    }
    operation[index](head, db, getline);
}

static void exit_program(list_t ***head, db_t ***db, char ***getline)
{
    free_getline(*getline);
    free_list(*head);
    free(**db);
}

bool main_loop(list_t **head, db_t **db)
{
    char **getline = NULL;

    while (true) {
        getline = my_getline();
        if (!getline || !*getline || (strcasecmp(getline[0], "END") == 0) || (strcasecmp(getline[0], "QUIT") == 0)) {
            exit_program(&head, &db, &getline);
            break;
        }
        do_action(head, db, getline);
        free_getline(getline);
    }
    return true;
}