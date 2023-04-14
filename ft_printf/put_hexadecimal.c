/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hexadecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:02:13 by fwatanab          #+#    #+#             */
/*   Updated: 2023/02/09 14:25:38 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ptr_size(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

static char	*str_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int	put_pointer(unsigned long long ptr)
{
	int		len;
	char	*str;

	ft_putstr_fd("0x", 1);
	if (ptr == 0)
	{
		ft_putstr_fd("0", 1);
		return (3);
	}
	len = ptr_size(ptr) + 2;
	str = convert_ptr_hex(ptr);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	put_hex_lower(unsigned int nbr)
{
	int		len;
	char	*str;

	len = ptr_size(nbr);
	if (nbr == 0)
	{
		ft_putstr_fd("0", 1);
		return (1);
	}
	str = convert_ptr_hex(nbr);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	put_hex_upper(unsigned int nbr)
{
	int		len;
	char	*str;

	len = ptr_size(nbr);
	if (nbr == 0)
	{
		ft_putstr_fd("0", 1);
		return (1);
	}
	str = convert_ptr_hex(nbr);
	if (!str)
		return (0);
	str = str_upper(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
