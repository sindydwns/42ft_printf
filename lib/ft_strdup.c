/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:33:58 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 09:20:35 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*dup;

	if (s1 == 0)
		return (0);
	size = 0;
	while (s1[size])
		size++;
	dup = (char *)malloc(sizeof(char) * size + 1);
	if (dup == 0)
		return (0);
	size = 0;
	while (s1[size])
	{
		dup[size] = s1[size];
		size++;
	}
	dup[size] = 0;
	return (dup);
}
