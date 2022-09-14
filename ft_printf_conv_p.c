/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_p.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:50:23 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 10:06:48 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_private.h"

t_substr	*ft_printf_conv_p(t_parsed_token *token, va_list *valst)
{
	void	*value;
	char	*temp;
	char	*res;

	token++;
	value = va_arg(*valst, void *);
	res = ft_tobase((unsigned long)value, "0123456789abcdef");
	temp = res;
	res = ft_strjoin("0x", res);
	free(temp);
	return (create_substr(res, DETECT_LEN));
}
