/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:43:20 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/26 20:35:41 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str_arg, size_t length)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str_arg;
	while (length--)
		*ptr++ = '\0';
}
