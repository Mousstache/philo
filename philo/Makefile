SRCS = $(addprefix srcs/, philo.c parsing.c philo_utils.c utils2.c)

NAME = philo

INC = -I include

FLAGS = -g3 -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}

${NAME} : ${OBJS}
			cc ${FLAGS} ${INC} $(OBJS) -o $(NAME)

all : ${NAME}

%.o:%.c
		cc ${FLAGS} ${INC}  -c $< -o $@

clean :
		rm -rf ${OBJS}

fclean : clean
		rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re NAME
