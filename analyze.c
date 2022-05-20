#include "fdf.h"

static int	get_height(char *file)
{
	int		fd;
	int		height;
	char	*line;

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

static int	get_width(char *file)
{
	int		fd;
	int		width;
	char	*line;

	fd = open(file, O_RDONLY, 0);
	width = 0;
	get_next_line(fd, &line);
	width = ft_wcount(line, ' ');
	free(line);
	close(fd);
	return (height);
}

static void	matrix_fill(int *z_line, char *line)
{
	int		i;
	char	**values;

	values = ft_strsplit(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(values[i]);
		i++;
	}
	free(values);
}

void  file_read(char *file, t_fdf *matrix)
{
	int   i;
	int   fd;
	chat  *line;

	i = 0;
	matrix->height = get_height(file);
	matrix->width = get_width(file);
	matrix->z_matrix = (int **)malloc(sizeof(int *) * (matrix->height + 1));
	while (i < matrix->height)
		matrix->z_matrix[i] = (int *)malloc(sizeof(int) * (matrix->width + 1));
	fd = open(file, O_RDONLY, 0);
	if (fd <= 0)
		ft_error("Error: file does not exist or not enouth permissions.\n")
	i = 0;
	while (get_next_line(fd, &line))
	{
		fill_matrix(matrix->z_matrix[i], line);
		free(line);
		i++;
	}
	matrix->z_matrix[i] = NULL;
	close (fd);
}
