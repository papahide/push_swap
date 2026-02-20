/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:00:42 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/20 23:27:46 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_append_node(t_stack **stk, t_stack **new)
{
	(*new)->prev = NULL;
	if (*stk == NULL)
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

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*to_push;

	if (*src == NULL)
		return ;
	to_push = (*src);
	(*src) = to_push->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	ft_append_node(dest, &to_push);
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
