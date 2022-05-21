#include "../includes/fdf.h"

static void	print_menu(t_fdf *matrix)
{
	int		y;
	int		x;
	void	*mlx;
	void	*win;

	y = 0;
	x = 20;
	mlx = matrix->mlx_ptr;
	win = matrix->win_ptr;
	mlx_string_put(mlx, win, 65, x, y += 20, 0xf5ebe0, \
					"How to use this programm");
	mlx_string_put(mlx, win, 15, x, y += 35, 0xf5ebe0, \
					"Zoom: R / F");
	mlx_string_put(mlx, win, 15, x, y += 30, 0xf5ebe0, \
					"Move: Arrows or WASD");
	mlx_string_put(mlx, win, 15, x, y += 30, 0xf5ebe0, \
					"Flatten: Shift");
	mlx_string_put(mlx, win, 15, x, y += 30, 0xf5ebe0, \
					"Isometric rotatation: Q / E");
	mlx_string_put(mlx, win, 15, x, y += 30, 0xf5ebe0, \
					"Change angle: Z / X");
	mlx_string_put(mlx, win, 15, x, y += 30, 0xf5ebe0, \
					"Projection");
	mlx_string_put(mlx, win, 57, x, y += 25, 0xf5ebe0, \
					"ISO: I Key");
	mlx_string_put(mlx, win, 57, x, y += 25, 0xf5ebe0, \
					"Parallel: P Key");
}

static t_fdf	default(t_fdf m)
{
	m.color = 0xffffff;
	m.height = 0;
	m.iso_angle = 0.5;
	m.shift_x = 150;
	m.shift_y = 150;
	m.z_matrix = 0;
	m.zoom = 20;
	m.width = 0;
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(matrix->mlx_ptr, 1000, 1000, "FDF - Fil de fer");
	return (m);
}

int		main(int argc, char **argv)
{
	t_fdf	*matrix;

	if (argc != 2)
		ft_error("Error: please, use this programm correctly (./fdf [map name])\n");
	matrix = (t_fdf *)malloc(sizeof(t_fdf));
	if (!matrix)
		ft_error("Error: unexpected error with malloc.\n")
	file_read(argv[1], matrix);
	matrix = default(matrix);
	print_menu(matrix);
	map(matrix);
	mlx_key_hook(matrix->win_ptr, deal_key, matrix);
	mlx_loop(matrix->mlx_ptr);
}
