/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** insert data
*/

#include "my_db.h"

bool insert(list_t **head, db_t **db)
{
    add_back(head, *db);
    return true;
}