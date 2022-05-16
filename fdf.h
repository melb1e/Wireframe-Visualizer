#ifndef FDF_H
# define FDF_H

typedef struct s_fdf
{
  int    width;
  int   height;
  int   **matrix;
  
  void  *mlx_ptr;
  void  *win_ptr;
}       t_fdf;

#endif
