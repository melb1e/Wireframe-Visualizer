/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:41:21 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:28 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output;
	size_t	s_length;
	int		i;

	if (s == NULL)
		return (NULL);
	s_length = ft_strlen(s);
	if (s_length == 0)
		return (NULL);
	if (s_length < len)
		len = s_length;
	i = 0;
	output = malloc(sizeof(char) * (len + 1));
	if (output == NULL)
		return (NULL);
	while (len-- != 0 && start < s_length && s[start] != 0)
	{
		output[i] = s[start++];
		i++;
	}
	output[i] = 0;
	return (output);
}
