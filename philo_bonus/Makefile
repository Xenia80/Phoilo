NAME = philo_bonus

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = 	init.c \
		lifecycle.c \
		utils.c \
		philosophers.c

HEADER = philo_bonus.h

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
