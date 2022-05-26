/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:40:27 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:31 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *reference, const char *str_arg, size_t length)
{
	if (length == 0)
	{
		return (0);
	}
	while (length-- != 0)
	{
		if (*reference != *str_arg)
		{
			return (*(unsigned char *)reference - *(unsigned char *)str_arg);
		}
		str_arg++;
		if (*reference == 0)
		{
			break ;
		}
		reference++;
	}
	return (0);
}
