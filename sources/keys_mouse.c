#include "../includes/fdf.h"

int	press_mouse(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == LMB || button == RMB)
	{
		if (button == LMB)
			fdf->mouse->lmb_pressed = 1;
		else
			fdf->mouse->rmb_pressed = 1;
	}
	return (0);
}

int	unpress_mouse(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->lmb_pressed = 0;
	fdf->mouse->rmb_pressed = 0;
	return (0);
}

int	move_coursor(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->previous_x = fdf->mouse->x;
	fdf->mouse->previous_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->lmb_pressed)
	{
		fdf->camera->beta += (x - fdf->mouse->previous_x) * 0.002;
		fdf->camera->alpha += (y - fdf->mouse->previous_y) * 0.002;
		master(fdf->map, fdf);
	}
	else if (fdf->mouse->rmb_pressed)
	{
		fdf->camera->shift_x += x - fdf->mouse->previous_x;
		fdf->camera->shift_y += y - fdf->mouse->previous_y;
		master(fdf->map, fdf);
	}
	return (0);
}
