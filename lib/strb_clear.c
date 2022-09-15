/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:53:04 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/15 20:43:47 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advstr.h"

t_strb	*strb_clear(t_strb *sb)
{
	t_list		*lst;
	t_list		*next;

	lst = sb->strs;
	while (lst)
	{
		next = lst->next;
		ft_lstdelone(lst, ((t_substr *)lst->content)->del);
		lst = next;
	}
	sb->last = 0;
	sb->len = 0;
	sb->err = 0;
	return (sb);
}
