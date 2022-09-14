/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_p_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:59:50 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 12:59:50 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf_private_bonus.h"

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
