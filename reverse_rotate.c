/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:14:25 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/06 22:38:34 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(stack **stk)
{
	stack	*first_node;

	first_node = *stk;
	*stk = ft_find_last_node(&first_node);
	first_node->prev = (*stk);
	(*stk)->next = first_node;
	(*stk)->prev = NULL;
	first_node->next = NULL;
}

void	rra(stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 3);
}

void	rrb(stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 3);
}

void	rrr(stack **a, stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 3);
}