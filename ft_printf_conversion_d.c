/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_d.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:50:18 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 07:18:52 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf_private.h"

char	*ft_printf_conversion_d(t_parsed_token *token, va_list *valst)
{
	int		value;
	char	*res;

	token++;
	value = va_arg(*valst, int);
	res = ft_itoa(value);
	return (res);
}
