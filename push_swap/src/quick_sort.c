/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:51:20 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:41:03 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	under_number_push_a(t_list **stack_a, t_list **stack_b, int size)
{
	int	nbr;

	if (!*stack_b || !size)
		return (0);
	if (size <= 3)
	{
		sort_b(stack_a, stack_b, size);
		return (0);
	}
	nbr = get_center_number(stack_b, size);
	size = get_push_size(stack_b, nbr, size);
	under_push_a(stack_a, stack_b, nbr, size);
	return (size);
}

static int	under_number_push_b(t_list **stack_a, t_list **stack_b, int size)
{
	int	nbr;

	if (!*stack_a || !size || stack_ascending(*stack_a) == 1)
		return (0);
	if (size <= 3)
	{
		sort_a(stack_a, size);
		return (0);
	}
	nbr = get_center_number(stack_a, size);
	size = get_push_size(stack_a, nbr, size);
	under_push_b(stack_a, stack_b, nbr, size);
	return (size);
}

void	lterative_sort_b(t_list **stack_a, t_list **stack_b, int count)
{
	int	size;

	size = lst_group_same_number_size(*stack_b, count);
	if (!size)
		return ;
	if (size <= 3)
	{
		sort_b(stack_a, stack_b, size);
		return ;
	}
	while (size)
	{
		size = under_number_push_a(stack_a, stack_b, size);
		size = under_number_push_b(stack_a, stack_b, size);
	}
	lterative_sort_a(stack_a, stack_b, count);
}

void	lterative_sort_a(t_list **stack_a, t_list **stack_b, int count)
{
	int	size;

	size = lst_group_same_number_size(*stack_a, count);
	if (!size)
		return ;
	if (size <= 3)
	{
		sort_a(stack_a, size);
		return ;
	}
	while (size)
	{
		size = under_number_push_b(stack_a, stack_b, size);
		size = under_number_push_a(stack_a, stack_b, size);
	}
	lterative_sort_b(stack_a, stack_b, count);
}

void	quick_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	size_a;
	int	size_b;

	if (stack_ascending(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	while (size)
	{
		size = under_number_push_b(stack_a, stack_b, size);
		size = under_number_push_a(stack_a, stack_b, size);
	}
	while (!(lst_group_max_number(*stack_a) == 0
			&& lst_group_max_number(*stack_b) == 0))
	{
		size_a = lst_group_max_number(*stack_a);
		size_b = lst_group_max_number(*stack_b);
		if (size_a > size_b)
			lterative_sort_a(stack_a, stack_b, size_a);
		if (size_a < size_b)
			lterative_sort_b(stack_a, stack_b, size_b);
	}
}
