/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:00:09 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:42:53 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_len(int n)
{
	size_t	length;

	length = 1;
	if (n < 0)
	{
		length++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		length++;
	}
	return (length);
}

static int	get_denom(size_t length)
{
	int	denominator;

	denominator = 1;
	if (length == 1)
	{
		return (denominator);
	}
	while (length >= 2)
	{
		denominator *= 10;
		length--;
	}
	return (denominator);
}

char	*ft_itoa(int n)
{
	char	*output;
	size_t	length;
	int		i;

	length = check_len(n);
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	output = malloc(sizeof(char) * (length + 1));
	if (output == NULL)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		output[i++] = 45;
		length--;
	}
	while (length != 0)
	{
		output[i++] = (n / get_denom(length--) % 10) + 48;
	}
	output[i] = 0;
	return (output);
}
