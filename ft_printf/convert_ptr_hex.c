/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:00:32 by fwatanab          #+#    #+#             */
/*   Updated: 2023/02/09 14:02:03 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*set_pet_hex(uintptr_t p1, char *str, int len)
{
	while (p1 != 0)
	{
		if ((p1 % 16) < 10)
			str[len - 1] = (p1 % 16) + '0';
		else
			str[len - 1] = (p1 % 16 - 10) + 'a';
		p1 /= 16;
		len--;
	}
	return (str);
}

char	*convert_ptr_hex(uintptr_t ptr)
{
	int			len;
	char		*str;
	uintptr_t	p1;

	p1 = ptr;
	if (ptr == 0)
		ft_strdup("0");
	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str = set_pet_hex(p1, str, len);
	return (str);
}
