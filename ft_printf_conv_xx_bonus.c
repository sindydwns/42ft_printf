/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_xx_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:00:09 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 13:00:09 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_private_bonus.h"

t_substr	*ft_printf_conv_xx(t_parsed_token *token, va_list *valst)
{
	unsigned int	value;
	char			*res;

	token++;
	value = va_arg(*valst, unsigned int);
	res = ft_tobase(value, "0123456789ABCDEF");
	return (create_substr(res, DETECT_LEN));
}
