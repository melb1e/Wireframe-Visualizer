#include "../includes/fdf.h"

static void	view(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x - *y) * cos(angle) - z;
}

static void	set_color(float x, float y, float ix, float iy, t_fdf *matrix)
{
	int		z;
	int		iz;

	z = matrix->z_matrix[(int)y][(int)x];
	iz = matrix->z_matrix[(int)iy][(int)ix];
	if (z || iz)
		matrix->color = 0xe80c0c;
	else
		matrix->color = 0xffffff;
}

static void	set_view(float x, float y, float ix, float iy, t_fdf *matrix)
{
	int		z;
	int		iz;

	z = matrix->z_matrix[(int)y][(int)x];
	iz = matrix->z_matrix[(int)iy][(int)ix];
	view(&x, &y, z, matrix->iso_angle);
	view(&ix, &iy, iz, matrix->iso_angle);
}

static void	line(float x, float y, float ix, float iy, t_fdf *matrix)
{
	int		max;
	float	step_x;
	float	step_y;
	int		z;
	int		iz;

	
	set_color(x, y, ix, iy, matrix);
	set_view(x, y, ix, iy, matrix);
	x += matrix->shift_x;
	y += matrix->shift_y;
	ix += matrix->shift_x;
	iy += matrix->shift_y;
	step_x = ix - x;
	step_y = iy - y;
	max = max(mod(step_x), mod(step_y));
	step_x /= max;
	step_y /= max;
	while ((int)(x - ix) || (int)(y - iy))
	{
		mlx_pixel_put(matrix->mlx_ptr, matrix->width, x, y, matrix->color);
		x += step_x;
		y += step_y;
	}
}

void	map(t_fdf *m)
{
	int	x;
	int	y;

	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (y < m->width)
		{
			if (x < m->height - 1)
				line(x * m->zoom, y * m->zoom, x * m->zoom, \
				(y + 1) * m->zoom, m);
			if (x < m->width - 1)
				line(x * m->zoom, y * m->zoom, (x + 1) * m->zoom, \
				y * m->zoom, m);
			x++;
		}
		y++;
	}
}
