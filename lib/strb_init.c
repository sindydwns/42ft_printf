/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:50:59 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/16 16:17:51 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "advstr.h"

t_strb	*strb_init(t_strb *sb, char *str, t_del del)
{
	sb->strs = 0;
	sb->last = 0;
	sb->len = 0;
	sb->err = 0;
	sb->clear = strb_clear;
	sb->add_left = strb_add_left;
	sb->add_right = strb_add_right;
	sb->build = strb_build;
	sb->finish = strb_finish;
	if (str)
		sb->add_left(sb, str, del);
	return (sb);
}
