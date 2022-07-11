#include "../includes/fdf.h"

int	keys(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_R \
		|| key == NUM_PAD_MINUS || key == MAIN_PAD_F)
		zoom(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT \
		|| key == ARROW_UP || key == ARROW_DOWN || \
		key == MAIN_PAD_W || key == MAIN_PAD_S || \
		key == MAIN_PAD_A || key == MAIN_PAD_D)
		movement_key(key, fdf);
	else if (key == MAIN_PAD_U || key == NUM_PAD_9 \
		|| key == MAIN_PAD_H || key == NUM_PAD_7 \
		|| key == MAIN_PAD_J || key == NUM_PAD_8 \
		|| key == MAIN_PAD_K || key == NUM_PAD_4 \
		|| key == MAIN_PAD_Y || key == NUM_PAD_6 \
		|| key == MAIN_PAD_I || key == NUM_PAD_5)
		rotate(key, fdf);
	else if (key == MAIN_PAD_Z || key == MAIN_PAD_X)
		view(key, fdf);
	else if (key == MAIN_PAD_LARR || key == MAIN_PAD_RARR)
		projection(key, fdf);
	return (0);
}
