/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_xx_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:00:09 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/20 18:44:17 by yonshin          ###   ########.fr       */
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
	char			*sign;
	t_strb			*(*add_str)(t_strb *sb, char *str, t_del del);

	value = va_arg(*valst, unsigned int);
	strb_init(&sb, ft_tobase(value, "0123456789ABCDEF"), free);
	if (value == 0 && token->flags & FLAG_DOT)
		sb.clear(&sb, 0, 0);
	sign = ft_if(token->flags & FLAG_SHARP && value != 0, "0X", "");
	if (token->flags & FLAG_DOT)
		sb.add_left(&sb, ft_strrepeat("0", token->precision - sb.len), free);
	else if (token->flags & FLAG_ZERO)
		sb.add_left(&sb, ft_strrepeat("0",
				token->width - sb.len - ft_strlen(sign)), free);
	sb.add_left(&sb, sign, 0);
	add_str = ft_if(token->flags & FLAG_DASH, sb.add_right, sb.add_left);
	add_str(&sb, ft_strrepeat(" ", token->width - sb.len), free);
	return (create_substr(sb.finish(&sb), DETECT_LEN));
}
