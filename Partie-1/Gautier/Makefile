##
## ESGI PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC	=	gcc

RM	= 	rm -f

LDFLAGS	=	-Wall -Wextra -Werror

CFLAGS	+=	-I./include/

NAME	=	XML

SRC	=	src/main.c			\
		src/getAndCheckFiles.c		\
		src/getAndCheckElements.c	\

OBJS	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) -l c_graph_prog $(CFLAGS) $(LDFLAGS)
		$(RM) *.o

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
