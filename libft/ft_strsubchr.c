/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 14:05:08 by vbrazhni          #+#    #+#             */
/*   Updated: 2022/05/23 18:17:31 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubchr(const char *s, char c)
{
	char	*ptr;

	ptr = ft_strchrs(s, c);
	if (!ptr)
		return (NULL);
	return (ft_strsub(s, 0, ptr - s));
}
