#include <stdlib.h>
#include <stdio.h>
#include "list.h"

unsigned int list_len(list_t *head)
{
    unsigned int i = 0;

    for (; head; head = head->next, ++i);

    return i;
}

void print_list(list_t *head)
{
    while (head) {
            printf("[%s]%c", (char *)head->data, (head->next == NULL ? '\n' : ' '));
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

    if (!*head)
        return add_front(head, data);

    while (tmp->next)
        tmp = tmp->next;

    tmp->next = node;
    return true;
}

bool add_at_position(list_t **head, void *data, unsigned int position)
{
    list_t *node = malloc(sizeof(list_t));
    list_t *current = *head;
    list_t *previous = *head;

    if (!node || !head)
        return false;
    node->next = NULL;
    node->data = data;

    if (position == 0) {
        (*head) = node;
        node->next = current;
        return true;
    }

    for (unsigned int i = 0; i < position - 1; ++i) {
        previous = current;
        current = previous->next;
    }
    previous->next = node;
    node->next = current;
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
    list_t *tmp = *head;
    list_t *save = *head;

    if (!tmp || !save || !*head || position > list_len(*head))
        return false;

    for (unsigned int i = 0; i < position - 1; ++i, tmp = tmp->next)
        save = tmp;
    save->next = tmp->next;
    free(tmp);

    return true;
}

void free_list(list_t **head)
{
    list_t *save = (*head);
    static bool is_freed = false;

    if (is_freed)
        return;

    while (save) {
        save = (*head)->next;
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