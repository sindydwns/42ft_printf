/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_x.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:50:31 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 10:07:39 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "ft_printf_private.h"

t_substr	*ft_printf_conv_x(t_parsed_token *token, va_list *valst)
{
	unsigned int	value;
	char			*res;

	token++;
	value = va_arg(*valst, unsigned int);
	res = ft_tobase(value, "0123456789abcdef");
	return (strb_create_substr(res, DETECT_LEN, free));
}
