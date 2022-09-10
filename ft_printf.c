/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 13:15:29 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/10 14:05:38 by yonshin          ###   ########.fr       */
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

t_list	*str2tokenlst(char *str)
{

}

char	*str_add_a(char *str)
{
	return ft_strjoin(str, "a");
}
char	*str_add_nl(char *str)
{
	return ft_strjoin(str, "\n");
}

#include <stdio.h>
#include "libft.h"
int main(void)
{
	// for test

	t_list *lst = 0;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("a")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("b")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("c")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("d")));

	t_chain	ch;
	lst = chain_init(&ch, lst)
		->map(&ch, (t_mapf)str_add_a)->freeall(&ch, FT_CHAIN_FREE_PREV)
		->map(&ch, (t_mapf)str_add_a)->freeall(&ch, FT_CHAIN_FREE_PREV)
		->map(&ch, (t_mapf)str_add_a)->freeall(&ch, FT_CHAIN_FREE_PREV)
		->map(&ch, (t_mapf)str_add_nl)->freeall(&ch, FT_CHAIN_FREE_PREV)
		->curr;

	if (lst == 0)
		return -1;
	while (lst)
	{
		ft_putstr_fd(lst->content, 1);
		lst = lst->next;
	}
	while(1){}
}
