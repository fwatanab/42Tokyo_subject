/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:35:55 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:41:34 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_ascending(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
	else if (ft_lstsize(*stack_a) == 3)
		sort3(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort4(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort5(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) <= 6)
		sort6(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) >= 7)
		quick_sort(stack_a, stack_b);
	return (0);
}
