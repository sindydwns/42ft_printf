/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_new_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:51:55 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/15 20:47:02 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "advstr.h"

t_list	*strb_new_node(char *str, t_del del)
{
	t_substr	*substr;
	t_list		*node;

	if (str == 0)
		return (0);
	substr = (t_substr *)malloc(sizeof(t_substr));
	if (substr == 0)
		return (0);
	substr->str = str;
	substr->del = del;
	substr->len = ft_strlen(str);
	node = ft_lstnew(substr);
	if (node == 0)
		del(str);
	return (node);
}
