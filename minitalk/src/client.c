/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 21:10:27 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/30 10:29:38 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	push_message(int pid, int nbr, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = ft_itoa(nbr);
	size = 8 - size;
	while (size)
	{
		kill(pid, SIGUSR1);
		size--;
		usleep(100);
	}
	while (str[i])
	{
		if (str[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
	free(str);
}

void	binary_conversion(int pid, char c)
{
	int		tmp;
	int		nbr;
	int		base;
	size_t	size;

	tmp = c;
	nbr = 0;
	base = 1;
	size = 0;
	while (tmp)
	{
		nbr = nbr + (tmp % 2) * base;
		tmp /= 2;
		base *= 10;
		size++;
	}
	push_message(pid, nbr, size);
}

void	repeat_message(int pid, char *str)
{
	while (*str)
	{
		binary_conversion(pid, *str);
		str++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	repeat_message(pid, argv[2]);
	return (0);
}
