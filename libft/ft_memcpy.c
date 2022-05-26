/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:43:07 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:42 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t length)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	if (destination == NULL && source == NULL && length > 0)
	{
		return (NULL);
	}
	ptr_dest = (unsigned char *)destination;
	ptr_src = (const unsigned char *)source;
	while (length-- != 0)
	{
		*ptr_dest = *ptr_src;
		ptr_dest++;
		ptr_src++;
	}
	return (destination);
}
