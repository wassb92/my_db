/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_db.h"

static void assign_default_value(db_t **db)
{
    *db = malloc(sizeof(db_t));
    if (!*db) {
        alloc_err;
        return;
    }
    (*db)->id = 0;
    strcpy((*db)->firstname, STR_EMPTY_VALUE);
    strcpy((*db)->lastname, STR_EMPTY_VALUE);
    strcpy((*db)->pseudonyme, STR_EMPTY_VALUE);
    strcpy((*db)->birthday, STR_EMPTY_VALUE);
    strcpy((*db)->city, STR_EMPTY_VALUE);
    strcpy((*db)->phone, STR_EMPTY_VALUE);
    strcpy((*db)->email, STR_EMPTY_VALUE);
    strcpy((*db)->password, STR_EMPTY_VALUE);
    strcpy((*db)->registeredAt, STR_EMPTY_VALUE);

    // print_brut_value(*db);
}

static bool error_handling(int ac, char **av)
{
    // if (ac <= 1 || ac > MAX_ARGS)
    // return true;
    return false;
}

int main(int ac, char **av)
{
    list_t *head = NULL;
    db_t *db = NULL;

    if (error_handling(ac, av))
        return (EXIT_FAILURE);
    assign_default_value(&db);
    main_loop(&head, &db);

    return EXIT_SUCCESS;
}