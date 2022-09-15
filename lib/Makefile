# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/13 14:29:59 by yonshin           #+#    #+#              #
#    Updated: 2022/09/15 19:55:42 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OPTIONS = rc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
OBJECTS = \
	ft_if.o \
	ft_max.o \
	ft_min.o \
	ft_tobase.o \
	ft_strupper.o \
	ft_strlower.o \
	ft_strreverse.o \
	ft_strrepeat.o \
	ft_isalnum.o \
	ft_isalpha.o \
	ft_isascii.o \
	ft_isdigit.o \
	ft_isprint.o \
	ft_atoi.o \
	ft_bzero.o \
	ft_calloc.o \
	ft_itoa.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_memcpy.o \
	ft_memmove.o \
	ft_memset.o \
	ft_putchar_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	ft_putstr_fd.o \
	ft_split.o \
	ft_strchr.o \
	ft_strchri.o \
	ft_strdup.o \
	ft_strjoin.o \
	ft_strlcat.o \
	ft_strlcpy.o \
	ft_strlen.o \
	ft_strmapi.o \
	ft_striteri.o \
	ft_strncmp.o \
	ft_strnstr.o \
	ft_strrchr.o \
	ft_strtrim.o \
	ft_substr.o \
	ft_tolower.o \
	ft_toupper.o \
	ft_lstnew.o \
	ft_lstadd_front.o \
	ft_lstsize.o \
	ft_lstlast.o \
	ft_lstadd_back.o \
	ft_lstdelone.o \
	ft_lstclear.o \
	ft_lstreverse.o \
	ft_lstiter.o \
	ft_lstmap.o \
	get_next_line.o \
	get_next_line_utils.o \
	chain_init.o \
	chain_param.o \
	chain_apply.o \
	chain_call.o \
	chain_next.o \
	chain_iterate.o \
	chain_free.o \
	lstb_init.o \
	lstb_add.o \
	lstb_clear.o \
	strb_add_left.o \
	strb_add_right.o \
	strb_build.o \
	strb_clear.o \
	strb_finish.o \
	strb_init.o \
	strb_new_node.o

$(NAME): $(OBJECTS)
	ar $(OPTIONS) $@ $^

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all bonus clean fclean re
