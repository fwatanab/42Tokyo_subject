#include "../inc/so_long.h"

size_t	my_strnlen(const char *str)
{
	size_t	size;

	if (!str)
		error();
	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	return (size);
}

void	map_size(char **argv)
{
	t_vars	vars;
	int		fd;
	char	*line;
	size_t	x_size;
	size_t	y_size;
	size_t	tmp;

	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	x_size = my_strnlen(line);
	y_size = 0;
	while (line)
	{
		tmp = my_strnlen(line);
		ft_printf("line %s\n", line);
		ft_printf("tmp %d\n", tmp);
		if (tmp != x_size)
			error();
		line = get_next_line(fd);
		y_size++;
	}
	vars.map_x = (int)x_size * 40;
	vars.map_y = (int)y_size * 40;
	ft_printf("x %d\ny %d\n", vars.map_x, vars.map_y);
}

int	put_window(int argc, char **argv)
{
	t_vars	vars;

	argc = 0;
	map_size(argv);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, vars.map_x, vars.map_y
			, "so_long");
	create_map(vars, argv);
	mlx_loop(vars.mlx);
	return (0);
}
