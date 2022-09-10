/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:04:43 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/09 22:41:43 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_chain	*chain_map(t_chain *chain, t_mapf f)
{
	if (chain->curr == 0)
		return (chain);
	chain->prev = chain->curr;
	chain->curr = ft_lstmap(chain->curr, f, chain->freecurr);
	return (chain);
}
