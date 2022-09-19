/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_xx_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:00:09 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/18 23:39:13 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_private_bonus.h"
#include "advstr.h"

t_substr	*ft_printf_conv_xx(t_parsed_token *token, va_list *valst)
{
	unsigned int	value;
	t_strb			sb;
	char			*padding;

	value = va_arg(*valst, unsigned int);
	if (value == 0 && token->flags & FLAG_DOT)
		strb_init(&sb, 0, 0);
	else
		strb_init(&sb, ft_tobase(value, "0123456789ABCDEF"), free);
	if (token->flags & FLAG_DOT)
		sb.add_left(&sb, ft_strrepeat("0", token->precision - sb.len), free);
	padding = ft_if(token->flags & FLAG_ZERO, "0", " ");
	if (token->flags & FLAG_DASH)
		sb.add_right(&sb, ft_strrepeat(padding, token->width - sb.len), free);
	else
		sb.add_left(&sb, ft_strrepeat(padding, token->width - sb.len), free);
	return (create_substr(sb.finish(&sb), DETECT_LEN));
}
