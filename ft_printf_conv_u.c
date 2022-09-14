/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_u.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:50:28 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 10:07:34 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf_private.h"

t_substr	*ft_printf_conv_u(t_parsed_token *token, va_list *valst)
{
	unsigned int	value;
	char			*res;

	token++;
	value = va_arg(*valst, unsigned int);
	res = ft_tobase(value, "0123456789");
	return (create_substr(res, DETECT_LEN));
}
