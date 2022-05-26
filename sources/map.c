/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:00:08 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/25 18:55:46 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_coordinates	*create_coordinate(char *string)
{
	t_coordinates	*stack;
	char			**parts;

	stack = (t_coordinates *)malloc(sizeof(t_coordinates));
	if (!stack)
		ft_error(ERR_MAP_READ);
	parts = ft_split(string, ',');
	if (!parts)
		ft_error(ERR_MAP_READ);
	if (!ft_isnumber(parts[0], 10))
		ft_error(ERR_MAP_READ);
	if (parts[1] && !ft_isnumber(parts[1], 16))
		ft_error(ERR_MAP_READ);
	stack->z = ft_atoi(parts[0]);
	if (parts[1])
		stack->color = ft_atoi_base(parts[1], 16);
	else
		stack->color = -1;
	stack->next = NULL;
	ft_free_arr(parts);
	return (stack);
}

static void	read_line(char **coordinates_line, t_coordinates **stack, \
						t_map *map)
{
	int	width;

	width = 0;
	while (*coordinates_line)
	{
		lst_v_push(stack, create_coordinate(*(coordinates_line)));
		coordinates_line++;
		width += 1;
	}
	if (map->height == 0)
	{
		map->width = width;
	}
	else if (map->width != width)
		ft_error(ERR_MAP_READ);
}

int	read_map(const int fd, t_coordinates **stack, t_map *map)
{
	char	*line;
	char	**coordinates_line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		coordinates_line = ft_split(line, ' ');
		if (!coordinates_line)
			ft_error(ERR_MAP_READ);
		read_line(coordinates_line, stack, map);
		ft_free_arr(coordinates_line);
		ft_strdel(&line);
		map->height++;
	}
	if (!(*stack))
		ft_error(ERR_MAP_READ);
	return ((int)line);
}
