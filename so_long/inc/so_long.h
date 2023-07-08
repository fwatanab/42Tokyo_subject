#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
//# include <mlx.h>
# include <fcntl.h>

# define P_IMG_PLAYER  "textures/player.xpm"
# define P_IMG_GRASS  "textures/grass.xpm"
# define P_IMG_WOOD  "textures/wood.xpm"
# define P_IMG_DOOR  "textures/door.xpm"
# define P_IMG_ITEM  "textures/item.xpm"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	int		map_x;
	int		map_y;
}	t_vars;

int		put_window(int argc, char **argv);
void	create_map(t_vars vars, char **argv);
void	error(void);

#endif
