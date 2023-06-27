/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:12:21 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:40:12 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_equal(t_list *stack, int size)
{
	t_list	*tmp;

	while (--size)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->data == tmp->data)
			{
				error_stack_free(stack);
				return (1);
			}
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	check_error(t_list *stack)
{
	int	size;

	size = ft_lstsize(stack);
	if (size <= 0)
	{
		error_stack_free(stack);
		return (1);
	}
	if (size == 1)
	{
		all_stack_free(stack);
		return (1);
	}
	if (check_equal(stack, size) == 1)
		return (1);
	return (0);
}
