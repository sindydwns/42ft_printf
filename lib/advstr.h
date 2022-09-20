/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advstr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:12:16 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/20 18:13:42 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADVSTR_H
# define ADVSTR_H
# include "libft.h"

typedef void	(*t_del)(void *p);
typedef struct s_substr
{
	t_del	del;
	char	*str;
	int		len;
}	t_substr;
typedef struct s_strb
{
	t_list			*substrs;
	t_list			*last;
	int				len;
	int				err;
	struct s_strb	*(*add_left)(struct s_strb *sb, char *str, t_del del);
	struct s_strb	*(*add_right)(struct s_strb *sb, char *str, t_del del);
	struct s_strb	*(*clear)(struct s_strb *sb, char *str, t_del del);
	char			*(*build)(struct s_strb *sb);
	char			*(*finish)(struct s_strb *sb);
}	t_strb;

t_strb	*strb_init(t_strb *sb, char *str, t_del del);
t_strb	*strb_add_left(t_strb *sb, char *str, t_del del);
t_strb	*strb_add_right(t_strb *sb, char *str, t_del del);
char	*strb_build(t_strb *sb);
t_strb	*strb_clear(t_strb *sb, char *str, t_del del);
char	*strb_finish(struct s_strb *sb);
t_list	*strb_new_node(char *str, t_del del);
#endif
