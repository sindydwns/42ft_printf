/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:53:04 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/18 12:12:55 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "advstr.h"

t_strb	*strb_clear(t_strb *sb)
{
	t_list		*lst;
	t_list		*next;
	t_del		del;

	lst = sb->substrs;
	while (lst)
	{
		next = lst->next;
		del = ((t_substr *)lst->content)->del;
		if (del)
			del(((t_substr *)lst->content)->str);
		ft_lstdelone(lst, free);
		lst = next;
	}
	sb->substrs = 0;
	sb->last = 0;
	sb->len = 0;
	sb->err = 0;
	return (sb);
}
