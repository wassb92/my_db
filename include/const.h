/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** const
*/

#ifndef CONST_H
#define CONST_H

# define alloc_err fprintf(stderr, MALLOC_FAILED);

#include "my_db.h"

typedef struct db_s db_t;

static const char STR_EMPTY_VALUE[6] = "EMPTY";
static const char MALLOC_FAILED[27] = "Memory allocation failed !\0";
static unsigned short MAX_ARGS = 14;
static const char SUCCESS_ASSIGNEMENT[20] = "Success assignement";
static const char SPACE_DEL = ' ';

enum db_operation_e {
    _insert,
    _drop,
    _delete,
};

enum db_assign_e {
    _firstStep,
    _target,
    _tableName,
    _extra, // (= VALUES)
    _firstname,
    _lastname,
    _pseudonyme,
    _birthday,
    _city,
    _phone,
    _email,
    _password,
    _registeredAt
};

#endif /* !CONST_H */