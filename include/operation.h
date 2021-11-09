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
bool insert(list_t **head, db_t **db, char **getline);

/* DELETE ROWS */
bool delete_rows(list_t **head, db_t **db, char **getline);

/* DROP TABLE */
bool drop(list_t **head, db_t **db, char **getline);

/* PRINT TABLE DATAS */
bool print_table(list_t **head, db_t **db, char **getline);
void init_print_table(float length);


#endif /* !OPERATION_H */