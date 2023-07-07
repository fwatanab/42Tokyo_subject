#include "../inc/so_long.h"

int	put_window(int argc, char **argv)
{
	t_vars	vars;

	argc = 0;
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, 800, 600, "so_long");
	create_map(vars, argv);
	mlx_loop(vars.mlx);
	return (0);
}
