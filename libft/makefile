.PHONY:	all clean fclean re ftoa bonus

NAME		=	libft.a
CC			=	gcc -Wall -Wextra -Werror
HEADER		=	./include
DIR_BONUS	=	./bonus
#DIR_FTOA	= 	./ftoa
SRCS		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c\
				ft_memcmp.c ft_strlen.c ft_nbrlen.c ft_isalpha.c ft_isdigit.c ft_isalnum.c\
				ft_isascii.c ft_isprint.c ft_isflag.c ft_iseven.c ft_isinhere.c ft_toupper.c ft_tolower.c\
				ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c\
				ft_strcmp.c ft_pow.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
				ft_strjoin_all.c ft_strtrim.c ft_split.c ft_itoa.c ft_itoa_ll.c ft_itoa_base_hex.c\
				ft_strrev.c ft_strmapi.c\
				ft_free.c	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
				ft_getenv.c
OBJS		=	${SRCS:.c=.o}

#SRCS_FTOA	=	ft_ftoa.c ft_etoa.c ft_gtoa.c dtobin.c ftoa_mantissa.c ftoa_decimal.c ftoa_round.c\
				ft_strsum.c ft_strmult.c ft_strpow.c
#OBJS_FTOA	=	${SRCS_FTOA:.c=.o}

SRCS_BONUS	=	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
		  		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c\
		  		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}


#all:		${NAME} ftoa
all:		${NAME}

bonus:		all
			@make -C ${DIR_BONUS}
			@cd ${DIR_BONUS} && for object in ${OBJS_BONUS}; do mv $$object ../; done
			@ar rs ${NAME} ${OBJS_BONUS}

#ftoa:
#			@make -C ${DIR_FTOA}
#			@cd ${DIR_FTOA} && for object in ${OBJS_FTOA}; do mv $$object ../; done
#			@ar rs ${NAME} ${OBJS_FTOA}

${NAME}:
			@${CC} -c ${SRCS} -I ${HEADER}
			@ar crs ${NAME} ${OBJS}

main:
			@${CC} main.c ${NAME} && ./a.out
			@rm a.out

#clean:
#			@rm -f ${OBJS} ${OBJS_FTOA} ${OBJS_BONUS}
clean:
			@rm -f ${OBJS} ${OBJS_BONUS}

fclean:		clean
			@rm -f ${NAME}

re:			fclean all
