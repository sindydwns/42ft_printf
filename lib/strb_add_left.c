/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_add_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:00:57 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/18 13:22:18 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advstr.h"

t_strb	*strb_add_left(t_strb *sb, char *str, t_del del)
{
	t_list	*node;

	if (sb->err || str == 0)
		return (sb);
	if (*str == 0)
	{
		if (del != 0)
			del(str);
		return (sb);
	}
	node = strb_new_node(str, del);
	if (node == 0)
	{
		sb->err = 1;
		return (sb);
	}
	ft_lstadd_front(&(sb->substrs), node);
	if (sb->substrs->next == 0)
		sb->last = node;
	return (sb);
}
