/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:52:13 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/26 20:38:16 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_menu(t_fdf *fdf)
{
	int		y;
	int		x;
	void	*mlxx;
	void	*winn;

	y = 5;
	x = 5;
	mlxx = fdf->mlx;
	winn = fdf->win;
	mlx_string_put(mlxx, winn, x, y += 20, 0xf5ebe0, "FDF");
	mlx_string_put(mlxx, winn, x, y += 35, 0xf5ebe0, "Zoom: R / F");
	mlx_string_put(mlxx, winn, x, y += 30, 0xf5ebe0, "Move: Arrows or WASD");
	mlx_string_put(mlxx, winn, x, y += 30, 0xf5ebe0, "Angle: YUIHJK or 789456");
	mlx_string_put(mlxx, winn, x, y += 25, 0xf5ebe0, "X-Axis - U/J/5/8");
	mlx_string_put(mlxx, winn, x, y += 25, 0xf5ebe0, "Y-Axis - K/H/4/6");
	mlx_string_put(mlxx, winn, x, y += 25, 0xf5ebe0, "Z-Axis - Y/I/7/9");
	mlx_string_put(mlxx, winn, x, y += 30, 0xf5ebe0, "Change elevation: Z / X");
	mlx_string_put(mlxx, winn, x, y += 30, 0xf5ebe0, "Projection");
	mlx_string_put(mlxx, winn, x, y += 25, 0xf5ebe0, "ISO: < Key");
	mlx_string_put(mlxx, winn, x, y += 25, 0xf5ebe0, "Parallel: > Key");
}

static int	close_all(void *param)
{
	(void)param;
	exit (0);
}

static void	controls_settings(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, keys, fdf);
	mlx_hook(fdf->win, 4, 0, press_mouse, fdf);
	mlx_hook(fdf->win, 5, 0, unpress_mouse, fdf);
	mlx_hook(fdf->win, 6, 0, move_coursor, fdf);
	mlx_hook(fdf->win, 17, 0, close_all, fdf);
}

int	main(int argc, char **argv)
{
	t_fdf			*fdf;
	t_map			*map;
	t_coordinates	*stack;
	int				fd;

	if (argc != 2)
		ft_error(ERR_USE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(ERR_MAP_READ);
	map = init_map();
	if (read_map(fd, &stack, map) == -1)
		ft_error(ERR_MAP_READ);
	close(fd);
	fdf = init_fdf(map);
	stack_to_arrays(&stack, map);
	fdf->camera = init_camera(fdf);
	master(fdf->map, fdf);
	controls_settings(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
