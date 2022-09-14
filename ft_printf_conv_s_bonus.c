/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_s_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:59:54 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 12:59:54 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf_private_bonus.h"

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
	return (create_substr(res, DETECT_LEN));
}
