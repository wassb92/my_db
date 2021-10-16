/*
** EPITECH PROJECT, 2022
** Linked List
** File description:
** Include
*/

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdbool.h>
#include "my_db.h"

typedef struct list_s {
    struct db_s *data;
    struct list_s *next;
}list_t;

/* Lib */

unsigned int list_len(list_t *head);
void print_list(list_t *head);
bool add_front(list_t **head, void *data);
bool add_back(list_t **head, void *data);
bool add_at_position(list_t **head, db_t *db, unsigned int position);
bool remove_front(list_t **head);
bool remove_back(list_t **head);
bool remove_at_position(list_t **head, unsigned int position);
void free_list(list_t **head);
list_t *find_value(list_t *head, void *data, bool keep_current_value);

#endif /* !LIST_H_ */