/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:58 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/15 20:45:14 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advstr.h"

char	*strb_finish(struct s_strb *sb)
{
	char	*res;

	if (sb->err)
	{
		sb->clear(sb);
		return (0);
	}
	res = sb->build(sb);
	sb->clear(sb);
	return (res);
}
