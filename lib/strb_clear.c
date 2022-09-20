/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:53:04 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/20 20:07:05 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "advstr.h"

t_strb	*strb_clear(t_strb *sb, char *str, t_del del)
{
	t_list		*lst;

	lst = sb->substrs;
	ft_lstclear(&(sb->substrs), strb_delete_substr);
	sb->substrs = 0;
	sb->last = 0;
	sb->len = 0;
	sb->err = 0;
	if (str)
		return (strb_init(sb, str, del));
	return (sb);
}
