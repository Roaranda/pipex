.PHONY:	all clean fclean re

NAME	:= 	pipex
CC		:= 	gcc 
CFLAGS	:=	-Wall -Wextra -Werror
LIBDIR	:=	./libft
SRCS 	:= 	./pipex.c
OBJS	:=	${SRCS:.c=.o}

all:	${NAME}

libft.a: 
		@make -C ${LIBDIR}
		@mv ${LIBDIR}/libft.a ./
		@echo 1 - libft compiled

%.o : %.c
		@${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS} libft.a
		@echo 2 - Compiling pipex objects
		@${CC} ${CFLAGS} ${OBJS} libft.a -o ${NAME}
		@echo 3 - pipex compiled

clean:
			@rm -f ${OBJS}

fclean:		clean
			@rm -f ${NAME} libft.a

re:			fclean all
