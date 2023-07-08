/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:24:18 by fwatanab          #+#    #+#             */
/*   Updated: 2023/07/08 14:43:22 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static t_vars	map_size(int fd)
{
	t_vars	vars;
	char	*line;
	size_t	x_size;
	size_t	y_size;
	size_t	tmp;

	line = get_next_line(fd);
	if (!line)
		error_map(fd);
	x_size = my_strnlen(line);
	y_size = 0;
	while (line)
	{
		tmp = my_strnlen(line);
		if (tmp != x_size)
			error_map(fd);
		line = get_next_line(fd);
		y_size++;
	}
	if (x_size == y_size)
		error_map(fd);
	vars.map_x = (int)x_size * 40;
	vars.map_y = (int)y_size * 40;
	return (vars);
}

int	put_window(char **argv)
{
	t_vars	vars;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error();
	vars = map_size(fd);
//	checker_map(fd);
	close(fd);
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, vars.map_x, vars.map_y, "so_long");
	create_map(vars, argv);
	mlx_loop(vars.mlx);
	return (0);
}
