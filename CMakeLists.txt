cmake_minimum_required(VERSION 3.19)
project(push_swap_ljarrahd C)

set(CMAKE_C_STANDARD 11)

add_executable(push_swap_ljarrahd sort_stack.c
        libft/ft_atoi.c
        libft/ft_putstr_fd.c
        libft/ft_putchar_fd.c
        libft/ft_error_exit.c
        libft/ft_isspace.c
        libft/ft_strlen.c
        libft/ft_split.c
        libft/ft_strsfree.c
        libft/ft_strjoin.c
        ft_small_stack.c
        ft_qsort.c
        commands.c
        stacks.c
        ft_sort_big_stack.c
        ft_sort_big_stack2.c
        ft_parser.c)