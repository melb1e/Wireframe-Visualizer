/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:06:20 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/25 18:54:31 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Part 1 - Libc functions
*/

# include <unistd.h>
# include <stdlib.h>
# include "get_next_line/get_next_line.h"

int		ft_isdigit(int arg);
int		ft_isalpha(int arg);
int		ft_isalnum(int arg);
int		ft_isascii(int arg);
int		ft_isprint(int arg);
int		ft_isspace(int arg);
size_t	ft_strlen(const char *str_arg);
void	*ft_memset(void *str_arg, int ch, size_t length);
void	ft_bzero(void *str_arg, size_t length);
void	*ft_memcpy(void *destination, const void *source, size_t length);
void	*ft_memmove(void *destination, const void *source, size_t length);
size_t	ft_strlcpy(char *destination, const char *source, size_t length);
size_t	ft_strlcat(char *destination, const char *source, size_t length);
int		ft_toupper(int ch);
int		ft_tolower(int ch);
char	*ft_strchr(const char *str_arg, int ch);
char	*ft_strrchr(const char *str_arg, int ch);
int		ft_strncmp(const char *reference, const char *str_arg, size_t length);
void	*ft_memchr(const void *reference, int ch, size_t length);
int		ft_memcmp(const void *reference_one, const void *reference_two, \
					size_t length);
char	*ft_strnstr(const char *full_str, const char *sub_str, size_t length);
int		ft_atoi(const char *str);

/*
** Functions that use malloc
*/
void	*ft_calloc(size_t num_obj, size_t size);
char	*ft_strdup(const char *str_arg);

/*
** Part 2 - Additional functions
*/
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

/*
** Part FDF
*/
void	ft_strdel(char **as);
int		ft_atoi_base(const char *str, int base);
int		ft_isnumber(char *str, int base);
void	ft_free_arr(char **arr);
double	ft_percent(int start, int end, int current);
int		ft_find_index(int x, int y, int width);
char	*ft_strchrs(const char *s, int c);
void	*ft_memalloc(size_t size);
char	*ft_strnew(size_t size);
char	*ft_strsubchr(const char *s, char c);
int		ft_sign(int a, int b);
float	ft_mod(float n);
float	ft_max(float a, float b);
float	ft_min(float a, float b);
int		ft_wcount(char const *str, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** Part 3 - Bonus part
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
/*
** !LIBFT_H
*/