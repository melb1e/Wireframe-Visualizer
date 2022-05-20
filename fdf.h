#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		color;

	int		shift_x;
	int		shift_y;
	float	iso_angle;

	void	*mlx_ptr;
	void	*win_ptr;
}       	t_fdf;

/*
** Analyze the file, read the map and save it.
*/
void	file_read(t_fdf *matrix);

/*
** Utils
*/
float	mod(float a, float b);
float	max(float a, float b);

/*
** Process and create the map.
*/
/*
** static void	line(float x, float y, float ix, float iy, t_fdf *data);
*/
void	map(t_fdf *matrix);

/*
** Movement key
*/
int	keys(int key, t_fdf *matrix);

/*
** 
*/

/*
** 
*/

#endif
