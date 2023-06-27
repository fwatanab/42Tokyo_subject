/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:36:07 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:41:37 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*exit;
	int		value;

	if (ft_lstsize(*stack) <= 1)
		return (1);
	head = *stack;
	exit = head->next;
	value = head->data;
	head->next = exit->next;
	if (exit->next)
		exit->next->prev = head;
	head->prev = exit;
	exit->prev = NULL;
	exit->next = head;
	*stack = exit;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (!stack_a || swap(stack_a) == 1)
		return (1);
	ft_printf("sa\n");
	return (0);
}

int	sb(t_list **stack_b)
{
	if (!stack_b || swap(stack_b) == 1)
		return (1);
	ft_printf("sb\n");
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !stack_b)
		return (1);
	if (swap(stack_a) == 1 || swap(stack_b) == 1)
		return (1);
	ft_printf("ss\n");
	return (0);
}
