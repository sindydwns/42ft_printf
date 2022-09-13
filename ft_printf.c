/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:15:29 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 14:56:51 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "ft_printf_private.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	args;

	va_start(args, fmt);
	va_end(args);
	return (0);
}

void test(void *test)
{
	test++;
}

#include <stdio.h>
static t_list	*parse2substr(char *str)
{
	t_substr			*ct;
	t_lstb				lstb;
	const static char	*conv = "cdipsuxX%";

	lstb_init(&lstb, 0);
	while (*str)
	{
		printf("--------%s\n", str);
		ct = (t_substr *)malloc(sizeof(t_substr));
		if (ct == 0 || lstb.add(&lstb, ct, free))
			return (lstb.clear(&lstb, free)->head);
		ct->str = str;
		ct->len = 1;
		while (str[0] == '%' && str[ct->len] &&
			ft_strchr(conv, str[ct->len]) == 0)
			ct->len++;
		while (str[0] != '%' && str[ct->len] &&
			str[ct->len] != '%')
			ct->len++;
		if (str[0] == '%' && str[ct->len])
			ct->len++;
		str = str + ct->len;
	}
	return (lstb.head);
}

void check_leak(void)
{
	system("leaks a.out");
}

#include "libft.h"
int main(void)
{
	char	*str = ft_strdup("asdf%da%%fsdf%%%faasdf");
	t_list 	*lst = ft_lstnew(str);
	t_chain	ch;
	lst = chain_init(&ch, lst)
		->flat(&ch, (t_flatf)parse2substr, &ch)
		->next(&ch);
	while (lst)
	{
		t_substr *token = (t_substr *)lst->content;
		printf("--%p %d\n", token->str, token->len);
		lst = lst->next;
	}
	ch.free(&ch, FT_CHAIN_ALL);

	atexit(check_leak);
	return (0);
}
