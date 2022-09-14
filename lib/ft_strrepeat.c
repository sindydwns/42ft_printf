/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 06:14:02 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 11:35:42 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrepeat(const char *str, int repeat)
{
	int		len;
	int		i;
	char	*res;

	if (str == 0)
		return (0);
	if (repeat <= 0)
		return (ft_strdup(""));
	len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * len * repeat + 1);
	if (res == 0)
		return (0);
	res[len * repeat] = 0;
	while (--repeat >= 0)
	{
		i = -1;
		while (++i < len)
			res[repeat * len + i] = str[i];
	}
	return (res);
}
