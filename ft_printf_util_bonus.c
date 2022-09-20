/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:00:19 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/20 20:32:18 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_private_bonus.h"

int	skip_flag(char **str, const char *flags)
{
	const static int	flag_map[] = {
		FLAG_DASH,
		FLAG_PLUS,
		FLAG_SPACE,
		FLAG_SHARP,
		FLAG_ZERO
	};
	int					flag;

	flag = FLAG_NO;
	while (ft_strchr(flags, **str))
	{
		flag |= flag_map[ft_strchri(flags, **str)];
		(*str)++;
	}
	return (flag);
}

int	skip_number(char **str)
{
	int	width;

	width = 0;
	while (ft_isdigit(**str))
	{
		width = width * 10 + (**str - '0');
		(*str)++;
	}
	return (width);
}
