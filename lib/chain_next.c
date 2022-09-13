/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:43:45 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/12 21:45:00 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*chain_next(t_chain *chain)
{
	chain->free(chain, FT_CHAIN_PREV);
	chain->prev = chain->curr;
	chain->curr = 0;
	return (chain->prev);
}
