/*
** EPITECH PROJECT, 2021
** my_db
** File description:
** assign target value
*/

#include <string.h>
#include <stdio.h>
#include "my_db.h"
#include "my.h"

void print_value(db_t *db)
{
    printf("id = %u\n", db->id);
    printf("firstname = %s\n", db->firstname);
    printf("lastname = %s\n", db->lastname);
    printf("pseudonyme = %s\n", db->pseudonyme);
    printf("birthday = %s\n", db->birthday);
    printf("city = %s\n", db->city);
    printf("phone = %s\n", db->phone);
    printf("email = %s\n", db->email);
    printf("password = %s\n", db->password);
    printf("registeredAt = %s\n", db->registeredAt);
}

void assign_value(db_t **db, char **getline)
{
    ++(*db)->id;

    strcpy((*db)->firstname, getline[_firstname]);
    strcpy((*db)->lastname, getline[_lastname]);
    strcpy((*db)->pseudonyme, getline[_pseudonyme]);
    strcpy((*db)->birthday, getline[_birthday]);
    strcpy((*db)->city, getline[_city]);
    strcpy((*db)->phone, getline[_phone]);
    strcpy((*db)->email, getline[_email]);
    strcpy((*db)->password, getline[_password]);
    strcpy((*db)->registeredAt, getline[_registeredAt]);

    printf("After assigned\n*------------------*\n");
    print_value(*db);
}
/*
INSERT INTO register_table VALUES 'Arthur' 'Dupont' 'Art123' '05/03/2000' 'Paris' '06.05.04.03.02' 'ArthurDupont@gmail.com' 'arthur123' '03/10/2021'
*/