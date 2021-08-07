CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR      = ar rcs

NAME = push_swap
LIB_PATH = ./libft

SRCS = commands.c ft_parser.c ft_qsort.c ft_small_stack.c ft_sort_big_stack.c ft_sort_big_stack2.c stacks.c sort_stack.c \
		libft/ft_putstr_fd.c \
		libft/ft_putchar_fd.c \
		libft/ft_split.c \
		libft/ft_strsfree.c \
		libft/ft_error_exit.c \
		libft/ft_isspace.c \
		libft/ft_strjoin.c \
		libft/ft_strlen.c \
		libft/ft_atoi.c

OBJECTS = $(SRCS:.c=.o)
HEADER = push_swap.h

all:  $(NAME)

%.o:	%.c $(HEADER)
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(HEADER)
		$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME)

makelibft:
		@$(MAKE) -C $(LIB_PATH)

clean:
	rm -f *.o
	make clean -C $(LIB_PATH)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
