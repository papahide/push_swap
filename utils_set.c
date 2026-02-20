/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:28:51 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/20 23:37:07 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_positions(t_stack **stk)
{
	t_stack	*temp;
	long	i;

	i = 0;
	temp = *stk;
	while (temp != NULL)
	{
		temp->position = i;
		temp = temp->next;
		i++;
	}
}

static void	ft_default_index(t_stack **stk)
{
	t_stack	*temp;

	temp = *stk;
	while (temp != NULL)
	{
		temp->index = -1;
		temp = temp->next;
	}
}

void	ft_set_index(t_stack **stk)
{
	t_stack	*temp;
	t_stack	*smallest;
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

void	ft_set_target_node(t_stack **stk, t_stack **target)
{
	t_stack	*temp;
	t_stack	*biggest;
	t_stack	*smallest;

	temp = *stk;
	while (temp)
	{
		biggest = ft_find_hi(*target);
		smallest = ft_find_smallest(*target);
		if (temp->num > biggest->num || temp->num < smallest->num)
			temp->target = biggest;
		else
			temp->target = ft_find_bigger_smallest(temp, target);
		temp = temp->next;
	}
}

void	ft_set_target_back(t_stack **stk, t_stack **target)
{
	t_stack	*temp;
	t_stack	*biggest;
	t_stack	*smallest;

	temp = *stk;
	while (temp)
	{
		biggest = ft_find_hi(*target);
		smallest = ft_find_smallest(*target);
		if (temp->num > biggest->num || temp->num < smallest->num)
			temp->target = smallest;
		else
			temp->target = ft_find_smallest_bigger(temp, target);
		temp = temp->next;
	}
}
