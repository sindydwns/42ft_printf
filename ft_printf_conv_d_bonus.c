/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_d_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:59:42 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 12:59:42 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf_private_bonus.h"

t_substr	*ft_printf_conv_d(t_parsed_token *token, va_list *valst)
{
	int		value;
	char	*res;

	token++;
	value = va_arg(*valst, int);
	res = ft_itoa(value);
	return (create_substr(res, DETECT_LEN));
}
