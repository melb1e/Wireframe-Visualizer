/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:42:48 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:41 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t length)
{
	unsigned char		*ptr_dest;
	unsigned const char	*ptr_src;

	ptr_dest = (unsigned char *)destination + (length - 1);
	ptr_src = (const unsigned char *)source + (length - 1);
	if (ptr_dest > ptr_src)
	{
		while (length--)
		{
			*ptr_dest = *ptr_src;
			ptr_dest--;
			ptr_src--;
		}
	}
	else
	{
		return (ft_memcpy(destination, source, length));
	}
	return (destination);
}
