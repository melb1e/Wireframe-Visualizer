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
