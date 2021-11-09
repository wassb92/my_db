/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** insert data
*/

#include "my_db.h"

bool insert(list_t **head, db_t **db, char **getline)
{
    assign_value(db, getline);
    add_at_position(head, (*db), list_len((*head)));
    return true;
}