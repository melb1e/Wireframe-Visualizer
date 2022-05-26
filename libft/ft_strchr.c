/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:40:49 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/25 15:31:07 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str_arg, int ch)
{
	char	*ptr;
	char	sym;

	ptr = (char *)str_arg;
	sym = (char)ch;
	while (*ptr && (*ptr == sym))
		ptr++;
	if (*ptr == sym)
		return (ptr);
	else
		return (NULL);
}
