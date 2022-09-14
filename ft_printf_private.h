/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 19:47:48 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/14 10:28:40 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H
# define FLAG_NO 0
# define FLAG_DASH 1
# define FLAG_PLUS 2
# define FLAG_SPACE 4
# define FLAG_SHARP 8
# define FLAG_ZERO 16
# define FLAG_DOT 32
# define FORMAT_NO 0
# define FORMAT_USE_CONVERSION 1
# define FORMAT_USE_FLAG 2
# define FORMAT_USE_WIDTH 4
# define FORMAT_USE_PRECISION 8
# define DETECT_LEN -1
# include <stdarg.h>

typedef struct s_substr
{
	char	*str;
	int		len;
}	t_substr;
typedef struct s_parsed_token
{
	char	*str;
	int		flags;
	int		width;
	int		precision;
	char	conversion;
}	t_parsed_token;
typedef char	*(*t_conversion_func)(t_parsed_token *token, va_list *valst);

int			skip_flag(char **str, const char *flags);
int			skip_number(char **str);
void		free_substr(void *substr);
t_substr	*create_substr(char *str, int len);
t_substr	*ft_printf_conv_c(t_parsed_token *token, va_list *valst);
t_substr	*ft_printf_conv_d(t_parsed_token *token, va_list *valst);
t_substr	*ft_printf_conv_i(t_parsed_token *token, va_list *valst);
t_substr	*ft_printf_conv_p(t_parsed_token *token, va_list *valst);
t_substr	*ft_printf_conv_s(t_parsed_token *token, va_list *valst);
t_substr	*ft_printf_conv_u(t_parsed_token *token, va_list *valst);
t_substr	*ft_printf_conv_x(t_parsed_token *token, va_list *valst);
t_substr	*ft_printf_conv_xx(t_parsed_token *token, va_list *valst);

#endif
