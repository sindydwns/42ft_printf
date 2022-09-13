# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 14:29:59 by yonshin           #+#    #+#              #
#    Updated: 2022/09/14 04:57:57 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARFLAGS = rc
TARGET = libftprintf.a
CFLAGS = -Wall -Wextra -Werror
OBJECTS = ft_printf.o \
	ft_printf_conversion_c \
	ft_printf_conversion_d \
	ft_printf_conversion_i \
	ft_printf_conversion_p \
	ft_printf_conversion_s \
	ft_printf_conversion_u \
	ft_printf_conversion_x \
	ft_printf_conversion_xx
BONUS_OBJECTS = ft_printf_bonus.o
LIB = ./lib/libft.a

ifdef WITH_BONUS
	OBJS = $(OBJECTS) $(BONUS_OBJECTS)
else
	OBJS = $(OBJECTS)
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	cp $(LIB) ./$(TARGET)
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
	rm -f $(TARGET)

re: fclean
	make all

.PHONY: all bonus clean fclean re
