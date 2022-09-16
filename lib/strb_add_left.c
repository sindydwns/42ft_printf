/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_add_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:00:57 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/16 16:19:56 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advstr.h"

t_strb	*strb_add_left(t_strb *sb, char *str, t_del del)
{
	t_list	*node;

	if (sb->err || str == 0 || *str == 0)
		return (sb);
	node = strb_new_node(str, del);
	if (node == 0)
	{
		sb->err = 1;
		return (sb);
	}
	ft_lstadd_front(&(sb->strs), node);
	if (sb->strs->next == 0)
		sb->last = node;
	return (sb);
}
