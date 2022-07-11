#include "../includes/fdf.h"

void	ft_error(char *message)
{
	if (message == 0)
		ft_putstr_fd("Error [Debug]\n", 1);
	else
		ft_putstr_fd(message, 1);
	exit (1);
}
