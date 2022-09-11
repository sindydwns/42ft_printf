/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:45:53 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/12 03:00:55 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_chain	*chain_init(t_chain *chain, t_list *lst)
{
	chain->prev = 0;
	chain->curr = lst;
	chain->freecurr = free;
	chain->freeprev = free;
	chain->flat = chain_flat;
	chain->reduce = chain_reduce;
	chain->map = chain_map;
	chain->freerule = chain_free_rule;
	chain->free = chain_free;
	return (chain);
}
