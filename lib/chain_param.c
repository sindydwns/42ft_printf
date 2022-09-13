/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:25:48 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 22:33:21 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advlst.h"

t_chain	*chain_param0(t_chain *ch)
{
	ch->param_len = 0;
	return (ch);
}

t_chain	*chain_param1(t_chain *ch, void *p1)
{
	ch->param[0] = p1;
	ch->param_len = 1;
	return (ch);
}

t_chain *chain_param2(t_chain *ch, void *p1, void *p2)
{
	ch->param[0] = p1;
	ch->param[1] = p2;
	ch->param_len = 2;
	return (ch);
}

t_chain *chain_param3(t_chain *ch, void *p1, void *p2, void *p3)
{
	ch->param[0] = p1;
	ch->param[1] = p2;
	ch->param[2] = p3;
	ch->param_len = 3;
	return (ch);
}
