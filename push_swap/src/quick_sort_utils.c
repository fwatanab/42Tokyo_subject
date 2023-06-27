/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:18:49 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:41:00 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_nmin(t_list *stack, int size)
{
	int	min;

	min = stack->data;
	while (size--)
	{
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return (min);
}

int	get_center_number(t_list **stack, int size)
{
	int		nbr;

	nbr = get_nmin(*stack, size);
	size = size / 2 + 1;
	while (--size)
	{
		nbr = get_min2(*stack, nbr);
	}
	return (nbr);
}

int	get_push_size(t_list **stack, int nbr, int len)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = *stack;
	while (len--)
	{
		if (nbr > tmp->data)
			size++;
		tmp = tmp->next;
	}
	return (size);
}

void	under_push_a(t_list **stack_a, t_list **stack_b, int nbr, int size)
{
	int	rb_count;

	rb_count = 0;
	while (size)
	{
		if (nbr > (*stack_b)->data)
		{
			(*stack_b)->group++;
			pa(stack_a, stack_b);
			size--;
		}
		else
		{
			rb_count++;
			rb(stack_b);
		}
	}
	while (rb_count--)
		rrb(stack_b);
}

void	under_push_b(t_list **stack_a, t_list **stack_b, int nbr, int size)
{
	int	ra_count;

	ra_count = 0;
	while (size)
	{
		if (nbr > (*stack_a)->data)
		{
			(*stack_a)->group++;
			pb(stack_a, stack_b);
			size--;
		}
		else
		{
			ra_count++;
			ra(stack_a);
		}
	}
	while (ra_count--)
		rra(stack_a);
}
