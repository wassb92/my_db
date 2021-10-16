/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** operation header
*/

#ifndef OPERATION_H_INCLUDED
#define OPERATION_H_INCLUDED

#include "my_db.h"

/* Operation */


/* INSERT DATA */
bool insert(list_t **head, db_t **db);

/* DELETE ROWS */
bool delete_rows(list_t **head, db_t **db);

/* DROP TABLE */
bool drop(list_t **head, db_t **db);

/* PRINT TABLE DATAS */
bool print_table(list_t **head, db_t **db);




#endif /* !OPERATION_H */