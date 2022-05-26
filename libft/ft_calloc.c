/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:38:50 by mmarcele          #+#    #+#             */
/*   Updated: 2021/10/19 17:45:13 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_obj, size_t size)
{
	void	*pointer;

	pointer = malloc(num_obj * size);
	if (pointer == NULL)
	{
		return (pointer);
	}
	ft_bzero(pointer, num_obj * size);
	return (pointer);
}
