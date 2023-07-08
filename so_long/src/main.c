#include "../inc/so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		error();
	put_window(argv);
	return (0);
}
