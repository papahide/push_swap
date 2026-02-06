/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:13:31 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/06 23:57:13 by paapahid         ###   ########.fr       */
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

bool	ft_sorted(stack *a)
{
	if (a == NULL)
		return(true);
	while (a->next != NULL)
	{
		if (a->index > a->next->index)
			return(false);
		a = a->next;
	}
	return(true);
}

void	ft_free_sort(stack **a)
{
	stack *tmp;

	tmp = *a;
	while ((*a)!= NULL)
	{
		tmp = *a;
		(*a) = (*a)->next;
		free(tmp);
		tmp = NULL;
	}
}

stack	*ft_find_last_node(stack **stk)
{
	stack *last;
	last = *stk;
	while (last->next != NULL)
		last = last->next;
	return(last);
}
long	ft_stack_len(stack *stk)
{
	long	nodes;

	nodes = 0;
	if (stk == NULL)
		return(nodes);
	while (stk != NULL)
	{
		stk = stk->next;
		nodes++;
	}
	return(nodes);
}