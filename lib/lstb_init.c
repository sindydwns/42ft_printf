/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 02:55:15 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 22:42:40 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

t_lstb	*lstb_init(t_lstb *lstb, t_list *list)
{
	if (lstb == FT_NULL)
		return (FT_NULL);
	lstb->list = list;
	lstb->add = lstb_add;
	lstb->clear = lstb_clear;
	lstb->last = list;
	while (lstb->last && lstb->last->next)
		lstb->last = lstb->last->next;
	return (lstb);
}
