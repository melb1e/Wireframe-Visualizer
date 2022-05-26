/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:57:39 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/25 14:13:13 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	movement_key(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT || key == MAIN_PAD_A)
		fdf->camera->shift_x -= 10;
	else if (key == ARROW_RIGHT || key == MAIN_PAD_D)
		fdf->camera->shift_x += 10;
	else if (key == ARROW_UP || key == MAIN_PAD_W)
		fdf->camera->shift_y -= 10;
	else
		fdf->camera->shift_y += 10;
	master(fdf->map, fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_U || key == NUM_PAD_8)
		fdf->camera->alpha += 0.05;
	else if (key == MAIN_PAD_J || key == NUM_PAD_5)
		fdf->camera->alpha -= 0.05;
	else if (key == MAIN_PAD_H || key == NUM_PAD_4)
		fdf->camera->beta -= 0.05;
	else if (key == MAIN_PAD_K || key == NUM_PAD_6)
		fdf->camera->beta += 0.05;
	else if (key == MAIN_PAD_I || key == NUM_PAD_9)
		fdf->camera->gamma += 0.05;
	else if (key == MAIN_PAD_Y || key == NUM_PAD_7)
		fdf->camera->gamma -= 0.05;
	master(fdf->map, fdf);
	return ;
}

void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_MINUS || key == MAIN_PAD_F || \
		key == SCROLL_UP)
		fdf->camera->zoom--;
	else if (key == NUM_PAD_PLUS || key == MAIN_PAD_R || \
		key == SCROLL_DOWN)
		fdf->camera->zoom++;
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	master(fdf->map, fdf);
	return ;
}

void	view(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_Z)
		fdf->camera->z_divisor -= 0.1;
	else if (key == MAIN_PAD_X)
		fdf->camera->z_divisor += 0.1;
	if (fdf->camera->z_divisor < 0.1)
		fdf->camera->z_divisor = 0.1;
	else if (fdf->camera->z_divisor > 10)
		fdf->camera->z_divisor = 10;
	master(fdf->map, fdf);
	return ;
}

void	projection(int key, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (key == MAIN_PAD_LARR)
		fdf->camera->projection = 0;
	else
		fdf->camera->projection = 1;
	master(fdf->map, fdf);
	return ;
}
