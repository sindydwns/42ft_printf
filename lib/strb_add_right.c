/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_add_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:02 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/15 20:45:03 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advstr.h"

t_strb	*strb_add_right(t_strb *sb, char *str, t_del del)
{
	t_list	*node;

	if (sb->err)
		return (sb);
	node = strb_new_node(str, del);
	if (node == 0)
	{
		sb->err = 1;
		return (sb);
	}
	ft_lstadd_back(&(sb->strs), node);
	if (sb->strs == node)
		sb->last = node;
	return (sb);
}
