/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:09:38 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:40:20 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_stack_free(t_list *stack)
{
	t_list	*exit;

	while (stack)
	{
		exit = stack->next;
		free(stack);
		stack = exit;
	}
	ft_printf("Error\n");
}

void	all_stack_free(t_list *stack)
{
	t_list	*exit;

	while (stack)
	{
		exit = stack->next;
		free(stack);
		stack = exit;
	}
}

void	all_free(t_list **stack)
{
	t_list	*exit;

	while (*stack)
	{
		exit = (*stack)->next;
		free(*stack);
		*stack = exit;
	}
	free(stack);
}
