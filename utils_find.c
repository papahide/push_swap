/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:26:52 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/17 22:37:35 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*ft_find_smallest(stack *stk)
{
	stack	*smallest;

	smallest = stk;
	while (stk != NULL)
	{
		if (stk->num < smallest->num)
			smallest = stk;
		stk = stk->next;
	}
	return(smallest);
}

stack	*ft_find_hi(stack *stk)
{
	stack *biggest;

	biggest = stk;
	while (stk != NULL)
	{
		if (stk->num > biggest->num)
			biggest = stk;
		stk = stk->next;
	}
	return (biggest);
}

stack	*ft_find_last_node(stack **stk)
{
	stack *last;
	last = *stk;
	while (last->next != NULL)
		last = last->next;
	return(last);
}

stack	*ft_find_bigger_smallest(stack *node, stack **target)
{
	stack	*temp;
	stack	*best;

	temp = *target;
	best = NULL;
	while (temp != NULL)
	{
		if (temp->num < node->num)
		{
			if (best == NULL || temp->num > best->num)
				best = temp;
		}
		temp = temp->next;
	}
	return (best);
}

stack	*ft_find_smallest_bigger(stack *node, stack **target)
{
	stack	*temp;
	stack	*best;

	temp = *target;
	best = NULL;
	while (temp != NULL)
	{
		if (temp->num > node->num)
		{
			if (best == NULL || temp->num < best->num)
				best = temp;
		}
		temp = temp->next;
	}
	return (best);
}
