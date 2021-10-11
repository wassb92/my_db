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

typedef struct db_s
{
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
} db_t;

/* Init */
void assign_value(db_t **db, char **getline);
void print_brut_value(db_t *db);

/* Loop */
bool main_loop(list_t **head, db_t **db);

/* Utils */
void free_getline(char **getline);
unsigned short find_index(char const *str, char const **fct_name);

/* Operation */
void print_table(db_t *db);
bool insert_into(list_t **head, db_t **db);
bool drop(list_t **head, db_t **db);
bool delete_table(list_t **head, db_t **db);


/* Display */

void display_id(float length, float width, db_t *db);
void display_firstname(float length, float width, db_t *db);
void display_lastname(float length, float width, db_t *db);
void display_pseudonyme(float length, float width, db_t *db);
void display_birthday(float length, float width, db_t *db);
void display_city(float length, float width, db_t *db);
void display_phone(float length, float width, db_t *db);
void display_email(float length, float width, db_t *db);
void display_password(float length, float width, db_t *db);
void display_registeredAt(float length, float width, db_t *db);

static bool (*operation[])(list_t **, db_t **) = {
    &insert_into,
    &drop,
    &delete_table,
};


static void (*display_field[])(float, float, db_t *) = {
    &display_id,
    &display_firstname,
    &display_lastname,
    &display_pseudonyme,
    &display_birthday,
    &display_city,
    &display_phone,
    &display_email,
    &display_password,
    &display_registeredAt,
};


#endif /* !MY_DB_H */
