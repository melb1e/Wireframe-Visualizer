/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:39:41 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:43 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *reference, int ch, size_t length)
{
	const unsigned char	*srch_str;

	srch_str = (const unsigned char *)reference;
	while (length-- != 0)
	{
		if (*srch_str == (unsigned char)ch)
		{
			return ((void *)&*srch_str);
		}
		srch_str++;
	}
	return (NULL);
}
