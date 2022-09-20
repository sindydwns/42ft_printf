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
	char	*res;

	token++;
	value = va_arg(*valst, char *);
	if (value == 0)
		res = ft_strdup("(null)");
	else
		res = ft_strdup(value);
	return (strb_create_substr(res, DETECT_LEN, free));
}
