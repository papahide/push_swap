/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:00:42 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/10 22:07:14 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_append_node(stack **stk, stack **new)
{
	(*new)->prev = NULL;
	if(*stk == NULL)
	{
		*stk = *new;
		(*stk)->next = NULL;
	}
	else
	{
		(*new)->prev = NULL;
		(*new)->next = *stk;
		(*stk)->prev = *new;
		*stk = *new;
	}
}

void	push(stack **src, stack **dest)
{
	stack *to_push;

	if(*src == NULL)
		return ;
	to_push = (*src);
	(*src) = to_push->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	ft_append_node(dest, &to_push);
}

void	pa(stack **a, stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(stack **a, stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
