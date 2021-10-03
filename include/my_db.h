/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** my_db
*/

#ifndef MY_DB_H
#define MY_DB_H

#include "list.h"
#include "const.h"

typedef struct db_s {
    unsigned int id;
    char firstname[32];
    char lastname[32];
    char pseudonyme[32];
    char birthday[12];
    char city[32];
    char phone[32];
    char email[128];
    char password[128];
    char registeredAt[16];
}db_t;

bool INSERT_INTO(list_t **head, db_t **db);
bool add_elements_to_database(list_t **head, db_t **db);


/* Init */
void assign_value(db_t **db, char **getline);
void print_value(db_t *db);


/* Loop */
bool main_loop(list_t **head, db_t **db);

/* Utils */
void free_getline(char **getline);



static bool (*operation[])(list_t **, db_t **) = {
    &INSERT_INTO,
    // &drop,
    // &delete,
};


#endif /* !MY_DB_H */
