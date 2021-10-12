/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** operation header
*/

#ifndef OPERATION_H
#define OPERATION_H

#include "my_db.h"
typedef struct db_s db_t;


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