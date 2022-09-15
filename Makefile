# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 14:29:59 by yonshin           #+#    #+#              #
#    Updated: 2022/09/15 15:37:28 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARFLAGS = rc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
OBJECTS = \
	ft_printf.o \
	ft_printf_util.o \
	ft_printf_conv_c.o \
	ft_printf_conv_d.o \
	ft_printf_conv_i.o \
	ft_printf_conv_p.o \
	ft_printf_conv_s.o \
	ft_printf_conv_u.o \
	ft_printf_conv_x.o \
	ft_printf_conv_xx.o
BONUS_OBJECTS = \
	ft_printf_bonus.o \
	ft_printf_util_bonus.o \
	ft_printf_conv_c_bonus.o \
	ft_printf_conv_d_bonus.o \
	ft_printf_conv_i_bonus.o \
	ft_printf_conv_p_bonus.o \
	ft_printf_conv_s_bonus.o \
	ft_printf_conv_u_bonus.o \
	ft_printf_conv_x_bonus.o \
	ft_printf_conv_xx_bonus.o
LIB = ./lib/libft.a

ifdef WITH_BONUS
	OBJS = $(BONUS_OBJECTS)
else
	OBJS = $(OBJECTS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	cp $(LIB) ./$(NAME)
	ar $(ARFLAGS) $@ $^

%.o: $(LIB) %.c
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) -I$(dir $(LIB)) -c $*.c

$(LIB):
	make -C $(@D)

bonus:
	make WITH_BONUS=1

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean
	make -C $(dir $(LIB))
	make all

.PHONY: all bonus clean fclean re
