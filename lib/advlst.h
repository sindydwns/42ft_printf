/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advlst.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:44:38 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 22:38:53 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADVLST_H
# define ADVLST_H
# define CHAIN_FLAT 1
# define CHAIN_MAP 2
# define CHAIN_REDUCE 3
# define CHAIN_CURR 1
# define CHAIN_PREV 2
# define CHAIN_ALL 3
# define CONTENT_NO_FREE 0
# include "libft.h"

typedef void	(*t_delf)(void *p1);
typedef t_list	*(*t_flatf)(void *content);
typedef t_list	*(*t_flatf1)(void *content);
typedef t_list	*(*t_flatf2)(void *content, void *p2);
typedef t_list	*(*t_flatf3)(void *content, void *p2, void *p3);
typedef t_list	*(*t_flatf4)(void *content, void *p2, void *p3, void *p4);
typedef void	*(*t_reducef)(t_list **list);
typedef void	*(*t_reducef1)(t_list **list);
typedef void	*(*t_reducef2)(t_list **list, void *p2);
typedef void	*(*t_reducef3)(t_list **list, void *p2, void *p3);
typedef void	*(*t_reducef4)(t_list **list, void *p2, void *p3, void *p4);
typedef void	*(*t_mapf)(void *content);
typedef void	*(*t_mapf1)(void *content);
typedef void	*(*t_mapf2)(void *content, void *p2);
typedef void	*(*t_mapf3)(void *content, void *p2, void *p3);
typedef void	*(*t_mapf4)(void *content, void *p2, void *p3, void *p4);
typedef struct s_chain
{
	t_list			*prev;
	t_list			*curr;
	t_delf			freerule[2];
	void			*param[3];
	int				param_len;
	struct s_chain	*(*param0)(struct s_chain *chain);
	struct s_chain	*(*param1)(struct s_chain *chain, void *p1);
	struct s_chain	*(*param2)(struct s_chain *chain, void *p1, void *p2);
	struct s_chain	*(*param3)(struct s_chain *chain, void *p1, void *p2, void *p3);
	struct s_chain	*(*call)(struct s_chain *chain, int t, void *f, t_delf d);
	struct s_chain	*(*free)(struct s_chain *chain, int range);
	t_list			*(*next)(struct s_chain *chain);
}	t_chain;
typedef t_list	*(*t_factory)(t_chain *ch, t_list **lst, t_mapf f);
typedef struct s_lstb
{
	t_list			*list;
	t_list			*last;
	int				(*add)(struct s_lstb *b, void *content, t_delf del);
	struct s_lstb	*(*clear)(struct s_lstb *b, t_delf del);
}	t_lstb;

t_chain	*chain_init(t_chain *chain, t_list *lst, t_delf d);
t_chain	*chain_iterate(t_chain *chain, t_factory fct, t_mapf f);
t_list	*chain_next(t_chain *ch);
t_chain *chain_param0(t_chain *ch);
t_chain	*chain_param1(t_chain *ch, void *p1);
t_chain	*chain_param2(t_chain *ch, void *p1, void *p2);
t_chain	*chain_param3(t_chain *ch, void *p1, void *p2, void *p3);
void	*chain_apply(void *f, void *p, void **params, int len);
t_chain	*chain_call(t_chain *chain, int t, void *f, t_delf del);
t_chain	*chain_free(t_chain *chain, int range);
t_lstb	*lstb_init(t_lstb *lstb, t_list *list);
int		lstb_add(t_lstb *lstb, void *content, t_delf del);
t_lstb	*lstb_clear(t_lstb *lstb, t_delf del);
#endif