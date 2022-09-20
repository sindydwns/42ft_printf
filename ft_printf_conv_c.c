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
#include <stdlib.h>
#include "ft_printf_private.h"

t_substr	*ft_printf_conv_c(t_parsed_token *token, va_list *valst)
{
	char	value;
	char	*res;

	token++;
	value = va_arg(*valst, int);
	res = ft_strrepeat("0", 1);
	if (res == 0)
		return (0);
	res[0] = value;
	return (strb_create_substr(res, 1, free));
}
