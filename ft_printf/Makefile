CC = gcc

CFLAG = -Wall -Wextra -Werror -g

NAME = libftprintf.a

INC_PATH =	./inc/

OBJ_PATH = ./obj/

SRC_PATH = ./src/

SRC_NAME = ft_strncpy.c tools.c ft_round.c ft_strcpyf.c ft_print_aa.c ft_print_gg.c ft_print_ff.c ft_print_float.c ft_float_f.c ft_float.c ft_pars_float.c ft_print_u.c ft_convert.c ft_strn.c ft_reset.c ft_pars_str.c ft_print_prcent.c ft_strchr.c ft_putchar_fd.c ft_atoi.c ft_bzero.c ft_strlen.c ft_printf.c ft_print_long.c ft_convert_h.c ft_convert_z.c ft_convert_j.c ft_convert_l.c ft_flags_espace.c\
		ft_flags_plus.c ft_flags_hastag.c ft_flags_zero.c ft_flags_less.c ft_flags_presci.c ft_print_int.c  \
		ft_print_c.c ft_print_str.c ft_xoxo.c ft_pointer.c ft_pars_hexa.c ft_pars_int.c ft_print_str.c
	
OBJ_NAME = $(SRC_NAME:.c=.o)

SRC =		$(addprefix $(SRC_PATH),$(SRC_NAME))

OBJ =		$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@ar rcs $@ $^
			@echo "compile done !"


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
			@mkdir -p $(OBJ_PATH)
			@$(CC) $(CFLAG) -I$(INC_PATH) -o $@ -c $<

clean:
			@rm -rf $(OBJ)
			@echo "clean done !"

fclean:		clean
			@rm -rf $(NAME)
			@echo "fclean done !"

re: 		fclean all
