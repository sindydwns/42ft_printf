/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_iterate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:48:17 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/12 21:41:53 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

t_chain	*chain_iterate(t_chain *chain, t_factory fct, t_mapf f, void *valst)
{
	t_list	*old_lst;
	t_list	*new_node;

	if (chain->curr == 0)
		return (chain);
	old_lst = chain->next(chain);
	while (old_lst)
	{
		new_node = fct(chain, &old_lst, f, (va_list)valst);
		if (new_node == 0)
			return (chain->free(chain, FT_CHAIN_ALL));
		ft_lstadd_front(&(chain->curr), new_node);
		if (old_lst)
			old_lst = old_lst->next;
	}
	if (chain->curr == 0)
		return (0);
	ft_lstreverse(&(chain->curr));
	return (chain);
}
