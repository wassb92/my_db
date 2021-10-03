/*
** EPITECH PROJECT, 2022
** Linked List
** File description:
** Include
*/

#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>

typedef struct list_s {
    void *data;
    struct list_s *next;
}list_t;

/* Lib */

unsigned int list_len(list_t *head);
void print_list(list_t *head);
bool add_front(list_t **head, void *data);
bool add_back(list_t **head, void *data);
bool add_at_position(list_t **head, void *data, unsigned int position);
bool remove_front(list_t **head);
bool remove_back(list_t **head);
bool remove_at_position(list_t **head, unsigned int position);
void free_list(list_t **head);
list_t *find_value(list_t *head, void *data, bool keep_current_value);

#endif /* !LIST_H_ */