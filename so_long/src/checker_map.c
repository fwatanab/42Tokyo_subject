/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:28:00 by fwatanab          #+#    #+#             */
/*   Updated: 2023/07/08 14:42:35 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static size_t	check_map_nbr(char *line, char c)
{
	size_t	i;
	size_t	frag;

	i = 0;
	frag = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == c)
			frag++;
		i++;
	}
	return (frag);
}

void	checker_map(char **argv)
{
	int		fd;
	char	*line;
	size_t	p_size;
	size_t	c_size;
	size_t	e_size;

	p_size = 0;
	c_size = 0;
	e_size = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error();
	line = get_next_line(fd);
	while (line)
	{
		p_size += check_map_nbr(line, 'P');
		c_size += check_map_nbr(line, 'C');
		e_size += check_map_nbr(line, 'E');
		line = get_next_line(fd);
	}
	if (p_size != 1 || c_size <= 0 || e_size != 1)
		error_map(fd);
	close(fd);
}
