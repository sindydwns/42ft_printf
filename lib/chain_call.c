/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chain_call.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:41:39 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 23:24:52 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "advlst.h"

static t_list	*flat_factory(t_chain *ch, t_list **lst, t_mapf f)
{
	t_list	*result;
	t_list	*next;

	result = chain_apply(f, (*lst)->content, ch->param, ch->param_len);
	if (result == 0)
		return (0);
	next = result;
	while (next)
	{
		if (next->content == 0)
		{
			ft_lstclear(&result, ch->freerule[0]);
			return (0);
		}
		next = next->next;
	}
	return (result);
}

static t_list	*map_factory(t_chain *ch, t_list **lst, t_mapf f)
{
	t_list	*result;
	void	*content;

	content = chain_apply(f, (*lst)->content, ch->param, ch->param_len);
	if (content == 0)
		return (0);
	result = ft_lstnew(content);
	if (result)
		return (result);
	ch->freerule[0](content);
	return (0);
}

static t_list	*reduce_factory(t_chain *ch, t_list **lst, t_mapf f)
{
	t_list	*result;
	void	*content;

	content = chain_apply(f, lst, ch->param, ch->param_len);
	if (content == 0)
		return (0);
	result = ft_lstnew(content);
	if (result)
		return (result);
	ch->freerule[0](content);
	return (0);
}

t_chain	*chain_call(t_chain *chain, int t, void *f, t_delf del)
{
	t_chain	*res;

	chain->next(chain);
	chain->freerule[0] = del;
	res = FT_NULL;
	if (t == CHAIN_MAP)
		res = chain_iterate(chain, map_factory, (t_mapf)f);
	if (t == CHAIN_FLAT)
		res = chain_iterate(chain, flat_factory, (t_mapf)f);
	if (t == CHAIN_REDUCE)
		res = chain_iterate(chain, reduce_factory, (t_mapf)f);
	chain_param0(chain);
	return (res);
}