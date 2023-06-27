/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:30:15 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:41:31 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min2(t_list *stack, int nbr)
{
	int	min;

	min = INT_MAX;
	while (stack)
	{
		if (stack->data < min && stack->data > nbr)
			min = stack->data;
			stack = stack->next;
	}
	return (min);
}

int	get_min(t_list *stack)
{
	int	min;

	min = stack->data;
	stack = stack->next;
	while (stack)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	count_rotation(t_list *stack, int min)
{
	int		rotation;
	t_list	*current;

	rotation = 0;
	current = stack;
	while (current)
	{
		if (current->data == min)
			break ;
		rotation++;
		current = current->next;
	}
	return (rotation);
}

void	push_count(t_list **stack_a, t_list **stack_b, int count)
{
	int	min;
	int	rotation;

	while (count && *stack_a)
	{
		min = get_min(*stack_a);
		rotation = count_rotation(*stack_a, min);
		if (rotation <= ft_lstsize(*stack_a) / 2)
		{
			while ((*stack_a)->data != min)
				ra(stack_a);
		}
		else
		{
			rotation = ft_lstsize(*stack_a) - rotation;
			while ((*stack_a)->data != min)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		count--;
	}
}
