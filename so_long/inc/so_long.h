#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

# include "../libft/libft.h"
//# include "../minilibx/mlx.h"
//# include "../minilibx/mlx_int.h"
# include <mlx.h>
# include <fcntl.h>

int	put_window(int argc, char **argv);

#endif
