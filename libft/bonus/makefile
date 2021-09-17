.PHONY:		all clean fclean re
NAME	=	libftbonus.a
CC		=	gcc -Wall -Wextra -Werror
HEADER	=	../include
SRCS	= 	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
		  	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		  	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS	=	${SRCS:.c=.o}


all:	${NAME}

${NAME}:
		@${CC} -c ${SRCS} -I ${HEADER}

clean:
		@rm -f ${OBJS}

fclean:	clean
		@rm -f ${NAME}

re:		fclean all
