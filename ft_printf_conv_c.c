/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_c.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:50:14 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 10:09:59 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf_private.h"

t_substr	*ft_printf_conv_c(t_parsed_token *token, va_list *valst)
{
	char	value;
	char	*res;
	int		len;

	value = va_arg(*valst, int);
	len = ft_max(1, token->width);
	if (token->flags & FLAG_ZERO)
		res = ft_strrepeat("0", len);
	else
		res = ft_strrepeat(" ", len);
	if (token->flags & FLAG_DASH)
		res[0] = value;
	else
		res[len - 1] = value;
	return (create_substr(res, len));
}
