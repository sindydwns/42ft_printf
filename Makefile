# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 14:29:59 by yonshin           #+#    #+#              #
#    Updated: 2022/09/14 08:57:16 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARFLAGS = rc
NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
OBJECTS = ft_printf.o \
	ft_printf_conversion_c.o \
	ft_printf_conversion_d.o \
	ft_printf_conversion_i.o \
	ft_printf_conversion_p.o \
	ft_printf_conversion_s.o \
	ft_printf_conversion_u.o \
	ft_printf_conversion_x.o \
	ft_printf_conversion_xx.o
BONUS_OBJECTS = ft_printf_bonus.o
LIB = ./lib/libft.a

ifdef WITH_BONUS
	OBJS = $(OBJECTS) $(BONUS_OBJECTS)
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
	make -C $(dir $@)

bonus:
	make WITH_BONUS = 1

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
