/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 07:19:56 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 08:37:43 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tobase(unsigned long value, const char *base)
{
	char	buff[100];
	int		idx;
	int		len;

	if (value == 0)
		return ft_strdup("0");
	len = ft_strlen(base);
	if (len == 0)
		return (0);
	idx = 0;
	while (value)
	{
		buff[idx++] = base[value % len];
		value /= len;
	}
	buff[idx] = 0;
	return (ft_strreverse(buff));	
}
