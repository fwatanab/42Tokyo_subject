#include "../inc/so_long.h"
#include <stdio.h>///////////////////////////////

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	put_window(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	char	*relative_path = "/Users/sukakaedefutoshi/ft_git/so_long/textures/maps.xpm";
	int		img_width;
	int		img_height;
	char	*str = "/Users/sukakaedefutoshi/ft_git/so_long/maps/map.ber";
	size_t	i;
	size_t	j;
	size_t	k;
//	char	line[96][] = 

	argc = 0;
	argv = NULL;
	mlx = mlx_init();
	img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	mlx_win = mlx_new_window(mlx, img_width, img_height, "so_long");
	if (img.img == NULL)
		return (1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	i = 0;
	j = 4;
	k = 0;
	while (str[i])
	{
		if (k == 96)
		{
			j += 4;
			k = 0;
		}
		else
		{
			mlx_string_put(mlx, mlx_win, k, j, 0, &str[i]);
			k++;
			i++;
		}
	}
//	check_map(argc, argv);
	mlx_loop(mlx);
	return (0);
}
