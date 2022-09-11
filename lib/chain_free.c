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

t_chain	*chain_free(t_chain *chain, int range)
{
	if (range & FT_CHAIN_PREV)
		ft_lstclear(&(chain->prev), chain->freeprev);
	if (range & FT_CHAIN_CURR)
		ft_lstclear(&(chain->curr), chain->freecurr);
	return (chain);
}
