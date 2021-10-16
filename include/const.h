/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** const
*/

#ifndef CONST_H_INCLUDED
#define CONST_H_INCLUDED

#define alloc_err fprintf(stderr, MALLOC_FAILED);
#define TABLE_SIZE_X(x) ((x) / 9.1)
#define TABLE_SIZE_Y(x) ((x) / 60)
#define NUMBER_FIELD tablen(field_name)

#include "my_db.h"

static const char STR_EMPTY_VALUE[6] = "EMPTY";
static const char table_name[16] = "Register_table";
static const char SUCCESS_ASSIGNEMENT[20] = "Success assignement";
static const char MALLOC_FAILED[27] = "Memory allocation failed !\0";
static const char COMMAND_NOT_FOUND[174] = "Command not found, please retry with these command :\n\
\tINSERT to insert element in table\n\
\tDELETE to delete a row from table\n\
\tDROP to drop the table (and so remove all datas)\n";
static const char SPACE_DEL = ' ';
static const char *action[] = {
    "INSERT",
    "DELETE",
    "DROP",
    "SELECT",
    ((void *)0)
};

static const char *field_name[] = {
    "id",
    "firstname",
    "lastname",
    "pseudonyme",
    "birthday",
    "city",
    "phone",
    "email",
    "password",
    "registeredAt",
    ((void *)0),
};

enum db_operation_e {
    _insert,
    _delete,
    _drop,
    _select
};

enum db_field_e {
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