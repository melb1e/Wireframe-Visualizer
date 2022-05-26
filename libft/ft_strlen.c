/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:37:25 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:32 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str_arg)
{
	size_t	length;

	length = 0;
	while (*str_arg != 0)
	{
		str_arg++;
		length++;
	}
	return (length);
}
