NAME	= so_long

SRCSDIR	= src/

SRCS = main.c graphic.c create_map.c error.c

OBJS	= $(addprefix $(SRCSDIR), $(SRCS:.c=.o))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
MLXFRAGS = -lX11 -lXext -lm

LIBFTDIR	= libft/
LIBFTNAME	= libft.a
MLXDIR		= minilibx/
MLXNAME		= libmlx.a

$(NAME):$(OBJS)
	$(MAKE) -C $(LIBFTDIR)
#	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft # -L$(MLXDIR) -lmlx $(MLXFRAGS)

all:$(NAME)

.c.o:
	$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

$(MLXDIR)$(MLXNAME):
	$(MAKE) -C $(MLXDIR)

$(LIBFTDIR)$(LIBFTNAME):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MLXDIR) fclean


re: fclean all
