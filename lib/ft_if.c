/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:26:48 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 13:27:40 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_if(int b, void *p1, void *p2)
{
	if (b)
		return (p1);
	return (p2);
}
