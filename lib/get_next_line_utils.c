/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 23:02:53 by yonshin           #+#    #+#             */
/*   Updated: 2022/08/08 19:47:59 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

/* ****************************************************************	*/
/*	if a node matching the fd value exists then return the node.	*/
/*	note. the node is removed from list.							*/
/* ****************************************************************	*/
static t_node	*grab_node(t_node **head, int fd)
{
	t_node	*before;
	t_node	*node;

	before = 0;
	node = *head;
	while (node && node->fd != fd)
	{
		before = node;
		node = node->next;
	}
	if (node && !before)
		*head = node->next;
	if (node && before)
		before->next = node->next;
	if (node)
		node->next = 0;
	return (node);
}

/* ************************************************************	*/
/*	Read a text sizeof BUFFER_SIZE from fd and return t_node.	*/
/*	If fail to malloc node or read from fd then return 0.		*/
/* ************************************************************	*/
static t_node	*create_next_node(int fd)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == 0)
		return (0);
	node->fd = fd;
	node->size = read(node->fd, node->text, BUFFER_SIZE);
	node->idx = 0;
	node->next = 0;
	if (node->size <= 0)
	{
		free(node);
		return (0);
	}
	return (node);
}

/* ************************************************************	*/
/*	Read chars from text starting at the idx position of node	*/
/*	It stops when it read c. And return copy length.			*/
/* ************************************************************	*/
static ssize_t	next_find_c(t_node *node, char c, ssize_t *start)
{
	ssize_t	len;

	len = 0;
	if (node == 0)
		return (len);
	*start = node->idx;
	while (len < node->size - node->idx)
		if (node->text[*start + len++] == c)
			break ;
	node->idx += len;
	return (len);
}

/* ************************************************************ */
/*	If there is more to read from the node then					*/
/*	add the node to the front of the list.	Else free.			*/
/* ************************************************************ */
static void	keep_or_free(t_node **head, t_node *node)
{
	if (head == 0 || node == 0)
		return ;
	if (node->idx == node->size)
		free(node);
	else
	{
		node->next = *head;
		*head = node;
	}
}

char	*get_next_line_recursive(t_node **head, int fd, size_t offset, int *err)
{
	t_node	*node;
	ssize_t	start;
	ssize_t	len;
	char	*res;

	res = 0;
	node = grab_node(head, fd);
	if (node == 0)
		node = create_next_node(fd);
	len = next_find_c(node, '\n', &start);
	if (len > 0 && node->text[start + len - 1] != '\n')
		res = get_next_line_recursive(head, fd, offset + len, err);
	if (len > 0 && res == 0 && *err == 0)
	{
		res = (char *)malloc(sizeof(char) * (offset + len + 1));
		if (res == 0)
			*err = 1;
		if (*err == 0)
			res[offset + len] = 0;
	}
	while (--len >= 0 && *err == 0)
		res[offset + len] = node->text[start + len];
	keep_or_free(head, node);
	return (res);
}
