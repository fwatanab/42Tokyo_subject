#include "../inc/so_long.h"

void	error_map(int fd)
{
	ft_printf("error\n");
	close(fd);
	exit(1);
}

void	error(void)
{
	ft_printf("error\n");
	exit(1);
}
