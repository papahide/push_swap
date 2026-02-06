/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:14:05 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/06 22:39:18 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(stack **stk)
{
	stack	*last_node;

	last_node = ft_find_last_node(stk);
	last_node->next = (*stk);
	(*stk)->prev = last_node;
	*stk = (*stk)->next;
	(*stk)->next = NULL;
	last_node->prev = NULL;
}

void	ra(stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(stack **a, stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}