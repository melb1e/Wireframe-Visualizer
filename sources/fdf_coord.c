#include "../includes/fdf.h"

static void	put_to_array(t_coordinates *temp, t_map *map, size_t i)
{
	map->coordinates[i] = temp->z;
	map->colors[i] = temp->color;
	if (temp->z > map->z_max)
		map->z_max = temp->z;
	if (temp->z < map->z_min)
		map->z_min = temp->z;
}

void	stack_to_arrays(t_coordinates **stack, t_map *map)
{
	t_coordinates	*temp;
	int				i;
	size_t			map_size;

	map_size = map->width * map->height * sizeof(size_t);
	map->coordinates = (int *)malloc(map_size);
	if (!map->coordinates)
		ft_error(ERR_CONV_TO_ARR);
	map->colors = (int *)malloc(map_size);
	if (!map->colors)
		ft_error(ERR_CONV_TO_ARR);
	i = map->width * map->height - 1;
	temp = lst_v_pop(stack);
	while (temp && i >= 0)
	{
		put_to_array(temp, map, i);
		i--;
		free(temp);
		temp = lst_v_pop(stack);
	}
	map->z_range = map->z_max - map->z_min;
}
