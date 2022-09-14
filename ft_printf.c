/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:15:29 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 09:08:05 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "ft_printf_private.h"
#include "advlst.h"

static t_list	*indexing(char *s, const char *cnv)
{
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

static void	*parsing(t_substr *s)
{
	t_parsed_token	*res;

	res = (t_parsed_token *)ft_calloc(1, sizeof(t_parsed_token));
	if (res == 0)
		return (0);
	res->str = s->str++;
	if (res->str[0] != '%')
		res->width = s->len;
	if (res->str[1] == '%')
		res->width = 1;
	if (res->str[0] != '%' || res->str[1] == '%')
		return (res);
	res->conversion = res->str[s->len - 1];
	res->flags = skip_flag(&(s->str), "-+ #0");
	res->width = skip_number(&(s->str));
	if (s->str[0] == '.' && *(s->str)++)
		res->precision = skip_number(&(s->str));
	return (res);
}

static void	*stringify(t_parsed_token *t, va_list *valst)
{
	if (t->conversion == 0)
		return (ft_substr(t->str, 0, t->width));
	if (t->conversion == 'c')
		return (ft_printf_conversion_c(t, valst));
	if (t->conversion == 'd')
		return (ft_printf_conversion_d(t, valst));
	if (t->conversion == 'i')
		return (ft_printf_conversion_i(t, valst));
	if (t->conversion == 'p')
		return (ft_printf_conversion_p(t, valst));
	if (t->conversion == 's')
		return (ft_printf_conversion_s(t, valst));
	if (t->conversion == 'u')
		return (ft_printf_conversion_u(t, valst));
	if (t->conversion == 'x')
		return (ft_printf_conversion_x(t, valst));
	if (t->conversion == 'X')
		return (ft_printf_conversion_xx(t, valst));
	return (0);
}

static void	*print(t_list **lst)
{
	int		*res;
	char	*str;

	res = (int *)ft_calloc(1, sizeof(int));
	if (res == 0)
		return (0);
	while (*lst)
	{
		str = (*lst)->content;
		*res += write(1, str, ft_strlen(str));
		*lst = (*lst)->next;
	}
	return (res);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_chain	ch;
	t_list	*lst;
	int		res;

	va_start(args, fmt);
	lst = chain_init(&ch, ft_lstnew((void *)fmt), CONTENT_NO_FREE)
		->param1(&ch, "cdipsuxX%")
		->call(&ch, CHAIN_FLAT, indexing, free)
		->call(&ch, CHAIN_MAP, parsing, free)
		->param1(&ch, args)
		->call(&ch, CHAIN_MAP, stringify, free)
		->call(&ch, CHAIN_REDUCE, print, free)
		->next(&ch);
	va_end(args);
	if (lst == 0)
		return (-1);
	res = *((int *)lst->content);
	ch.free(&ch, CHAIN_ALL);
	return (res);
}
