# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbensado <kbensado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/25 17:59:07 by kbensado          #+#    #+#              #
#    Updated: 2017/09/28 16:55:32 by kbensado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HOSTTYPE ?= $(shell uname -m)_$(shell uname -s)

NAME = libft_malloc_$(HOSTTYPE).so

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRCS_PATH = srcs/

SRCS_NAME = malloc.c \
			free.c \
			realloc.c \
			calloc.c \
			iterate_memory.c \
			show_alloc_memory.c \
			handle_size.c \
			tools.c \
			tools2.c \
			memory_list.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

LIBRARY = ft_printf/libftprintf.a

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

all: odir $(NAME)

$(NAME): $(OBJS)
	@echo " - Making $(NAME)"
	@$(CC) -shared $(CFLAGS) -o $(NAME) $^ $(LIBRARY)
	@ln -sf $(NAME) libft_malloc.so

odir:
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@echo " - Compiling $<"
	@$(CC) $(CFLAGS) -fPIC -o $@ -c $<

clean:
	@echo " - Cleaning objs"
	@make clean -C ft_printf/
	@rm -f $(OBJS)

fclean: clean
	@echo " - Cleaning executable"
	@make clean
	@make fclean -C ft_printf/
	@rm -f $(NAME)
	@rm -f libft_malloc.so

re: fclean all

.PHONY: clean fclean re odir
