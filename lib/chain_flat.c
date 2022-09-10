/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_flat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:59:02 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/10 00:16:01 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_chain	*chain_flat(t_chain *chain, t_flatf f)
{
	t_list	*curr;
	t_list	*new_list;

	if (chain->curr == 0)
		return (chain);
	curr = chain->curr;
	chain->prev = chain->curr;
	chain->curr = 0;
	while (curr)
	{
		new_list = f(curr->content);
		if (new_list == 0)
			return chain->freeall(chain, FT_CHAIN_FREE_ALL);
		ft_lstadd_back(&(chain->curr), new_list);
		curr = curr->next;
	}
	return (chain);
}
