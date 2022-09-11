/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_reduce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:01:20 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/12 00:38:50 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

t_chain	*chain_reduce(t_chain *chain, t_reducef1 f, ...)
{
	t_list	*curr;
	t_list	*new_node;
	va_list	args;

	if (chain->curr == 0)
		return (chain);
	va_start(args, f);
	curr = chain->curr;
	chain->prev = chain->curr;
	chain->curr = 0;
	while (curr)
	{
		new_node = ft_lstnew(chain_apply(f, &curr, args, chain));
		if (new_node == 0 || new_node->content == 0)
			return chain->freeall(chain, FT_CHAIN_FREE_ALL);
		ft_lstadd_back(&(chain->curr), new_node);
		if (curr)
			curr = curr->next;
	}
	va_end(args);
	return (chain);
}
