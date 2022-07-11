#include "../includes/fdf.h"

void	pixel(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x >= MENU && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * fdf->pixel_bits / 8) + (y * fdf->line_bytes);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

static int	gradient(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = ft_percent(start.x, end.x, current.x);
	else
		percentage = ft_percent(start.y, end.y, current.y);
	red = gradient((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, \
					percentage);
	green = gradient((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, \
					percentage);
	blue = gradient(start.color & 0xFF, end.color & 0xFF, \
					percentage);
	return ((red << 16) | (green << 8) | blue);
}
