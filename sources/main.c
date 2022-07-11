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
	mlx_string_put(mlxx, winn, x, y += 20, TEXT_COLOR, "FDF");
	mlx_string_put(mlxx, winn, x, y += 35, TEXT_COLOR, "Zoom: R / F");
	mlx_string_put(mlxx, winn, x, y += 30, TEXT_COLOR, "Tip: use scroll wheel");
	mlx_string_put(mlxx, winn, x, y += 30, TEXT_COLOR, "Move: Arrows or WASD");
	mlx_string_put(mlxx, winn, x, y += 30, TEXT_COLOR, "Tip: try using LMB");
	mlx_string_put(mlxx, winn, x, y += 30, TEXT_COLOR, "Angle: YUIHJK or 789456");
	mlx_string_put(mlxx, winn, x, y += 30, TEXT_COLOR, "Tip: try using RMB");
	mlx_string_put(mlxx, winn, x, y += 25, TEXT_COLOR, "Axis X - U/J/5/8");
	mlx_string_put(mlxx, winn, x, y += 25, TEXT_COLOR, "Axis Y - K/H/4/6");
	mlx_string_put(mlxx, winn, x, y += 25, TEXT_COLOR, "Axis Z - Y/I/7/9");
	mlx_string_put(mlxx, winn, x, y += 30, TEXT_COLOR, "Change elevation: Z / X");
	mlx_string_put(mlxx, winn, x, y += 30, TEXT_COLOR, "Change elevation: Z / X");
	mlx_string_put(mlxx, winn, x, y += 30, TEXT_COLOR, "Projection");
	mlx_string_put(mlxx, winn, x, y += 25, TEXT_COLOR, "ISO: < Key");
	mlx_string_put(mlxx, winn, x, y += 25, TEXT_COLOR, "Parallel: > Key");
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
