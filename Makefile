# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fchanal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/16 13:57:06 by fchanal           #+#    #+#              #
#    Updated: 2017/06/17 17:00:13 by fchanal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#################################################
###                  Settings                 ###
#################################################

NAME = ft_ls
CC = clang
FLAGS = -Wall -Wextra -Werror
SRC_PATH = ./srcs/
INC_PATH = -I./includes/

#################################################
###                  Colors                   ###
#################################################

COL_BLACK  = \033[1;30m
COL_RED    = \033[1;31m
COL_GREEN  = \033[1;32m
COL_YELLOW = \033[1;33m
COL_BLUE   = \033[1;34m
COL_PURPLE = \033[1;35m
COL_WHITE  = \033[1;37m

#################################################
###                 Sources                   ###
#################################################

SRC =\
	 \
	ft_ls.c \
	ls_get_flags.c \
	ls_error_message.c \
	ls_cmpf.c \
	ls_display.c \
	ls_disp_elem.c \
	ls_l.c \
	ls_disp_color.c \
	ls_color_l.c \
	ls_utilities.c \
	ls_parse_dir.c \
	ls_parse_dir2.c \
	ls_handle_flags.c \
	 \
	ls_mini_libft/ft_itoa.c \
	ls_mini_libft/ft_bzero.c \
	ls_mini_libft/ft_strcmp.c \
	ls_mini_libft/ft_strdup.c \
	ls_mini_libft/ft_memdel.c \
	ls_mini_libft/ft_putendl.c \
	ls_mini_libft/ft_bt_apply_asc.c \
	ls_mini_libft/ft_bt_apply_desc.c \
	ls_mini_libft/ft_bt_insert_node.c \
	ls_mini_libft/ft_bt_new_node.c \
	ls_mini_libft/ft_bt_tree_del.c \
	ls_mini_libft/ft_get_abs_len.c \
	 \
	ft_printf/ft_vdprintf.c \
	ft_printf/ft_vprintf.c \
	ft_printf/ft_printf.c \
	ft_printf/ft_dprintf.c \
	ft_printf/pf_color.c \
	ft_printf/pf_buffering.c \
	ft_printf/pf_utilities.c \
	ft_printf/pf_unicode_handler.c \
	ft_printf/pf_get_attr.c \
	ft_printf/pf_numb_conv_tools.c \
	ft_printf/pf_casting.c \
	 \
	ft_printf/pf_specifier/pf_convert_m.c \
	ft_printf/pf_specifier/pf_convert_big_m.c \
	ft_printf/pf_specifier/pf_convert_b.c \
	ft_printf/pf_specifier/pf_convert_c.c \
	ft_printf/pf_specifier/pf_convert_big_c.c \
	ft_printf/pf_specifier/pf_convert_d.c \
	ft_printf/pf_specifier/pf_convert_o.c \
	ft_printf/pf_specifier/pf_convert_p.c \
	ft_printf/pf_specifier/pf_convert_s.c \
	ft_printf/pf_specifier/pf_convert_big_s.c \
	ft_printf/pf_specifier/pf_convert_u.c \
	ft_printf/pf_specifier/pf_convert_v.c \
	ft_printf/pf_specifier/pf_convert_x.c \
	ft_printf/pf_specifier/pf_convert_y.c \
	ft_printf/pf_specifier/pf_convert_big_y.c \
	ft_printf/pf_specifier/pf_convert_n.c \
	ft_printf/pf_specifier/pf_convert_w.c \
	ft_printf/pf_specifier/pf_convert_big_w.c \
	ft_printf/pf_specifier/float/pf_convert_f.c \
	ft_printf/pf_specifier/float/pf_float_engine.c \
	ft_printf/pf_specifier/float/pf_float_integer_part.c \
	 \
	ft_printf/pf_mini_libft/ft_dexp.c \
	ft_printf/pf_mini_libft/ft_get_dint_part.c \
	ft_printf/pf_mini_libft/ft_memcpy.c \
	ft_printf/pf_mini_libft/ft_memcmp.c \
	ft_printf/pf_mini_libft/ft_memset.c \
	ft_printf/pf_mini_libft/ft_strchr.c \
	ft_printf/pf_mini_libft/ft_strchr_zero.c \
	ft_printf/pf_mini_libft/ft_strlen.c \
	ft_printf/pf_mini_libft/ft_strnlen.c \
	ft_printf/pf_mini_libft/ft_get_nbr.c \
	ft_printf/pf_mini_libft/ft_isdigit.c \
	ft_printf/pf_mini_libft/ft_isprint.c
\

#################################################
###                   Format                  ###
#################################################

SRCS = $(addprefix $(SRC_PATH), $(SRC))
O = $(notdir $(SRC))
OB = $(basename $(O))
OBJ = $(addsuffix .o ,$(OB))

#################################################
###                   Rules                   ###
#################################################

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ): $(SRCS)
	$(CC) -c $(FLAGS) $(INC_PATH) $(SRCS)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(FLAGS) $(INC_PATH) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
