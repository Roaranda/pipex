.PHONY:	all clean fclean re

NAME	:= 	pipex
CC		:= 	gcc 
CFLAGS	:=	-Wall -Wextra -Werror
LIBFT	:=	./libft
SRCS 	:= 	./pipex.c
OBJS	:=	${SRCS:.c=.o}

all: 	libft.a ${NAME}

libft.a: 
		@make -C ${LIBFT}
		@mv ${LIBFT}/libft.a ./
		@echo 1 - libft compiled

${NAME}:
		@echo 2 - Compiling pipex objects
		@${CC} ${CFLAGS} -c ${SRCS}
		@${CC} ${CFLAGS} ${OBJS} libft.a -o ${NAME}
		@echo 3 - pipex compiled

clean:
			@rm -f ${OBJS}

fclean:		clean
			@rm -f ${NAME} libft.a

re:			fclean all
