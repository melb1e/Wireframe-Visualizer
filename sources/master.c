#include "../includes/fdf.h"

void	create_line(t_point start, t_point end, t_fdf *fdf)
{
	t_line	*pos;

	pos = (t_line *)malloc(sizeof(t_line));
	pos->d.x = ft_mod(end.x - start.x);
	pos->d.y = ft_mod(end.y - start.y);
	pos->s.x = ft_sign(start.x, end.x);
	pos->s.y = ft_sign(start.y, end.y);
	pos->math_error[0] = pos->d.x - pos->d.y;
	pos->c = start;
	while (pos->c.x != end.x || pos->c.y != end.y)
	{
		pixel(fdf, pos->c.x, pos->c.y, get_color(pos->c, start, end, pos->d));
		pos->math_error[1] = pos->math_error[0] * 2;
		if (pos->math_error[1] > -pos->d.y)
		{
			pos->math_error[0] -= pos->d.y;
			pos->c.x += pos->s.x;
		}
		if (pos->math_error[1] < pos->d.x)
		{
			pos->math_error[0] += pos->d.x;
			pos->c.y += pos->s.y;
		}
	}
	free(pos);
}

void	create_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->pixel_bits / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		if (i % WIDTH < MENU)
			image[i] = MENU_BACKGROUND;
		else
			image[i] = BACKGROUND;
		i++;
	}
}

static int	default_color(int z, t_map *map)
{
	double	percentage;

	percentage = ft_percent(map->z_min, map->z_max, z);
	if (percentage < 0.2)
		return (LIGHTEST);
	else if (percentage < 0.4)
		return (LIGHT);
	else if (percentage < 0.6)
		return (MEDIUM);
	else if (percentage < 0.8)
		return (DARK);
	else
		return (DARKEST);
}

static t_point	new_point(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = ft_find_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coordinates[index];
	if (map->colors[index] == -1)
		point.color = default_color(point.z, map);
	else
		point.color = map->coordinates[index];
	return (point);
}

void	master(t_map *map, t_fdf *fdf)
{
	int	x;
	int	y;

	create_background(fdf);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != fdf->map->width - 1)
				create_line(project(new_point(x, y, map), fdf),
					project(new_point(x + 1, y, map), fdf), fdf);
			if (y != fdf->map->height - 1)
				create_line(project(new_point(x, y, map), fdf),
					project(new_point(x, y + 1, map), fdf), fdf);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->image, 0, 0);
	print_menu(fdf);
}
