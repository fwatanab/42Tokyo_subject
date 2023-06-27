NAME	= push_swap

SRCSDIR	= src/

SRCS	= main.c push_swap.c check_error.c free.c list.c list_utils.c sort.c swap_command.c push_command.c\
rotate_command.c reverse_rotate_command.c sort_utils.c sort_below_5.c quick_sort.c quick_sort_utils.c\
quick_sort_utils_sort.c list_group_utils.c print_list.c

OBJS	= $(addprefix $(SRCSDIR), $(SRCS:.c=.o))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

LIBFTDIR = libft/
LIBFTNAME = libft.a

$(NAME):$(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft

all:$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

libft/$(LIBFTNAME):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean


re: fclean all
