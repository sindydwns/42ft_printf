/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:15:29 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/21 00:15:35 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "ft_printf_private.h"

static t_list	*parsing(char *s)
{
	t_parsed_token	*content;
	t_lstb			lstb;

	lstb_init(&lstb, 0);
	while (*s)
	{
		content = (t_parsed_token *)ft_calloc(1, sizeof(t_parsed_token));
		if (content == 0 || lstb.add(&lstb, content, free) == FT_ERROR)
			return (lstb.clear(&lstb, free)->list);
		s = read_context(content, s);
	}
	return (lstb.list);
}

static void	*tosubstr(t_parsed_token *t, va_list *valst)
{
	if (t == 0)
		return (0);
	if (t->conversion == 0)
		return (strb_create_substr(t->str, t->width, 0));
	if (t->conversion == '%')
		return (ft_printf_conv_c(t, valst));
	if (t->conversion == 'c')
		return (ft_printf_conv_c(t, valst));
	if (t->conversion == 'd')
		return (ft_printf_conv_d(t, valst));
	if (t->conversion == 'i')
		return (ft_printf_conv_i(t, valst));
	if (t->conversion == 'p')
		return (ft_printf_conv_p(t, valst));
	if (t->conversion == 's')
		return (ft_printf_conv_s(t, valst));
	if (t->conversion == 'u')
		return (ft_printf_conv_u(t, valst));
	if (t->conversion == 'x')
		return (ft_printf_conv_x(t, valst));
	if (t->conversion == 'X')
		return (ft_printf_conv_xx(t, valst));
	return (strb_create_substr(0, 0, 0));
}

static void	*print(t_list **lst)
{
	int			len;
	int			*res;
	t_substr	*substr;
	int			written;

	len = 0;
	while (*lst)
	{
		substr = (*lst)->content;
		if (substr->str == 0)
		{
			len = -1;
			break ;
		}
		written = write(1, substr->str, substr->len);
		if (written != substr->len)
			return (0);
		len += written;
		*lst = (*lst)->next;
	}
	res = (int *)malloc(sizeof(int));
	if (res == 0)
		return (0);
	*res = len;
	return (res);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	valst;
	t_chain	ch;
	t_list	*lst;
	int		res;

	if (fmt == 0)
		return (-1);
	if (*fmt == 0)
		return (0);
	va_start(valst, fmt);
	lst = chain_init(&ch, ft_lstnew((void *)fmt), CONTENT_NO_FREE)
		->call(&ch, CHAIN_FLAT, parsing, free)
		->param1(&ch, &valst)
		->call(&ch, CHAIN_MAP, tosubstr, strb_delete_substr)
		->call(&ch, CHAIN_REDUCE, print, free)
		->next(&ch);
	va_end(valst);
	if (lst == 0)
		return (-1);
	res = *((int *)lst->content);
	ch.free(&ch, CHAIN_ALL);
	return (res);
}
