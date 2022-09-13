/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_reduce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:01:20 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/12 21:39:56 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static t_list	*factory(t_chain *ch, t_list **lst, t_mapf f, void *valst)
{
	t_list	*result;
	void	*content;

	content = chain_apply(f, lst, valst, ch);
	if (content == 0)
		return (0);
	result = ft_lstnew(content);
	if (result)
		return (result);
	ch->freecurr(content);
	return (0);
}

t_chain	*chain_reduce(t_chain *chain, t_reducef1 f, ...)
{
	va_list	args;

	va_start(args, f);
	chain_iterate(chain, factory, (t_mapf)f, args);
	va_end(args);
	return (chain);
}
