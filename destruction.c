#include "../includes/fdf.h"

void	ft_error(char *message)
{
	ft_printf("%s\n", message);
	exit (1);
}

void	destruction(t_fdf matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (matrix->z_matrix[i])
	{
		while (matrix->z_matrix[i][j])
		{
			free(matrix->z_matrix[i][j]);
			j++;
		}
		free(matrix->z_matrix[i]);
		i++
	}
	free(matrix);
}
