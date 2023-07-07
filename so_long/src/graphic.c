#include "../inc/so_long.h"

int	put_window(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;

	argc = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "so_long");
	create_map(mlx, mlx_win, argv);
	mlx_loop(mlx);
	return (0);
}
