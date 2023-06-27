/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:36:18 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:41:06 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;
	t_list	*tmp;

	if (ft_lstsize(*stack) <= 1)
		return (1);
	head = *stack;
	tail = ft_lstlast(head);
	tmp = tail;
	tmp = tmp->prev;
	head->prev = tail;
	tail->next = head;
	tmp->next = NULL;
	tail->prev = NULL;
	*stack = tail;
	return (0);
}

int	rra(t_list **stack_a)
{
	if (reverse_rotate(stack_a) == 1)
		return (1);
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (reverse_rotate(stack_b) == 1)
		return (1);
	ft_printf("rrb\n");
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rotate(stack_a) == 1 || reverse_rotate(stack_b) == 1)
		return (1);
	ft_printf("rrr\n");
	return (0);
}
