/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strb_delete_substr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:58:32 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/20 20:38:24 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "advstr.h"

void	strb_delete_substr(void *p)
{
	t_substr	*substr;

	substr = (t_substr *)p;
	if (substr == 0)
		return ;
	if (substr->del)
		substr->del(substr->str);
	free(substr);
}
