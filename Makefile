NAME = push_swap
LIBFT = libft/libft.a

SRC = main.c \
	  src/stack_operations.c \
	  src/stack_sort.c \
	  src/stack_validators.c \
	  src/utils/utils.c \
	  src/utils/stack_utils.c \
	  src/utils/sort_utils.c \
	  src/operations/push_ops.c \
      src/operations/swap_ops.c \
	  src/operations/rotate_ops.c \
	  src/operations/revrotate_ops.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	$(MAKE) clean -C libft
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft
	$(RM) $(NAME)

re: fclean all
