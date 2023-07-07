#include "../inc/so_long.h"
#include <stdio.h>

static t_path	*compare_map(void *mlx, char c)
{
	t_path	path;
	t_data	img;
	int		img_width;
	int		img_hight;

	path.player = "/Users/sukakaedefutoshi/ft_git/so_long/textures/hatiware.xpm";
	path.grass = "/Users/sukakaedefutoshi/ft_git/so_long/textures/grass.xpm";
	path.wood = "/Users/sukakaedefutoshi/ft_git/so_long/textures/wood.xpm";
	path.door = "/Users/sukakaedefutoshi/ft_git/so_long/textures/door.xpm";
	path.item = "/Users/sukakaedefutoshi/ft_git/so_long/textures/item.xpm";
	if (c == 'P')
		img.img = mlx_xpm_file_to_image(mlx, path.player, &img_width, &img_hight);
	if (c == '0')
		img.img = mlx_xpm_file_to_image(mlx, path.grass, &img_width, &img_hight);
	if (c == '1')
		img.img = mlx_xpm_file_to_image(mlx, path.wood, &img_width, &img_hight);
	if (c == 'E')
		img.img = mlx_xpm_file_to_image(mlx, path.door, &img_width, &img_hight);
	if (c == 'C')
		img.img = mlx_xpm_file_to_image(mlx, path.item, &img_width, &img_hight);
	if (img.img == NULL)
		error();
	return (img.img);
}

static void	put_map(void *mlx, void *mlx_win, char *line, size_t k)
{
	t_data	img;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
	{
		img.img = compare_map(mlx, line[i]);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
		mlx_put_image_to_window(mlx, mlx_win, img.img, j, k);
		j += 40;
		i++;
	}
}

void	create_map(void *mlx, void *mlx_win, char **argv)
{
	int		fd;
	char	*line;
	size_t	k;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error();
	line = get_next_line(fd);
	k = 0;
	while (line)
	{
		put_map(mlx, mlx_win, line, k);
		line = get_next_line(fd);
		k += 40;
	}
	close(fd);
}
