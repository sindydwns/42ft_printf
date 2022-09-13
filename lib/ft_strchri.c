/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 04:03:22 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 04:32:59 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchri(const char *s, int c)
{
	char	*found;

	found = ft_strchr(s, c);
	if (found)
		return (found - s);
	return (-1);
}
