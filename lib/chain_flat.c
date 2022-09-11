/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_flat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:59:02 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/12 02:54:08 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int	is_valid(t_list *list)
{
	if (list == FT_NULL)
		return (FT_FALSE);
	while (list)
	{
		if (list->content == FT_NULL)
			return (FT_FALSE);
		list = list->next;
	}
	return (FT_TRUE);
}

t_chain	*chain_flat(t_chain *chain, t_flatf1 f, ...)
{
	t_list	*curr;
	t_list	*new_list;
	va_list	args;

	if (chain->curr == 0)
		return (chain);
	va_start(args, f);
	curr = chain->curr;
	chain->prev = chain->curr;
	chain->curr = 0;
	while (curr)
	{
		new_list = chain_apply(f, curr->content, args, chain);
		if (is_valid(new_list) == FT_FALSE)
			return chain->freeall(chain, FT_CHAIN_FREE_ALL);
		ft_lstadd_front(&(chain->curr), new_list);
		curr = curr->next;
	}
	ft_lstreverse(&(chain->curr));
	va_end(args);
	return (chain);
}
