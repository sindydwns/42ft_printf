/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:02:47 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/13 16:02:01 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <unistd.h>

typedef struct s_node
{
	int				fd;
	char			text[BUFFER_SIZE];
	ssize_t			idx;
	ssize_t			size;
	struct s_node	*next;
}	t_node;

char	*get_next_line(int fd);
char	*get_next_line_recursive(t_node **head, int fd, size_t start, int *err);

#endif
