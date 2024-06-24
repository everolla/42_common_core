NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

SRC_1 = 	main.c \
		work.c \
		utils.c \
		parse.c \
		utils_ab.c \
		moves.c \
		moves_2.c \
		moves_3.c \
		free.c \
		lst.c \
		lst_2.c \
		ft_isdigit.c \
		ft_split.c \
		check_args.c \
		rotate_and_push.c \
		sort.c \

OBJ_1 = ${SRC_1:.c=.o}

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1}
	${CC} ${FLAGS} ${OBJ_1} -o ${NAME} ${INCLUDE}

all: ${NAME}

clean:
	${RM} ${OBJ_1} ${NAME}

fclean: clean
	${RM} ${NAME}

re: clean all

.PHONY: all clean fclean re
