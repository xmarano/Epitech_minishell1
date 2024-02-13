##
## EPITECH PROJECT, 2024
## B-PSU-200-MAR-2-1-minishell1-leo.gregori
## File description:
## Makefile
##

SRCLIB	=	lib/my_atoi.c 		\
			lib/my_printf.c		\
			lib/my_put_nbr_recursive.c	\
			lib/my_put_nbr.c 	\
			lib/my_putchar.c	\
			lib/my_putstr.c		\
			lib/my_strcmp.c		\
			lib/my_strdup.c 	\
			lib/my_strlen.c 	\

SRCNAME	=	main.c				\

LIB 	=	libmy.a

OBJLIB	=	$(SRCLIB:.c=.o)

OBJNAME	=	$(SRCNAME:.c=.o)

NAME	=	minishell

$(NAME) : 	$(LIB) $(OBJNAME)
			gcc -o $(NAME) $(OBJNAME) -lmy -L./ -g3

$(LIB) 	: 	$(OBJLIB)
			ar rc libmy.a lib/*.o

all		:	$(LIB) $(NAME)

clean	:
			rm -f $(OBJLIB) $(OBJNAME) libmy.a

fclean	: 	clean
			rm -f $(NAME)

re		: 	fclean all