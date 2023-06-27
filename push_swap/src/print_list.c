/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwatanab <fwatanab@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 18:36:34 by fwatanab          #+#    #+#             */
/*   Updated: 2023/06/24 20:16:51 by fwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	group_print_head(t_list *head, t_list *head2)
{
	t_list	*p;
	t_list	*p2;

	p = head;
	p2 = head2;
	ft_printf("-----------------\n");
	ft_printf("group_head\n");
	while (p || p2)
	{
		if (!p)
			ft_printf("\t");
		if (p)
		{
			ft_printf("%d\t", p->group);
			p = p->next;
		}
		if (p2)
		{
			ft_printf("%d", p2->group);
			p2 = p2->next;
		}
		ft_printf("\n");
	}
	ft_printf("-\t-\na\tb\n-----------------\n");
}

void	list_print_head(t_list *head, t_list *head2)
{
	t_list	*p;
	t_list	*p2;

	p = head;
	p2 = head2;
	ft_printf("-----------------\n");
	ft_printf("head\n");
	while (p || p2)
	{
		if (!p)
			ft_printf("\t");
		if (p)
		{
			ft_printf("%d\t", p->data);
			p = p->next;
		}
		if (p2)
		{
			ft_printf("%d", p2->data);
			p2 = p2->next;
		}
		ft_printf("\n");
	}
	ft_printf("-\t-\na\tb\n-----------------\n");
}

void	list_print_tail(t_list *tail, t_list *tail2)
{
	t_list	*p;
	t_list	*p2;

	p = tail;
	p2 = tail2;
	ft_printf("tail\n");
	while (p || p2)
	{
		if (!p)
			ft_printf("\t");
		if (p)
		{
			ft_printf("%d\t", p->data);
			p = p->prev;
		}
		if (p2)
		{
			ft_printf("%d", p2->data);
			p2 = p2->prev;
		}
		ft_printf("\n");
	}
	ft_printf("-\t-\na\tb\n-----------------\n");
}
