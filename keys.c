#include "../includes/fdf.h"

static int	movement_key(int key, t_fdf *matrix)
{
	mlx_clear_window(matrix->mlx_ptr, matrix->win_ptr);
	if (key == 13 || key == 126)
		matrix->shift_y += 10;
	else if (key == 0 || key == 123)
		matrix->shift_x -= 10;
	else if (key == 1 || key == 125)
		matrix->shift_y -= 10;
	else if (key == 2 || key == 124)
		matrix->shift_x += 10;
	else if (key == 12)
		matrix->iso_angle -= 10;
	else if (key == 14)
		matrix->iso_angle += 10;
	return (matrix);
}

static int	zoom(int key, t_fdf *matrix)
{
	mlx_clear_window(matrix->mlx_ptr, matrix->win_ptr);
	if (key == 15)
		matrix->zoom += 10;
	else if (key == 3)
		matrix->zoom -= 10;
	else if (key == 6)
		matrix->iso_angle += 0.05;
	else if (key == 7)
		matrix->iso_angle -= 0.05;
	return (matrix);
}

static int	view(int key, t_fdf *matrix)
{
	mlx_clear_window(matrix->mlx_ptr, matrix->win_ptr);
	if (key == 34)
		matrix->iso_angle = 0;
	else if (key == 35)
		matrix->iso_angle = 0.5;
	else if (key == 257)
	{
		matrix->iso_angle = 0.5;
		matrix->shift_y = 0;
		matrix->shift_x = 0;
		matrix->zoom = 20;
	}
	return (matrix);
}

int	keys(int key, t_fdf *matrix)
{
	if (key == 13 || key == 126 || key == 0 || key == 123 || key == 1 || \
		key == 2 || key == 125 || key == 124 || key == 12 || key == 14)
		matrix = movement_key(key, matrix);
	else if (key == 53)
	{
		mlx_destroy_window(matrix->mlx_ptr, matrix->win_ptr);
		destruction(matrix);
		exit(0);
	}
	else if (key == 15 || key == 3 || key == 6 || key == 7)
		matrix = zoom(key, matrix);
	else if (key == 34 || key == 35 || key == 257)
		matrix = view(key, matrix);
	mlx_clear_window(matrix->mlx_ptr, matrix->win_ptr);
	map(matrix);
	return (0);
}
