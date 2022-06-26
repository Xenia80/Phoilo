NAME = philo

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC =	for_forks.c \
		init.c \
		main.c \
		philo_acts.c \
		utils.c \
		check_arg.c

HEADER = philo.h

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) Makefile
	$(CC) $(FLAGS) $(OBJ) -lpthread -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all