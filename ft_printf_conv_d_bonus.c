/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_d_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:59:42 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/18 21:43:57 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf_private_bonus.h"

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
	char	*padding;

	value = va_arg(*valst, int);
	if (value == 0 && token->flags & FLAG_DOT)
		strb_init(&sb, 0, 0);
	else
		strb_init(&sb, abs_itoa(value), free);
	if (token->flags & FLAG_DOT)
		sb.add_left(&sb, ft_strrepeat("0", token->precision - sb.len), free);
	else if (token->flags & FLAG_ZERO && *get_sign(token, value))
		sb.add_left(&sb, ft_strrepeat("0", token->width - sb.len - 1), free);
	else if (token->flags & FLAG_ZERO)
		sb.add_left(&sb, ft_strrepeat("0", token->width - sb.len), free);
	sb.add_left(&sb, get_sign(token, value), 0);
	padding = ft_if(token->flags & FLAG_ZERO, "0", " ");
	if (token->flags & FLAG_DASH)
		sb.add_right(&sb, ft_strrepeat(padding, token->width - sb.len), free);
	else
		sb.add_left(&sb, ft_strrepeat(padding, token->width - sb.len), free);
	return (create_substr(sb.finish(&sb), DETECT_LEN));
}
