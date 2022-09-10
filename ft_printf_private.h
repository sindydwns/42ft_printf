/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:47:48 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/08 19:49:48 by yonshin          ###   ########.fr       */
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
# define FORMAT_NO 0
# define FORMAT_USE_CONVERSION 1
# define FORMAT_USE_FLAG 2
# define FORMAT_USE_WIDTH 4
# define FORMAT_USE_PRECISION 8
# define ERR -1
# include "libft.h"

typedef char *(*t_conversion_func)(void *pared_token);

typedef struct s_raw_token
{
	char	*str;
	int		len;
	va_list	*args;
}	t_raw_token;

typedef struct s_parsed_token
{
	char	*str;
	void	*arg;
	int		format;
	int		flags;
	int		width;
	int		precision;
	char	conversion;
}	t_parsed_token;

char	*ft_printf_conversion_(t_parsed_token *token);
char	*ft_printf_conversion_c(t_parsed_token *token);
char	*ft_printf_conversion_d(t_parsed_token *token);
char	*ft_printf_conversion_i(t_parsed_token *token);
char	*ft_printf_conversion_p(t_parsed_token *token);
char	*ft_printf_conversion_s(t_parsed_token *token);
char	*ft_printf_conversion_u(t_parsed_token *token);
char	*ft_printf_conversion_x(t_parsed_token *token);
char	*ft_printf_conversion_xx(t_parsed_token *token);

#endif
