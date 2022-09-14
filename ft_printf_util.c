/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:02:43 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 10:15:22 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_private.h"
#include "libft.h"

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

t_substr	*create_substr(char *str, int len)
{
	t_substr	*res;

	if (str == 0)
		return (0);
	res = (t_substr *)malloc(sizeof(t_substr));
	if (res == 0)
	{
		free(str);
		return (0);
	}
	res->str = str;
	if (len == DETECT_LEN)
		res->len = ft_strlen(str);
	else
		res->len = len;
	return (res);
}

void	free_substr(void *substr)
{
	if (substr == 0)
		return ;
	free(((t_substr *)substr)->str);
	free(substr);
}
