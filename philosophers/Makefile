NAME = philo
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror -pthread

SRC_1 = 	philo.c \
			ft_atoi.c \
			utils.c \
			work.c \

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
