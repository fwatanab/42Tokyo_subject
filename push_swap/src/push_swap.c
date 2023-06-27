/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:38:09 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:39:14 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	push_swap(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	if (!stack_a || !stack_b)
		return (1);
	*stack_a = NULL;
	*stack_b = NULL;
	if (lstadd_space_split(stack_a, argc, argv) == 1)
		return (1);
	if (check_error(*stack_a) == 1)
		return (1);
	sort(stack_a, stack_b);
	all_free(stack_a);
	all_free(stack_b);
	return (0);
}
