/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_apply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:10:03 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/12 00:12:44 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

void	*chain_apply(void *f, void *curr, void *valist, void *end)
{
	va_list	val;
	void	*arr[4];

	val = (va_list)valist;
	arr[0] = va_arg(val, void*);
	if (arr[0] == end)
		return (((t_mapf1)f)(curr));
	arr[1] = va_arg(val, void*);
	if (arr[1] == end)
		return (((t_mapf2)f)(curr, arr[0]));
	arr[2] = va_arg(val, void*);
	if (arr[2] == end)
		return (((t_mapf3)f)(curr, arr[0], arr[1]));
	arr[3] = va_arg(val, void*);
	if (arr[3] == end)
		return (((t_mapf4)f)(curr, arr[0], arr[1], arr[2]));
	return (((t_mapf1)f)(curr));
}
