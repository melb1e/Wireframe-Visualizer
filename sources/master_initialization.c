#include "../includes/fdf.h"

t_camera	*init_camera(t_fdf *fdf)
{
	t_camera	*camera;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		ft_error(ERR_CAMERA_INIT);
	camera->zoom = ft_min((WIDTH - MENU) / fdf->map->width / 2, \
							HEIGHT / fdf->map->height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->shift_x = 0;
	camera->shift_y = 0;
	camera->projection = 0;
	return (camera);
}

t_fdf	*init_fdf(t_map *map)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		ft_error(ERR_FDF_INIT);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		ft_error(ERR_FDF_INIT);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	if (!fdf->win)
		ft_error(ERR_FDF_INIT);
	fdf->image = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->image)
		ft_error(ERR_FDF_INIT);
	fdf->data_addr = mlx_get_data_addr(fdf->image, &(fdf->pixel_bits), \
										&(fdf->line_bytes), &(fdf->endian));
	fdf->map = map;
	fdf->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!fdf->mouse)
		ft_error(ERR_FDF_INIT);
	fdf->mouse->lmb_pressed = 0;
	fdf->mouse->rmb_pressed = 0;
	return (fdf);
}

t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		ft_error(ERR_MAP_INIT);
	map->height = 0;
	map->colors = NULL;
	map->width = 0;
	map->coordinates = NULL;
	map->z_min = Z_MIN;
	map->z_max = Z_MAX;
	map->z_range = 0;
	return (map);
}
