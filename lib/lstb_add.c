/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 03:11:17 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 19:45:12 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

int	lstb_add(t_lstb *lstb, void *content, t_delf del)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (node == 0)
	{
		if (del)
			del(content);
		return (FT_ERROR);
	}
	if (lstb->last)
		ft_lstadd_back(&(lstb->last), node);
	else
		ft_lstadd_back(&(lstb->list), node);
	lstb->last = node;
	return (FT_SUCCESS);
}
