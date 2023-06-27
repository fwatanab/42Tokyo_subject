/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:13:01 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:40:29 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *stack)
{
	if (stack)
	{
		while (stack->next)
			stack = stack->next;
	}
	return (stack);
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_lstlast(*stack);
	last->next = new;
	new->prev = last;
}

t_list	*ft_lstnew(int data)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->group = 1;
	new->next = NULL;
	return (new);
}
