/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:39:16 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:30 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *full_str, const char *sub_str, size_t length)
{
	size_t	sub_len;

	sub_len = ft_strlen(sub_str);
	if (*sub_str == 0)
	{
		return ((char *)full_str);
	}
	while (length != 0 && *full_str != 0)
	{
		if (length-- >= sub_len && ft_strncmp(full_str, sub_str, sub_len) == 0)
		{
			return ((char *)full_str);
		}
		full_str++;
	}
	return (NULL);
}
