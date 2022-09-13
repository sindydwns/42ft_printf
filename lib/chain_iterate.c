/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_iterate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:48:17 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 22:42:13 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "advlst.h"

t_chain	*chain_iterate(t_chain *chain, t_factory fct, t_mapf f)
{
	t_list	*old_lst;
	t_list	*new_node;

	old_lst = chain->prev;
	while (old_lst)
	{
		new_node = fct(chain, &old_lst, f);
		if (new_node == 0)
			return (chain->free(chain, CHAIN_ALL));
		ft_lstadd_front(&(chain->curr), new_node);
		if (old_lst)
			old_lst = old_lst->next;
	}
	ft_lstreverse(&(chain->curr));
	return (chain);
}
