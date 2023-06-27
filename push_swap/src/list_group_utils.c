/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_group_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:21:38 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:40:24 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lst_group_max_number(t_list *stack)
{
	int	nbr;

	if (!stack)
		return (0);
	nbr = stack->group;
	while (stack)
	{
		if (stack->group > nbr)
			nbr = stack->group;
		stack = stack->next;
	}
	return (nbr);
}

int	lst_group_same_number_size(t_list *stack, int group_nbr)
{
	int	size;

	size = 0;
	while (stack)
	{
		if (stack->group == group_nbr)
			size++;
		stack = stack->next;
	}
	return (size);
}
