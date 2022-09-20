/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_u_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:59:58 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/20 18:32:44 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf_private_bonus.h"
#include "advstr.h"

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
	return (create_substr(sb.finish(&sb), DETECT_LEN));
}
