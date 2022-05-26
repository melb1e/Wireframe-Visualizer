/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:11:51 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/25 16:09:09 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnllen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_gnljoin(char const *s1, char const *s2)
{
	char			*output;
	unsigned int	length;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	length = (ft_gnllen(s1) + ft_gnllen(s2) + 1);
	output = malloc(sizeof(char) * length);
	if (!output)
		return (NULL);
	while (s1 && s1[i])
	{
		output[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		output[i++] = s2[j++];
	output[i] = '\0';
	ft_free((char *)s1);
	return (output);
}

char	*ft_free(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

int	ft_islf(char ch)
{
	if (ch == '\n')
		return (1);
	return (0);
}
