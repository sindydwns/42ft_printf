/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 03:11:27 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/20 22:27:51 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

t_lstb	*lstb_clear(t_lstb *lstb, t_delf content_del)
{
	ft_lstclear(&(lstb->list), content_del);
	lstb_init(lstb, FT_NULL);
	return (lstb);
}
