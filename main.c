#include "fdf.h"

int get_height(char *file)
{
  int   fd;
  int   height;
  char  *line;
  
  fd = open(file, O_RDONLY, 0);
  heihgt = 0;
  while(get_next_line(fd, &line))
  {
    height++;
    free(line);
  }
  close(fd);
  return (height);
}

int get_width(char *file)
{
  int   fd;
  int   width;
  char  *line;
  
  fd = open(file, O_RDONLY, 0);
  width = 0;
  get_next_line(fd, &line);
  width = ft_wcount(line, ' ');
  free(line);
  close(fd);
  return (height);
}

void  matrix_fill(int *m_line, char *line)
{
  int   i;
  char  **values;
  
  values = ft_strsplit(line, ' ');
  i = 0;
  while (nums[i])
  {
    m_line[i] = ft_atoi(nums[i]);
    free(values[i]);
    i++;
  }
  free(values);
}

void  file_read(t_fdf *matrix)
{
  int   i;
  int   fd;
  chat  *line;

  i = 0;
  data->height = get_height(file);
  data->width = get_width(file);
  data->matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
  while (i < data->height)
    data->matrix[i] = (int *)malloc(sizeof(int) * (data->width + 1));
  fd = open(file, O_RDONLY, 0);
  i = 0;
  while (get_next_line(fd, &line))
  {
    fill_matrix(data->matrix[i], line);
    free(line);
    i++;
  }
  data->matrix[i] = NULL;
}

int		main(int argc, char **argv)
{
  t_fdf **matrix;

	if (argc != 2)
		ft_error("usage: ./fdf [map name]");
  matrix = (t_ftf *)malloc(sizeof(fdf));
  file_read(matrix);
  
	matrix = read_map(*++argv);
	set_default(&PRM);
	draw(matrix);
	mlx_key_hook(PRM.win_ptr, deal_key, matrix);
	mlx_loop(PRM.mlx_ptr);
}
