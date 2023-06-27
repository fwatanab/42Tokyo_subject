/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:36:14 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:41:11 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) <= 1)
		return (1);
	head = *stack;
	*stack = head->next;
	(*stack)->prev = NULL;
	tail = ft_lstlast(head);
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == 1)
		return (1);
	ft_printf("ra\n");
	return (0);
}

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == 1)
		return (1);
	ft_printf("rb\n");
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	if (rotate(stack_a) == 1 || rotate(stack_b) == 1)
		return (1);
	ft_printf("rr\n");
	return (0);
}
