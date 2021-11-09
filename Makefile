##
## EPITECH PROJECT, 2021
## my_db
## File description:
## Makefile
##

OPERATION	=	src/operation/print_table.c	\
				src/operation/print_init_table.c	\
				src/operation/insert_data.c	\
				src/operation/delete_data.c	\
				src/operation/drop_data.c	\

SRC	=	src/main.c	\
		src/my_db.c	\
		src/assign_value.c	\
		src/utils.c	\
		$(OPERATION)	\

LIB =	lib/my_lib.c	\
		lib/list.c	\
		lib/my_getline.c

SRC_TEST	=	\

OBJ	=	$(SRC:.c=.o)
NAME	=	my_db
TEST_NAME	=	unitest
RM	=	rm -f
CFLAGS	=	-I./include/
ERROR	=	-std=gnu11 -Wall -Wextra
DEBUG	=	-g3
CC	=	gcc
TFLAGS	=	--coverage -lcriterion
LDFLAGS	=	-lm

all:	$(NAME)
$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(SRC) $(LIB) $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *.gcno
	$(RM) *.gcda

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

unitest :
	$(CC) -o $(TEST_NAME) $(SRC_TEST) $(TFLAGS) $(CFLAGS)

tests_run: fclean unitest
		./unitest
	gcovr --exclude tests/ --branches
	gcovr --exclude tests/

.PHONY:	all clean fclean tests_run unitest

re:	fclean all