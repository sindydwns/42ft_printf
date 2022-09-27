/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_create_substr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:49:48 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/23 16:21:45 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "advstr.h"

t_substr	*strb_create_substr(char *str, int len, t_del del)
{
	t_substr	*substr;

	if (str == 0)
		return (0);
	substr = (t_substr *)malloc(sizeof(t_substr));
	if (substr == 0)
	{
		if (del)
			del(str);
		return (0);
	}
	substr->str = str;
	substr->len = len;
	if (len == DETECT_LEN)
		substr->len = ft_strlen(str);
	substr->del = del;
	return (substr);
}
