NAME = push_swap

SRC = main.c \
	  sort_stack.c \
	  utils/utils.c \
	  utils/stack_utils.c \
      operations/swap_ops.c \
      operations/rotate_ops.c \
      operations/revrotate_ops.c \
      operations/push_ops.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
