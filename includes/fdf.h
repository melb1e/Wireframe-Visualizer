/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarcele <mmarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 13:20:00 by mmarcele          #+#    #+#             */
/*   Updated: 2022/05/25 18:44:22 by mmarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

# define ERR_USE			"Error 101 [Usage], try ./fdf [map name].\n"
# define ERR_READ			"Error 102 [Reading], invalid map or permissions.\n"
# define ERR_MALLOC			"Error 103 [Malloc], invalid map or not enough \
					space on device.\n"
# define ERR_MAP_INIT		"Error 104 [Initialization], invalid map or not enough \
					space on device.\n"
# define ERR_MAP_READ		"Error 105 [Reading], invalid map or permissions.\n"
# define ERR_FDF_INIT		"Error 106 [FDF Initialization], invalid map or not \
					enough space on device.\n"
# define ERR_CONV_TO_ARR	"Error 107 [Stack coversion], something went \
						wrong with array conversion.\n"
# define ERR_CAMERA_INIT	"Error 106 [Camera Initialization], invalid map or not \
					enough space on device.\n"

/*
** Default window
*/
# define WINDOW_NAME		"FdF"

/*
** Default window
*/
# define WIDTH				1920
# define HEIGHT				1080
# define MENU				250

/*
** Lazy values
*/
# define Z_MAX				0
# define Z_MIN				0

/*
** Color
*/
# define BACKGROUND 		0x696969
# define MENU_BACKGROUND	0x383838
# define DARKEST 			0x8427db
# define DARK 				0xb38bd9
# define MEDIUM 			0x8ba1d9
# define LIGHT				0x8bc4d9
# define LIGHTEST			0x8bd99b
# define TEXT_COLOR			0xf5ebe0

/*
** Zoom
*/
# define NUM_PAD_PLUS		69
# define NUM_PAD_MINUS		78
# define MAIN_PAD_R			15
# define MAIN_PAD_F			3

/*
** Exit
*/
# define MAIN_PAD_ESC		53

/*
** Projection
*/
# define MAIN_PAD_LARR		43
# define MAIN_PAD_RARR		47

/*
** Moveement keys
*/
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define MAIN_PAD_W			13
# define MAIN_PAD_S			1
# define MAIN_PAD_A			0
# define MAIN_PAD_D			2

/*
** Flatten map
*/
# define MAIN_PAD_Z			6	
# define MAIN_PAD_X			7

/*
** Moveement keys
*/
# define MAIN_PAD_U			32
# define MAIN_PAD_H			4
# define MAIN_PAD_J			38
# define MAIN_PAD_K			40
# define NUM_PAD_8			91
# define NUM_PAD_4			86
# define NUM_PAD_5			87
# define NUM_PAD_6			88
# define MAIN_PAD_Y			16
# define MAIN_PAD_I			34
# define NUM_PAD_7			89
# define NUM_PAD_9			92

/*
** Mouse controls
*/
# define LMB				1
# define RMB				2
# define SCROLL_UP			4
# define SCROLL_DOWN		5

typedef struct s_mouse
{
	int						x;
	int						y;
	int						previous_x;
	int						previous_y;
	int						lmb_pressed;
	int						rmb_pressed;
}							t_mouse;

typedef struct s_point
{
	int						x;
	int						y;
	int						z;
	int						color;
}							t_point;

typedef struct s_line
{
	t_point					d;
	t_point					s;
	t_point					c;
	int						math_error[2];
}							t_line;

typedef struct s_camera
{
	int						projection;
	int						zoom;
	double					alpha;
	double					beta;
	double					gamma;
	float					z_divisor;
	int						shift_x;
	int						shift_y;
}							t_camera;

typedef struct s_coordinates
{
	int						z;
	int						color;
	struct s_coordinates	*next;
}							t_coordinates;

typedef struct s_map
{
	int						width;
	int						height;
	int						*colors;
	int						*coordinates;
	int						z_min;
	int						z_max;
	int						z_range;
}							t_map;

typedef struct s_fdf
{
	void					*mlx;
	void					*win;
	void					*image;
	char					*data_addr;
	int						line_bytes;
	int						pixel_bits;
	int						endian;
	t_map					*map;
	t_camera				*camera;
	t_mouse					*mouse;
}							t_fdf;

/*
** Initialization
*/
t_map						*init_map(void);
t_fdf						*init_fdf(t_map *map);
t_camera					*init_camera(t_fdf *fdf);

/*
** Read map and fill arrays with coordinates and colors
*/
int							read_map(int fd, t_coordinates **stack, t_map *map);
void						stack_to_arrays(t_coordinates **stack, t_map *map);

/*
** Draw everything, master of creation (background & lines).
*/
void						master(t_map *map, t_fdf *fdf);
void						create_background(t_fdf *fdf);
void						create_line(t_point f, t_point s, t_fdf *fdf);
void						print_menu(t_fdf *fdf);
int							get_color(t_point current, t_point start, t_point \
								end, t_point delta);
void						pixel(t_fdf *fdf, int x, int y, int color);

/*
** Camera position and setting.
*/
t_point						project(t_point point, t_fdf *fdf);

/*
** Analyze the file, read the map and save it.
*/
void						file_read(char *file, t_fdf *matrix);

/*
** Utils
*/
void						lst_v_push(t_coordinates **stack, \
										t_coordinates *new);
t_coordinates				*lst_v_pop(t_coordinates **stack);

/*
** Movement key
*/
int							keys(int key, void *param);
void						movement_key(int key, t_fdf *fdf);
void						rotate(int key, t_fdf *fdf);
void						zoom(int key, t_fdf *fdf);
void						view(int key, t_fdf *fdf);
void						projection(int key, t_fdf *fdf);
int							move_coursor(int x, int y, void *param);
int							unpress_mouse(int button, int x, int y, \
											void *param);
int							press_mouse(int button, int x, int y, void *param);

/*
** Errors
*/
void						ft_error(char *message);

#endif
/*
** !FDF_H
*/
