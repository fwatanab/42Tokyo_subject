/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:36:25 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:40:41 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push(t_list **stack_x, t_list **stack_y)
{
	t_list	*tmp_x;
	t_list	*tmp_y;

	if (!*stack_y)
		return (1);
	tmp_x = *stack_x;
	tmp_y = *stack_y;
	*stack_y = tmp_y->next;
	if (*stack_y)
		(*stack_y)->prev = NULL;
	tmp_y->next = tmp_x;
	tmp_y->prev = NULL;
	if (tmp_x)
		tmp_x->prev = tmp_y;
	*stack_x = tmp_y;
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == 1)
		return (1);
	ft_printf("pa\n");
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == 1)
		return (1);
	ft_printf("pb\n");
	return (0);
}
