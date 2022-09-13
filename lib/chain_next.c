/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:43:45 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 22:07:52 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "advlst.h"

t_list	*chain_next(t_chain *chain)
{
	chain->free(chain, CHAIN_PREV);
	chain->prev = chain->curr;
	chain->freerule[1] = chain->freerule[0];
	chain->curr = 0;
	chain->freerule[0] = 0;
	return (chain->prev);
}
