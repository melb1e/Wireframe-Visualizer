/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:39:30 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:43 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *reference_one, const void *reference_two, \
				size_t length)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str1 = (const unsigned char *)reference_one;
	str2 = (const unsigned char *)reference_two;
	i = 0;
	while (length-- != 0)
	{
		if (str1[i] != str2[i])
		{
			if (str1[i] < str2[i])
			{
				return (str1[i] - str2[i]);
			}
			else
			{
				return (str1[i] - str2[i]);
			}
		}
		i++;
	}
	return (0);
}
