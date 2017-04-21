# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohrechyn <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/14 01:17:25 by ohrechyn          #+#    #+#              #
#    Updated: 2017/04/14 03:12:59 by ohrechyn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
GCC = gcc
FLAG = -Wall -Wextra -Werror
SRC = add_hard.c add_steps.c base.c clean_globals.c find_simple.c flags_all.c flags_h.c \
	  flags_j.c flags_z.c ft_charjoin.c ft_eightbit.c ft_printf.c get_width.c \
	  hard_valid.c index.c print_c.c print_d_i.c print_f.c print_jd.c print_jo.c print_ju.c \
	  print_jx.c print_ld.c print_lld.c print_llo.c print_llu.c print_llx.c print_lo.c \
	  print_lu.c print_lx.c print_o.c print_p.c print_s.c print_u.c print_x.c \
	  valid_digit.c valid_toch.c valid_width.c flags_l.c print_ls.c \
	  print_hd.c print_ho.c print_hu.c print_hx.c ft_itoa_base.c min_width.c\
	  print_hhd_i.c print_hho.c print_hhu.c print_hhx.c print_zd.c print_zu.c \
	  min1.c min2.c min3.c
OBJ = $(SRC:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	make -C libft/
	mv libft/libft.a ./$(NAME)
	$(GCC) -c $(FLAG) $(SRC) -I ./
	ar rv $(NAME) $(OBJ)
	ranlib $(NAME)
clean :
	make clean -C libft/
	rm -rf $(OBJ)
fclean : clean
	make fclean -C libft/
	rm -rf $(NAME)
re : fclean all
