/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_p_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:59:50 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/18 22:01:48 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_private_bonus.h"

t_substr	*ft_printf_conv_p(t_parsed_token *token, va_list *valst)
{
	void	*value;
	t_strb	sb;

	value = va_arg(*valst, void *);
	strb_init(&sb, ft_tobase((unsigned long)value, "0123456789abcdef"), free);
	sb.add_left(&sb, "0x", 0);
	if (token->flags & FLAG_DASH)
		sb.add_right(&sb, ft_strrepeat(" ", token->width - sb.len), free);
	else
		sb.add_left(&sb, ft_strrepeat(" ", token->width - sb.len), free);
	return (create_substr(sb.finish(&sb), DETECT_LEN));
}
