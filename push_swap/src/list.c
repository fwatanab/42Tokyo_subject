/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:12:31 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:40:33 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	str_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static t_list	*check_atoi_digit_ischar(char *str)
{
	t_list	*new;
	size_t	i;
	long	value;

	i = 0;
	if (str[i] == '-')
	{
		i++;
		if (!str[i])
			return (NULL);
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (NULL);
		i++;
	}
	value = ft_atoi(str);
	if (value < INT_MIN || INT_MAX < value)
		return (NULL);
	new = ft_lstnew((int)value);
	if (!new)
		return (NULL);
	return (new);
}

int	lstadd_space_split(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**str;
	size_t	i;
	size_t	j;

	i = 1;
	while (--argc)
	{
		str = ft_split(argv[i++], ' ');
		j = 0;
		while (str[j])
		{
			new = check_atoi_digit_ischar(str[j]);
			if (!new)
			{
				str_free(str);
				error_stack_free(*stack);
				return (1);
			}
			ft_lstadd_back(stack, new);
			j++;
		}
		str_free(str);
	}
	return (0);
}
