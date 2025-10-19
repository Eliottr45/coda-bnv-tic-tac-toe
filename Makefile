# Makefile

NAME = test

SRCS = main.c \
	robot.c \
	tictactoe.c

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all