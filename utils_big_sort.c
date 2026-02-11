/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:16:35 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/11 23:17:31 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_default_index(stack **stk)
{
	stack	*temp;

	temp = *stk;
	while (temp != NULL)
	{
		temp->index = -1;
		temp = temp->next;
	}
}

void	ft_set_index(stack **stk)
{
	stack	*temp;
	stack	*smallest;
	long	max_index;
	long	i;

	i = 0;
	ft_default_index(stk);
	max_index = ft_stack_len(*stk) - 1;
	while (i <= max_index)
	{
		temp = *stk;
		smallest = *stk;
		while (smallest && smallest->index != -1)
			smallest = smallest->next;
		while (temp)
		{
			if ((smallest->num > temp->num) && temp->index == -1)
				smallest = temp;
			temp = temp->next;
		}
		if (smallest)
			smallest->index = i;
		i++;
	}
}

void	ft_set_target_node(stack **stk, stack **target_stk)
{
	stack	*temp;
	stack	*iterate;

	iterate = *target_stk;
	temp = *stk;
	while (temp != NULL)
	{
		iterate = *target_stk;
		temp->target = NULL;
		while (iterate != NULL)
		{
			if (!temp->target && iterate->index > temp->index)
				temp->target = iterate;
			else if (iterate->index > temp->index 
				&& iterate->index < temp->target->index)
				temp->target = iterate;
			iterate = iterate->next;
		}
		if (!temp->target)
			temp->target = ft_find_smallest(*target_stk);
		temp = temp->next;
	}
}

void	ft_return_a(stack **a, stack **b)
{
	
}
