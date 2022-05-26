/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:11:59 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/25 16:12:13 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 64
# endif
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft.h"

char	*get_next_line(int fd);
char	*ft_free(char *str);
int		ft_islf(char ch);
char	*ft_gnljoin(char const *s1, char const *s2);
size_t	ft_gnllen(const char *str);

#endif
/*
** !GET_NEXT_LINE_H
*/