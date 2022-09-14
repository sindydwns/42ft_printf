/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv_i_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:59:46 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 12:59:46 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_private_bonus.h"

t_substr	*ft_printf_conv_i(t_parsed_token *token, va_list *valst)
{
	return (ft_printf_conv_d(token, valst));
}
