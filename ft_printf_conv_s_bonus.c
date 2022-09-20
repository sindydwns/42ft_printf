/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_s_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:59:54 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/20 18:19:57 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf_private_bonus.h"
#include "advstr.h"

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
	return (create_substr(sb.finish(&sb), DETECT_LEN));
}
