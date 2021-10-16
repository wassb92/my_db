/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** insert data
*/

#include "my_db.h"

bool insert(list_t **head, db_t **db)
{
    add_at_position(head, (*db), list_len((*head)));
    return true;
}