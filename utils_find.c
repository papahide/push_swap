/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:26:52 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/20 23:28:28 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_find_smallest(t_stack *stk)
{
	t_stack	*smallest;

	smallest = stk;
	while (stk != NULL)
	{
		if (stk->index < smallest->index)
			smallest = stk;
		stk = stk->next;
	}
	return (smallest);
}

t_stack	*ft_find_hi(t_stack *stk)
{
	t_stack	*biggest;

	biggest = stk;
	while (stk != NULL)
	{
		if (stk->index > biggest->index)
			biggest = stk;
		stk = stk->next;
	}
	return (biggest);
}

t_stack	*ft_find_last_node(t_stack **stk)
{
	t_stack	*last;

	last = *stk;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

t_stack	*ft_find_bigger_smallest(t_stack *node, t_stack **target)
{
	t_stack	*temp;
	t_stack	*best;

	temp = *target;
	best = NULL;
	while (temp != NULL)
	{
		if (temp->index < node->index)
		{
			if (best == NULL || temp->index > best->index)
				best = temp;
		}
		temp = temp->next;
	}
	return (best);
}

t_stack	*ft_find_smallest_bigger(t_stack *node, t_stack **target)
{
	t_stack	*temp;
	t_stack	*best;

	temp = *target;
	best = NULL;
	while (temp != NULL)
	{
		if (temp->index > node->index)
		{
			if (best == NULL || temp->index < best->index)
				best = temp;
		}
		temp = temp->next;
	}
	return (best);
}
