//#include "../minitalk.h"
#include "../libft/libft.h"
#include <stdio.h>

int	binary_convertion(char *str)
{
	int	nbr;

	nbr = ft_atoi(str);
	return (nbr);
}

int	main()
{
	char	*str = "abc";
	int	nbr;

	nbr = *str;
//	nbr = binary_convertion("abc");
	printf("%d\n", nbr);
	return (0);
}
