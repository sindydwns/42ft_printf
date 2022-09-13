/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:04:43 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 16:00:25 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static t_list	*factory(t_chain *ch, t_list **lst, t_mapf f, void *valst)
{
	t_list	*result;
	void	*content;

	content = chain_apply(f, (*lst)->content, valst, ch);
	if (content == 0)
		return (0);
	result = ft_lstnew(content);
	if (result)
		return (result);
	ch->freecurr(content);
	return (0);
}

t_chain	*chain_map(t_chain *chain, t_mapf f, ...)
{
	va_list	args;

	va_start(args, f);
	chain_iterate(chain, factory, f, args);
	va_end(args);
	return (chain);
}
