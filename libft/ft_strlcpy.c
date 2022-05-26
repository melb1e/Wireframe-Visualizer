/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:42:37 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:33 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *destination, const char *source, size_t length)
{
	size_t	src_length;

	src_length = ft_strlen(source);
	if (src_length + 1 < length)
	{
		ft_memcpy(destination, source, src_length + 1);
	}
	else if (length != 0)
	{
		ft_memcpy(destination, source, length - 1);
		destination[length - 1] = 0;
	}
	return (src_length);
}
