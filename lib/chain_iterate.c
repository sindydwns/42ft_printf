/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_iterate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:48:17 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 01:21:22 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "advlst.h"

t_chain	*chain_iterate(t_chain *chain, t_factory fct, t_mapf f)
{
	t_list	*old_lst;
	t_list	*new_node;
	t_list	*last;

	last = 0;
	old_lst = chain->prev;
	while (old_lst)
	{
		new_node = fct(chain, &old_lst, f);
		if (new_node == 0)
			return (chain->free(chain, CHAIN_ALL));
		if (last == 0)
			ft_lstadd_back(&(chain->curr), new_node);
		else
			ft_lstadd_back(&last, new_node);
		last = new_node;
		while (last->next)
			last = last->next;
		if (old_lst)
			old_lst = old_lst->next;
	}
	return (chain);
}
