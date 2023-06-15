##
## FASTA_TOOLS PROJECT, 2022
## makefile
## File description:
## makefile
##

CC ?= gcc

SRC	=	src/main.c 										\
		src/fasta_loop.c								\
		src/lib/is_delim_separator.c					\
		src/lib/my_word_array_delim.c					\

UTSRC = src/fasta_loop.c								\
		src/lib/is_delim_separator.c					\
		src/lib/my_word_array_delim.c					\

UTDIR = src/test/unit_test.c

OBJ	=	$(SRC:.c=.o)

RM = rm -f

CPPFLAGS += -iquote./includes

CFLAGS += -Wall -Wextra -g3

NAME	=	FASTAtools

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPLAGS) $(CFLAGS)

tests_run:
	$(CC) $(UTSRC) $(UTDIR) $(CPPFLAGS) --coverage -lcriterion -o unit_tests
	./unit_tests

tests_clean:
		$(RM) unit_tests*

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	 fclean all

.PHONY = all clean fclean re
