/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 07:44:03 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 08:07:40 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strreverse(char *str)
{
	int		len;
	int		idx;
	char	*res;

	if (str == 0)
		return (0);
	len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	res[len] = 0;
	if (res == 0)
		return (0);
	idx = -1;
	while (++idx < len)
		res[idx] = str[len - idx - 1];
	return (res);
}