/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:02:51 by yonshin           #+#    #+#             */
/*   Updated: 2022/08/04 13:17:11 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_node	*list;
	int				err;

	if (fd < 0)
		return (0);
	err = 0;
	return (get_next_line_recursive(&list, fd, 0, &err));
}
