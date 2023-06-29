#include "../minitalk.h"
#include <stdio.h>

void	argv_print(char *argv)
{
	printf("%s\n", argv);
}

int main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	signal(SIGUSR1, argv_print);
	kill((pid_t)ft_atoi(argv[1]), SIGUSR1);
	return (0);
}

