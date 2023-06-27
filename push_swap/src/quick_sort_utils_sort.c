/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:36:01 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:40:51 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort3_a(t_list **stack)
{
	if (((*stack)->data > (*stack)->next->data
			&& (*stack)->next->data < (*stack)->next->next->data
			&& (*stack)->data < (*stack)->next->next->data)
		|| ((*stack)->data > (*stack)->next->data
			&& (*stack)->next->data > (*stack)->next->next->data)
		|| ((*stack)->data < (*stack)->next->data
			&& (*stack)->next->data > (*stack)->next->next->data
			&& (*stack)->data < (*stack)->next->next->data))
		sa(stack);
	if ((*stack)->data > (*stack)->next->data
		&& (*stack)->next->data < (*stack)->next->next->data)
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
	}
	if ((*stack)->data < (*stack)->next->data
		&& (*stack)->next->data > (*stack)->next->next->data)
	{
		ra(stack);
		sa(stack);
		rra(stack);
		sa(stack);
	}
}

static void	sort3_b(t_list **stack)
{
	if (((*stack)->data > (*stack)->next->data
			&& (*stack)->next->data < (*stack)->next->next->data
			&& (*stack)->data < (*stack)->next->next->data)
		|| ((*stack)->data > (*stack)->next->data
			&& (*stack)->next->data > (*stack)->next->next->data)
		|| ((*stack)->data < (*stack)->next->data
			&& (*stack)->next->data > (*stack)->next->next->data
			&& (*stack)->data < (*stack)->next->next->data))
		sb(stack);
	if ((*stack)->data > (*stack)->next->data
		&& (*stack)->next->data < (*stack)->next->next->data)
	{
		sb(stack);
		rb(stack);
		sb(stack);
		rrb(stack);
	}
	if ((*stack)->data < (*stack)->next->data
		&& (*stack)->next->data > (*stack)->next->next->data)
	{
		rb(stack);
		sb(stack);
		rrb(stack);
		sb(stack);
	}
}

void	sort_a(t_list **stack_a, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->data > (*stack_a)->next->data)
			sa(stack_a);
	}
	else if (size == 3)
		sort3_a(stack_a);
	while (size--)
	{
		(*stack_a)->group = 0;
		ra(stack_a);
	}
}

void	sort_b(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
	{
		if ((*stack_b)->data > (*stack_b)->next->data)
			sb(stack_b);
	}
	else if (size == 3)
		sort3_b(stack_b);
	while (size--)
	{
		(*stack_b)->group = 0;
		pa(stack_a, stack_b);
		ra(stack_a);
	}
}
