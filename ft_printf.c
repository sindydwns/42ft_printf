/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:15:29 by yonshin           #+#    #+#             */
/*   Updated: 2022/08/26 19:17:49 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "ft_printf_private.h"

static int	create_node(t_list **node)
{
	t_printable	*content;

	if (node == FT_NULL)
		return (FT_ERROR);
	content = (t_printable *)ft_calloc(1, sizeof(t_printable));
	if (content == FT_NULL)
		return (FT_ERROR);
	*node = ft_lstnew(content);
	if (*node == FT_NULL)
	{
		free(content);
		return (FT_ERROR);
	}
	return (FT_SUCCESS);
}

static int	parse_sub(va_list args, const char *s, t_list **node)
{
	int		state;
	int		len;

	state = STAT_NORM;
	if (create_node(node) == FT_ERROR)
		return (FT_ERROR);
	if (s[0] == 0)
		return (FT_SUCCESS);
	len = -1;
	if (s[++len] == '%')
		state = STAT_FORM;
	while (s[++len])
	{
		if (state == STAT_NORM && s[len] == '%')
			break ;
		if (state == STAT_NORM)
			continue ;
		if (state == STAT_FORM && ft_strchr("-0.# +", s[len]))
			// TODO add flag
		if (state == STAT_FORM && ft_strchr("cspdiuxX%%", s[len]));
			// TODO exit
	}
	return (FT_SUCCESS);
}

static int	parse(va_list args, const char *fmt, t_list **head)
{
	t_list	*last;

	last = parse_sub(args, fmt);
	if (last == FT_NULL)
		return (FT_ERROR);
	fmt += last->len;
	*head = last;
	while (*fmt)
	{
		last->next = parse_sub(args, fmt);
		last = last->next;
		if (last == FT_NULL)
		{
			ft_lstclear(head);
			return (FT_ERROR);
		}
		fmt += last->len;
	}
	return (FT_SUCCESS);
}

static int	ft_print_list(t_list *list)
{
	int			total_size;
	t_printable	*content;
	int			size;

	if (list == FT_NULL)
		return (FT_ERROR);
	total_size = 0;
	while (list)
	{
		content = (t_printable *)list->content;
		size = content->print(content);
		if (size == FT_ERROR)
			return (FT_ERROR);
		total_size += size;
		list = list->next;
	}
	return (total_size);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	t_list	*list;
	int		size;

	if (fmt == FT_NULL)
		return (FT_ERROR);
	va_start(args, fmt);
	list = FT_NULL;
	if (parse(args, fmt, &list) == FT_SUCCESS)
		size = ft_print_list(list);
	else
		size = FT_ERROR;
	va_end(args);
	if (list != FT_NULL)
		ft_lstclear(&list, free);
	return (size);
}
