#include "../inc/so_long.h"

int	put_window(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	*grass_path = "/Users/fwatanab/ft_git/so_long/textures/grass.xpm";
	char	*wood_path = "/Users/fwatanab/ft_git/so_long/textures/wood.xpm";
	char	*door_path = "/Users/fwatanab/ft_git/so_long/textures/door.xpm";
	char	*item_path = "/Users/fwatanab/ft_git/so_long/textures/item.xpm";
	char	*player_path = "/Users/fwatanab/ft_git/so_long/textures/hatiware.xpm";
	int		img_width;
	int		img_height;
	int		fd;
	size_t	i;
	size_t	j;
	size_t	k;
	char	*line;

	argc = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "so_long");
	k = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		j = 0;
		while (line[i])
		{
			ft_printf("--- %c\n", line[i]);
			if (line[i] == 'P')
				img.img = mlx_xpm_file_to_image(mlx, player_path, &img_width, &img_height);
			if (line[i] == '0')
				img.img = mlx_xpm_file_to_image(mlx, grass_path, &img_width, &img_height);
			if (line[i] == '1')
				img.img = mlx_xpm_file_to_image(mlx, wood_path, &img_width, &img_height);
			if (line[i] == 'E')
				img.img = mlx_xpm_file_to_image(mlx, door_path, &img_width, &img_height);
			if (line[i] == 'C')
				img.img = mlx_xpm_file_to_image(mlx, item_path, &img_width, &img_height);
			if (img.img == NULL)
				return (1);
			ft_printf("w %d\nh %d\n", img_width, img_height);
			img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
			mlx_put_image_to_window(mlx, mlx_win, img.img, j, k);
			i++;
			j += 40;
		}
		k += 40;
		line = get_next_line(fd);
	}
//	check_map(argc, argv);
	mlx_loop(mlx);
	return (0);
}
