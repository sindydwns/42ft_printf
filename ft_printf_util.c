/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 09:02:43 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/21 00:07:11 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_private.h"

int	skip_flag(char **str)
{
	const static char	*flags = "-+ #0";
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

char	skip_conversion(char **str)
{
	const static char	*conversions = "%cdipsuxX";
	char				*conversion;

	if (*str == 0)
		return (FT_ERROR);
	conversion = ft_strchr(conversions, **str);
	if (conversion == 0)
		return (0);
	(*str)++;
	return (*conversion);
}

char	*read_context(t_parsed_token *content, char *s)
{
	content->str = s++;
	if (*(content->str) == '%')
	{
		content->flags = skip_flag(&s);
		content->width = skip_number(&s);
		if (*s == '.' && *s++)
		{
			content->flags |= FLAG_DOT;
			content->precision = skip_number(&s);
		}
		content->conversion = skip_conversion(&s);
	}
	if (content->conversion == 0)
	{
		while (*s && *s != '%')
			s++;
		content->width = (int)(s - content->str);
	}
	return (s);
}
