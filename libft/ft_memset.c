/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:43:35 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:40 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str_arg, int ch, size_t length)
{
	unsigned char	*pointer;

	pointer = (unsigned char *)str_arg;
	while (length != 0)
	{
		pointer[length - 1] = (unsigned char)ch;
		length--;
	}
	return (str_arg);
}
