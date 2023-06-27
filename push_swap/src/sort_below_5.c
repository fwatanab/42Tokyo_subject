/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_below_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:36:01 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:41:20 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort3(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if ((a > b && b < c && a < c)
		|| (a > b && b > c) || (a < b && b > c && a < c))
		sa(stack);
	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a > b && b < c)
		ra(stack);
	if (a < b && b > c)
		rra(stack);
}

void	sort4(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	if (stack_ascending(*stack_a) == 1)
		return ;
	while ((*stack_a)->data != min)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort3(stack_a);
	pa(stack_a, stack_b);
}

void	sort6(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = 3;
	push_count(stack_a, stack_b, count);
	sort3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort5(t_list **stack_a, t_list **stack_b)
{
	int	count;

	count = 2;
	push_count(stack_a, stack_b, count);
	sort3(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
