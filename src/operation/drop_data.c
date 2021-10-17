/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** drop_data
*/

#include "my_db.h"

bool drop(list_t **head, db_t **db)
{
    free_list(head);
    return true;
}