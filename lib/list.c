#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_db.h"

void dbcpy(list_t *dest, db_t *src)
{
    dest->data->id = src->id;

    strcpy(dest->data->firstname, src->firstname);
    strcpy(dest->data->lastname, src->lastname);
    strcpy(dest->data->pseudonyme, src->pseudonyme);
    strcpy(dest->data->birthday, src->birthday);
    strcpy(dest->data->city, src->city);
    strcpy(dest->data->phone, src->phone);
    strcpy(dest->data->email, src->email);
    strcpy(dest->data->password, src->password);
    strcpy(dest->data->registeredAt, src->registeredAt);
}

unsigned int list_len(list_t *head)
{
    unsigned int i = 0;

    for (; head; head = head->next, ++i);

    return i;
}

void print_list(list_t *head)
{
    while (head) {
        printf("[%s]\n", (char *)head->data);
        head = head->next;
    }
}

bool add_front(list_t **head, void *data)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *tmp = *head;

    if (!node || !head)
        return false;
    node->next = NULL;
    node->data = data;

    if (*head == NULL) {
        *head = node;
        return true;
    }
    *head = node;
    (*head)->next = tmp;
    return true;
}

bool add_back(list_t **head, void *data)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *tmp = *head;

    if (!node || !head)
        return false;
    node->next = NULL;
    node->data = data;

    if (!*head) {
        free(node);
        return add_front(head, data);
    }
    while (tmp->next)
        tmp = tmp->next;

    tmp->next = node;
    return true;
}

bool add_at_position(list_t **head, db_t *elem, unsigned int position)
{
    list_t *pre = *head;
    list_t *current = *head;
    list_t *cell = malloc(sizeof(list_t));

    if (!cell || position > list_len(*head))
        return false;

    cell->data = malloc(sizeof(db_t));
    dbcpy(cell, elem);

    cell->next = NULL;
    if (position == 0)
    {
        cell->next = *head;
        *head = cell;
        return true;
    }
    for (unsigned int i = 0; i < position; ++i)
    {
        pre = current;
        current = current->next;
    }
    pre->next = cell;
    cell->next = current;
    return true;
}

bool remove_front(list_t **head)
{
    list_t *tmp = *head;

    if (!tmp || !*head)
        return false;

    (*head) = (*head)->next;
    free(tmp);

    return true;
}

bool remove_back(list_t **head)
{
    list_t *tmp = *head;
    list_t *save = *head;

    if (!tmp || !*head)
        return false;
    for (; tmp->next; save = tmp, tmp = tmp->next);
    save->next = NULL;
    printf("%s\n", (char *)save->data);
    free(tmp);
    return true;
}

bool remove_at_position(list_t **head, unsigned int position)
{
    list_t *temp = *head;
    list_t *next = NULL;

    if (*head == NULL)
        return false;
    if (position == 0) {
        *head = temp->next;
        free(temp->data);
        free(temp);
        return true;
    }
    for (unsigned int i = 0; temp != NULL && i < position - 1; ++i)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return false;
    next = temp->next->next;
    free(temp->next->data);
    free(temp->next);
    temp->next = next;

    return true;
}

void free_list(list_t **head)
{
    list_t *save = (*head);
    static bool is_freed = false;

    if (is_freed || !*head || !head || !save || list_len(*head) == 0)
        return;
    while (save) {
        save = (*head)->next;
        free((*head)->data);
        free(*head);
        *head = save;
    }
    free(save);
    is_freed = true;
}

list_t *find_value(list_t *head, void *data, bool keep_current_value)
{
    for (;head; head = head->next)
        if (head->data == data)
            return keep_current_value ? head : head->next;
    return NULL;
}