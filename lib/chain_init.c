/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:45:53 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 22:31:56 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "advlst.h"

t_chain	*chain_init(t_chain *chain, t_list *lst, t_delf del)
{
	chain->prev = 0;
	chain->curr = lst;
	chain->freerule[0] = del;
	chain->freerule[1] = 0;
	chain->param[0] = 0;
	chain->param[1] = 0;
	chain->param[2] = 0;
	chain->param_len = 0;
	chain->param0 = chain_param0;
	chain->param1 = chain_param1;
	chain->param2 = chain_param2;
	chain->param3 = chain_param3;
	chain->call = chain_call;
	chain->free = chain_free;
	chain->next = chain_next;
	return (chain);
}
