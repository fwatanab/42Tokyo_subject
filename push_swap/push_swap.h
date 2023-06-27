/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:33:25 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 21:26:22 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <string.h>
# include <limits.h>
# include <stdlib.h>

typedef struct s_list
{
	int				data;
	int				group;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

int		push_swap(int argc, char **argv);
int		check_error(t_list *stack);
int		lstadd_space_split(t_list **stack, int argc, char **argv);
void	error_stack_free(t_list *stack);
void	all_stack_free(t_list *stack);
void	all_free(t_list **stack);
int		sort(t_list **stack_a, t_list **stack_b);
int		stack_ascending(t_list *stack);
int		get_min(t_list *stack);
int		get_min2(t_list *stack, int nbr);
int		count_rotation(t_list *stack, int min);
void	push_count(t_list **stack_a, t_list **stack_b, int count);
void	sort3(t_list **stack_a);
void	sort4(t_list **stack_a, t_list **stack_b);
void	sort5(t_list **stack_a, t_list **stack_b);
void	sort6(t_list **stack_a, t_list **stack_b);
void	quick_sort(t_list **stack_a, t_list **stack_b);
void	sort_size_disteibution(t_list **stack_a, t_list **stack_b, int size);
int		get_push_size(t_list **stack, int nbr, int len);
int		get_center_number(t_list **stack, int size);
int		get_nmin(t_list *stack, int size);
void	under_push_a(t_list **stack_a, t_list **stack_b, int nbr, int size);
void	under_push_b(t_list **stack_a, t_list **stack_b, int nbr, int size);
int		lst_group_same_number_size(t_list *stack, int group_nbr);
int		lst_group_max_number(t_list *stack);
void	lterative_sort_a(t_list **stack_a, t_list **stack_b, int count);
void	lterative_sort_b(t_list **stack_a, t_list **stack_b, int count);
void	sort_b(t_list **stack, t_list **stack_b, int size);
void	sort_a(t_list **stack, int size);

// swao_command
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);

// print
void	list_print_head(t_list *head, t_list *head2);
void	list_print_tail(t_list *tail, t_list *tail2);
void	group_print_head(t_list *head, t_list *head2);

// libft_bonus
t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *stack);

#endif
