/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:16:20 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/09 16:32:25 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

t_chain	*chain_free(t_chain *chain, int range)
{
	if (range & CHAIN_PREV)
		ft_lstclear(&(chain->prev), chain->freerule[1]);
	if (range & CHAIN_CURR)
		ft_lstclear(&(chain->curr), chain->freerule[0]);
	return (chain);
}
