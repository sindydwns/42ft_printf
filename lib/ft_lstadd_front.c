/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 06:31:53 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/12 02:53:18 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*new_head;

	if (lst == 0 || new == 0)
		return ;
	new_head = new;
	while (new->next)
		new = new->next;
	new->next = *lst;
	*lst = new_head;
}
