/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_s.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:50:26 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 05:08:56 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf_private.h"

char	*ft_printf_conversion_s(t_parsed_token *token, va_list *valst)
{
	valst++;
	return (ft_strdup(token->str));
}
