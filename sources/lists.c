/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 12:53:55 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/25 18:44:42 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	lst_v_push(t_coordinates **stack, t_coordinates *new)
{
	if (stack)
	{
		if (new)
			new->next = *stack;
		*stack = new;
	}
}

t_coordinates	*lst_v_pop(t_coordinates **stack)
{
	t_coordinates	*top;

	top = NULL;
	if (stack && *stack)
	{
		top = *stack;
		*stack = (*stack)->next;
	}
	return (top);
}
