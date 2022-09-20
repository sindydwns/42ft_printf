/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_d.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:50:18 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 10:06:38 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf_private.h"

static char	*abs_itoa(int a)
{
	char	arr[42];
	int		idx;

	if (a > 0)
		a = -a;
	idx = 0;
	arr[idx++] = -(a % 10) + '0';
	while (a / 10)
	{
		a /= 10;
		arr[idx++] = -(a % 10) + '0';
	}
	arr[idx] = 0;
	return (ft_strreverse(arr));
}

static char	*get_sign(t_parsed_token *token, int value)
{
	if (value < 0)
		return ("-");
	if (token->flags & FLAG_PLUS)
		return ("+");
	if (token->flags & FLAG_SPACE)
		return (" ");
	return ("");
}

t_substr	*ft_printf_conv_d(t_parsed_token *token, va_list *valst)
{
	int		value;
	t_strb	sb;
	char	*sign;
	t_strb	*(*add_str)(t_strb *sb, char *str, t_del del);

	value = va_arg(*valst, int);
	strb_init(&sb, abs_itoa(value), free);
	if (value == 0 && token->flags & FLAG_DOT)
		sb.clear(&sb, 0, 0);
	sign = get_sign(token, value);
	if (token->flags & FLAG_DOT)
		sb.add_left(&sb, ft_strrepeat("0", token->precision - sb.len), free);
	else if (token->flags & FLAG_ZERO)
		sb.add_left(&sb, ft_strrepeat("0",
				token->width - sb.len - ft_strlen(sign)), free);
	sb.add_left(&sb, sign, 0);
	add_str = ft_if(token->flags & FLAG_DASH, sb.add_right, sb.add_left);
	add_str(&sb, ft_strrepeat(" ", token->width - sb.len), free);
	return (strb_create_substr(sb.finish(&sb), DETECT_LEN, free));
}
