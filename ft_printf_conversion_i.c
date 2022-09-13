/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_i.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:50:21 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 06:46:01 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private.h"

char	*ft_printf_conversion_i(t_parsed_token *token, va_list *valst)
{
	return (ft_printf_conversion_d(token, valst));
}
