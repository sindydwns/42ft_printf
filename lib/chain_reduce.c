/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_reduce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:01:20 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/10 00:16:26 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_chain	*chain_reduce(t_chain *chain, t_reducef f)
{
	t_list	*curr;
	void	*content;
	t_list	*new_nodes;

	if (chain->curr == 0)
		return (chain);
	curr = chain->curr;
	chain->prev = chain->curr;
	chain->curr = 0;
	while (curr)
	{
		content = f(&curr);
		if (content == 0)
			return chain->freeall(chain, FT_CHAIN_FREE_ALL);
		new_nodes = ft_lstnew(content);
		if (new_nodes == 0)
		{
			chain->freecurr(content);
			return chain->freeall(chain, FT_CHAIN_FREE_ALL);
		}
		ft_lstadd_back(&(chain->curr), new_nodes);
		if (curr)
			curr = curr->next;
	}
	return (chain);
}
