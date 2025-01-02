NAME = push_swap

CC = gcc

MY_SOURCES = a_operations.c \
	     best_index.c \
	     b_operations.c \
	     ft_check.c \
	     ft_check_inputs.c \
	     ft_repush_end.c \
	     ft_utils.c \
		 ft_utils_2.c \
	     main.c \
	     operations.c \
	     push_swap.c \
	     short_sort.c \
		 algo.c \

MY_OBJECTS = $(MY_SOURCES:.c=.o)

INCLUDE = Libft_pushswap/*.c
CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	 $(CC) $(CFLAGS) $(INCLUDE) $(MY_OBJECTS) -o $(NAME)

clean:
	rm -f $(MY_OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean

