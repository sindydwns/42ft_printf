/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_u.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:50:28 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 10:07:34 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf_private.h"

static char	*uitoa(unsigned int a)
{
	char	arr[42];
	int		idx;

	idx = 0;
	arr[idx++] = (a % 10) + '0';
	while (a / 10)
	{
		a /= 10;
		arr[idx++] = (a % 10) + '0';
	}
	arr[idx] = 0;
	return (ft_strreverse(arr));
}

t_substr	*ft_printf_conv_u(t_parsed_token *token, va_list *valst)
{
	unsigned int	value;
	t_strb			sb;
	t_strb			*(*add_str)(t_strb *sb, char *str, t_del del);

	value = va_arg(*valst, unsigned int);
	strb_init(&sb, uitoa(value), free);
	if (value == 0 && token->flags & FLAG_DOT)
		sb.clear(&sb, 0, 0);
	if (token->flags & FLAG_DOT)
		sb.add_left(&sb, ft_strrepeat("0", token->precision - sb.len), free);
	else if (token->flags & FLAG_ZERO)
		sb.add_left(&sb, ft_strrepeat("0", token->width - sb.len), free);
	add_str = ft_if(token->flags & FLAG_DASH, sb.add_right, sb.add_left);
	add_str(&sb, ft_strrepeat(" ", token->width - sb.len), free);
	return (strb_create_substr(sb.finish(&sb), DETECT_LEN, free));
}
