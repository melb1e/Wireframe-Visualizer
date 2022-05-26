/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:41:24 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:33 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *destination, const char *source, size_t length)
{
	char		*ptr_dest;
	const char	*ptr_src;
	size_t		dest_length;
	size_t		pos_dest;

	ptr_dest = destination;
	ptr_src = source;
	pos_dest = length;
	while (pos_dest-- != 0 && *ptr_dest != 0)
		ptr_dest++;
	dest_length = (size_t)ptr_dest - (size_t)destination;
	pos_dest = length - dest_length;
	if (pos_dest == 0)
		return (dest_length + ft_strlen(ptr_src));
	while (*ptr_src != 0)
	{
		if (pos_dest != 1)
		{
			*ptr_dest++ = *ptr_src;
			pos_dest--;
		}
		ptr_src++;
	}
	*ptr_dest = 0;
	return (dest_length + ((size_t)ptr_src - (size_t)source));
}
