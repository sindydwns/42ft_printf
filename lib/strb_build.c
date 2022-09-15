/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:43 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/15 20:45:08 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "advstr.h"

char	*strb_build(t_strb *sb)
{
	char	*res;
	char	*str;
	t_list	*lst;
	int		idx;

	if (sb->err)
		return (0);
	res = (char *)malloc(sb->len + 1);
	if (res == 0)
		return (0);
	lst = sb->strs;
	idx = 0;
	while (lst)
	{
		str = (char *)lst->content;
		while (*str)
			res[idx++] = *str++;
		lst = lst->next;
	}
	res[idx] = 0;
	return (res);
}
