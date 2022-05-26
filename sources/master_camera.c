/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:08:21 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/25 18:19:58 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

static void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

static void	set_base_view(int *x, int *y, int z, double zethos)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(zethos);
	*y = -z + (previous_x + previous_y) * sin(zethos);
}

t_point	project(t_point point, t_fdf *fdf)
{
	point.x *= fdf->camera->zoom;
	point.y *= fdf->camera->zoom;
	point.z *= fdf->camera->zoom / fdf->camera->z_divisor;
	point.x -= (fdf->map->width * fdf->camera->zoom) / 2;
	point.y -= (fdf->map->height * fdf->camera->zoom) / 2;
	rotate_x(&point.y, &point.z, fdf->camera->alpha);
	rotate_y(&point.x, &point.z, fdf->camera->beta);
	rotate_z(&point.x, &point.y, fdf->camera->gamma);
	if (fdf->camera->projection == 0)
		set_base_view(&point.x, &point.y, point.z, 0.5);
	point.x += (WIDTH - MENU) / 2 + fdf->camera->shift_x + MENU;
	point.y += (HEIGHT + fdf->map->height * fdf->camera->zoom) / 2 \
				+ fdf->camera->shift_y;
	return (point);
}
