/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstb_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 03:11:27 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 19:45:20 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

t_lstb	*lstb_clear(t_lstb *lstb, t_delf del)
{
	ft_lstclear(&(lstb->list), del);
	lstb_init(lstb, FT_NULL);
	return (lstb);
}
