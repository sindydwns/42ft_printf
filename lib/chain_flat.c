/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_flat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:59:02 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/12 21:37:15 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static t_list	*factory(t_chain *ch, t_list **lst, t_mapf f, void *valst)
{
	t_list	*result;
	t_list	*next;

	result = chain_apply(f, (*lst)->content, valst, ch);
	if (result == 0)
		return (0);
	next = result;
	while (next)
	{
		if (next->content == 0)
		{
			ft_lstclear(&result, ch->freecurr);
			return (0);
		}
		next = next->next;
	}
	return (result);
}

t_chain	*chain_flat(t_chain *chain, t_flatf1 f, ...)
{
	va_list	args;

	va_start(args, f);
	chain_iterate(chain, factory, (t_mapf)f, args);
	va_end(args);
	return (chain);
}
