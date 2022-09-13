/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:10:03 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 23:32:22 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "advlst.h"

void	*chain_apply(void *f, void *p, void **params, int len)
{
	if (len == 0)
		return (((t_mapf1)f)(p));
	if (len == 1)
		return (((t_mapf2)f)(p, params[0]));
	if (len == 2)
		return (((t_mapf3)f)(p, params[0], params[1]));
	if (len == 3)
		return (((t_mapf4)f)(p, params[0], params[1], params[2]));
	return (((t_mapf1)f)(p));
}
