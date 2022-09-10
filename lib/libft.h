/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 13:52:51 by yonshin           #+#    #+#             */
/*   Updated: 2022/09/10 00:17:15 by yonshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define FT_NULL 0
# define FT_SUCCESS 0
# define FT_ERROR -1
# define FT_TRUE 1
# define FT_FALSE 0
# define FT_CHAIN_FREE_PREV 1
# define FT_CHAIN_FREE_CURR 2
# define FT_CHAIN_FREE_ALL 3
# include "get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
typedef void	(*t_delf)(void *p1);
typedef	t_list	*(*t_flatf)(void *p1);
typedef void	*(*t_reducef)(t_list **list);
typedef	void	*(*t_mapf)(void *p1);
typedef struct s_chain
{
	t_list			*prev;
	t_list			*curr;
	t_delf			freeprev;
	t_delf			freecurr;
	struct s_chain	*(*flat)(struct s_chain *chain, t_flatf f);
	struct s_chain	*(*reduce)(struct s_chain *chain, t_reducef f);
	struct s_chain	*(*map)(struct s_chain *chain, t_mapf f);
	struct s_chain	*(*freerule)(struct s_chain *chain, t_delf d1, t_delf d2);
	struct s_chain	*(*freeall)(struct s_chain *chain, int range);
}	t_chain;

int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_chain	*chain_init(t_chain *chain, t_list *lst);
t_chain	*chain_flat(t_chain *chain, t_flatf f);
t_chain	*chain_reduce(t_chain *chain, t_reducef f);
t_chain	*chain_map(t_chain *chain, t_mapf f);
t_chain	*chain_free_rule(t_chain *chain, t_delf d4prev, t_delf del4curr);
t_chain	*chain_free(t_chain *chain, int range);
#endif
