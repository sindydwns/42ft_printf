/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:04:43 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/12 00:38:44 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

t_chain	*chain_map(t_chain *chain, t_mapf f, ...)
{
	t_list	*curr;
	t_list	*new_node;
	va_list args;

	if (chain->curr == 0)
		return (chain);
	va_start(args, f);
	curr = chain->curr;
	chain->prev = chain->curr;
	chain->curr = 0;
	while (curr)
	{
		new_node = ft_lstnew(chain_apply(f, curr->content, args, chain));
		if (new_node == 0 || new_node->content == 0)
			return chain->freeall(chain, FT_CHAIN_FREE_ALL);
		ft_lstadd_back(&(chain->curr), new_node);
		curr = curr->next;
	}
	va_end(args);
	return (chain);
}
