/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:11:24 by yonshin           #+#    #+#             */
/*   Updated: 2022/07/16 03:10:04 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

int	ft_atoi(const char *str)
{
	int		sign;
	long	value;

	sign = 1;
	value = 0;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		if (value > (value * 10) + (*str - '0'))
		{
			if (sign == -1)
				return ((int)LONG_MIN);
			else
				return ((int)LONG_MAX);
		}
		value = (value * 10) + (*str - '0');
		str++;
	}
	return (sign * value);
}
