/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:52:14 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/25 16:05:03 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	size_t	length;
	int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	output = malloc(sizeof(char) * (length + 1));
	if (output == NULL)
		return (NULL);
	while (*s1 != 0)
	{
		output[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != 0)
	{
		output[i] = *s2;
		i++;
		s2++;
	}
	output[i] = 0;
	return (output);
}
