/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:15:29 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 21:31:36 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "ft_printf_private.h"
#include "advlst.h"

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
static t_list	*parse2substr(char *s)
{
	const static char	*cnv = "cdipsuxX%";
	t_substr			*ct;
	t_lstb				lstb;

	lstb_init(&lstb, 0);
	while (*s)
	{
		ct = (t_substr *)malloc(sizeof(t_substr));
		if (ct == 0 || lstb.add(&lstb, ct, free))
			return (lstb.clear(&lstb, free)->list);
		ct->str = s;
		ct->len = 1;
		while (s[0] != '%' && s[ct->len] && s[ct->len] != '%')
			ct->len++;
		while (s[0] == '%' && s[ct->len] && ft_strchr(cnv, s[ct->len]) == 0)
			ct->len++;
		if (s[0] == '%' && s[ct->len])
			ct->len++;
		s += ct->len;
	}
	return (lstb.list);
}

void check_leak(void)
{
	system("leaks a.out");
}

#include "libft.h"
int main(void)
{
	char	*str = "asdf%da%%fsdf%%%faasdf";
	t_list 	*lst = ft_lstnew(str);
	t_chain	ch;

	lst = chain_init(&ch, lst, CONTENT_NO_FREE)
		->call(&ch, CHAIN_FLAT, parse2substr, free)
		->call(&ch, CHAIN_FLAT, parse2substr)
		->next(&ch);
	while (lst)
	{
		t_substr *token = (t_substr *)lst->content;
		lst = lst->next;
	}
	ch.free(&ch, CHAIN_ALL);

	atexit(check_leak);
	return (0);
}
