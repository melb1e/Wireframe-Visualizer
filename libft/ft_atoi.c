/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:36:53 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/23 18:10:48 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				sign;
	long long int	ret_value;

	sign = 1;
	ret_value = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str != 0 && ft_isdigit(*str))
		ret_value = ret_value * 10 + (int)*str++ - 48;
	ret_value *= sign;
	if (ret_value <= INT32_MAX && ret_value >= INT32_MIN)
		return ((int)ret_value);
	else if (sign == 1)
		return (-1);
	else
		return (0);
}
