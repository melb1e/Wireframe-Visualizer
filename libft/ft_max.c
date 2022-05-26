/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:20:05 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/23 17:42:29 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_max(float a, float b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

float	ft_min(float a, float b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
