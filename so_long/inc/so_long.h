#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
//# include "../minilibx/mlx.h"
//# include "../minilibx/mlx_int.h"
# include <mlx.h>
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
	int		pixel;
	int		len;
	int		end;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	int		map_x;
	int		map_y;
}	t_vars;

int		put_window(char **argv);
void	create_map(t_vars vars, char **argv);
void	error(void);
void	error_map(int fd);
size_t	my_strnlen(const char *str);
void	checker_map(char **argv, t_vars vars);

#endif
