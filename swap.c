/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:26:07 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/06 23:08:27 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_two_nodes(stack **stk)
{
	stack	*temp;
	
	temp = *stk;
	(*stk) = (*stk)->next;
	temp->prev = (*stk);
	temp->next = NULL;
	(*stk)->next = temp;
	(*stk)->prev = NULL;
}

void	swap(stack **stk)
{
	stack *temp;

	if ((*stk)->next->next == NULL)
		swap_two_nodes(stk);
	else
	{
		temp = *stk;
		*stk = (*stk)->next;
		temp->next = (*stk)->next;
		temp->prev = (*stk);
		(*stk)->next = temp;
		(*stk)->prev = NULL;
		temp->next->prev = temp;
	}
}

void	sa(stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(stack **a, stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}