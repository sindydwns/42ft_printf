/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_d.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:50:18 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 10:06:38 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf_private.h"

t_substr	*ft_printf_conv_d(t_parsed_token *token, va_list *valst)
{
	int		value;
	char	*res;

	token++;
	value = va_arg(*valst, int);
	res = ft_itoa(value);
	return (strb_create_substr(res, DETECT_LEN, free));
}
