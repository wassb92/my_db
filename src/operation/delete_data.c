/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** delete data
*/

#include "my_db.h"

bool delete_rows(list_t **head, db_t **db, char **getline)
{
    remove_at_position(head, 3);
    return true;
}