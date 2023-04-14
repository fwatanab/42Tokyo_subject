NAME	= libftprintf.a

SRCS	= ft_printf.c put_print.c convert_ptr_hex.c unsigned_itoa.c put_hexadecimal.c\
ft_strlen.c ft_strdup.c ft_putchar_fd.c ft_putstr_fd.c ft_itoa.c ft_toupper.c ft_calloc.c ft_bzero.c

OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

$(NAME):$(OBJS)
		ar crs $(NAME) $(OBJS)

all:$(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all