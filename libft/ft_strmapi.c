/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 10:07:20 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:32 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	size_t	i;
	size_t	length;

	if (s == NULL || f == NULL)
	{
		return (NULL);
	}
	length = ft_strlen(s) + 1;
	output = malloc(sizeof(char) * (length));
	if (output == NULL)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		output[i] = (*f)(i, s[i]);
		i++;
	}
	output[i] = 0;
	return (output);
}
