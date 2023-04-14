/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:02:19 by fwatanab          #+#    #+#             */
/*   Updated: 2023/02/09 17:13:58 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	put_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	put_string(char	*str)
{
	if (str == NULL)
		str = "(null)";
	if (INT_MAX <= ft_strlen(str))
		return (-1);
	ft_putstr_fd(str, 1);
	return ((int)ft_strlen(str));
}

int	put_number(int nbr)
{
	int		len;
	char	*str;

	str = ft_itoa(nbr);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	len = (int)ft_strlen(str);
	free(str);
	return (len);
}

int	put_unsigned_number(unsigned int nbr)
{
	int		len;
	char	*str;

	str = unsigned_itoa(nbr);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	len = (int)ft_strlen(str);
	free(str);
	return (len);
}
