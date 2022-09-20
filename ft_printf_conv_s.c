/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_s.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:50:26 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 10:17:25 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf_private.h"

t_substr	*ft_printf_conv_s(t_parsed_token *token, va_list *valst)
{
	char	*value;
	t_strb	sb;

	value = va_arg(*valst, char *);
	if (value == 0)
		value = "(null)";
	strb_init(&sb, value, 0);
	if (token->flags & FLAG_DOT)
		sb.clear(&sb, ft_substr(value, 0, token->precision), free);
	if (token->flags & FLAG_DASH)
		sb.add_right(&sb, ft_strrepeat(" ", token->width - sb.len), free);
	else
		sb.add_left(&sb, ft_strrepeat(" ", token->width - sb.len), free);
	return (strb_create_substr(sb.finish(&sb), DETECT_LEN, free));
}
