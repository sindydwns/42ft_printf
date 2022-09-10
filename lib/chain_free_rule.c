/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_free_rule.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:07:04 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/09 16:32:15 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_chain	*chain_free_rule(t_chain *chain, t_delf d4prev, t_delf d4curr)
{
	chain->freeprev = d4prev;
	chain->freecurr = d4curr;
	return (chain);
}
