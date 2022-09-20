/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_finish.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:02:58 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/20 18:19:01 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advstr.h"

char	*strb_finish(struct s_strb *sb)
{
	char	*res;

	if (sb->err)
	{
		sb->clear(sb, 0, 0);
		return (0);
	}
	res = sb->build(sb);
	sb->clear(sb, 0, 0);
	return (res);
}
