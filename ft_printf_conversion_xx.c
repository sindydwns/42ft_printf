/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_xx.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:50:34 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 08:40:53 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_private.h"

char	*ft_printf_conversion_xx(t_parsed_token *token, va_list *valst)
{
	void			*value;
	char			*temp;
	char			*res;

	token++;
	value = va_arg(*valst, void *);
	res = ft_tobase((unsigned int)value, "0123456789ABCDEF");
	temp = res;
	res = ft_strjoin("0X", res);
	free(temp);
	return (res);
}
