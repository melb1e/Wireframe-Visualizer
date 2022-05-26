/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:40:38 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:29 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str_arg, int ch)
{
	char	*last_found;
	char	*ptr_str;

	last_found = 0;
	ptr_str = ft_strchr(str_arg, ch);
	if (ch == 0)
	{
		return (ft_strchr(str_arg, 0));
	}
	while (ptr_str != 0)
	{
		last_found = ptr_str;
		str_arg = ptr_str + 1;
		ptr_str = ft_strchr(str_arg, ch);
	}
	return ((char *)last_found);
}
