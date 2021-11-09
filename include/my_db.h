/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** my_db
*/

#ifndef MY_DB_H_INCLUDED
#define MY_DB_H_INCLUDED

typedef struct db_s
{
    unsigned long long int id;
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

#include "list.h"
#include "const.h"
#include "operation.h"

/* Init */
void assign_value(db_t **db, char **getline);
void print_brut_value(db_t *db);

/* Loop */
bool main_loop(list_t **head, db_t **db);

/* Utils */
void free_getline(char **getline);
short find_index(char const *str, char const **fct_name);
float *get_screen_size(void);


/* Display */
// void display_id(float length, float width, db_t *db);
// void display_firstname(float length, float width, db_t *db);
// void display_lastname(float length, float width, db_t *db);
// void display_pseudonyme(float length, float width, db_t *db);
// void display_birthday(float length, float width, db_t *db);
// void display_city(float length, float width, db_t *db);
// void display_phone(float length, float width, db_t *db);
// void display_email(float length, float width, db_t *db);
// void display_password(float length, float width, db_t *db);
// void display_registeredAt(float length, float width, db_t *db);

static bool (*operation[])(list_t **, db_t **, char **) = {
    &insert,
    &delete_rows,
    &drop,
    &print_table
};


// static void (*display_field[])(float, float, db_t *) = {
//     &display_id,
//     &display_firstname,
//     &display_lastname,
//     &display_pseudonyme,
//     &display_birthday,
//     &display_city,
//     &display_phone,
//     &display_email,
//     &display_password,
//     &display_registeredAt,
// };


#endif /* !MY_DB_H */
