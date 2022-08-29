/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:47:48 by yonshin           #+#    #+#             */
/*   Updated: 2022/08/29 22:50:28 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H
# define FLAG_NO 0
# define FLAG_DASH 1
# define FLAG_ZERO 2
# define FLAG_DOT 4
# define FLAG_SHARP 8
# define FLAG_SPACE 16
# define FLAG_PLUS 32
# define STAT_ERR -1
# define STAT_NORM 0
# define STAT_FORM 1
# include "libft.h"

typedef struct s_printable
{
	char		*str;
	int			len;
	int			flags;
	void		*data;
	void		(*print)(struct s_printable);
}	t_printable;
typedef void	(*t_print_func)(struct s_printable);

int		ft_printf_conversion_(t_printable *printable);
int		ft_printf_conversion_c(t_printable *printable);
int		ft_printf_conversion_d(t_printable *printable);
int		ft_printf_conversion_i(t_printable *printable);
int		ft_printf_conversion_p(t_printable *printable);
int		ft_printf_conversion_s(t_printable *printable);
int		ft_printf_conversion_u(t_printable *printable);
int		ft_printf_conversion_x(t_printable *printable);
int		ft_printf_conversion_xx(t_printable *printable);

#endif
