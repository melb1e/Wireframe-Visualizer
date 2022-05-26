/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:04:19 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:29 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;
	char	*output;
	int		start_l;
	int		end_l;

	if (s1 == NULL || set == NULL)
	{
		output = NULL;
		return (output);
	}
	start_l = 0;
	end_l = ft_strlen(s1);
	while (s1[start_l] != 0 && ft_strchr(set, s1[start_l]))
		start_l++;
	while (end_l > start_l && ft_strchr(set, s1[end_l - 1]))
		end_l--;
	length = end_l - start_l + 1;
	output = malloc(sizeof(char) * (length));
	if (output == NULL)
		return (NULL);
	ft_strlcpy(output, &s1[start_l], length);
	return (output);
}
