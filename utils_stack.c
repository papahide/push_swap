/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:13:31 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/20 23:38:45 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_sorted(t_stack *stk)
{
	if (stk == NULL)
		return (true);
	while (stk->next != NULL)
	{
		if (stk->num > stk->next->num)
			return (false);
		stk = stk->next;
	}
	return (true);
}

void	ft_free_stack(t_stack *stk)
{
	t_stack	*temp;

	while (stk != NULL)
	{
		temp = stk->next;
		free(stk);
		stk = NULL;
		stk = temp;
	}
}

long	ft_stack_len(t_stack *stk)
{
	long	nodes;

	nodes = 0;
	if (stk == NULL)
		return (nodes);
	while (stk != NULL)
	{
		stk = stk->next;
		nodes++;
	}
	return (nodes);
}

void	ft_set_median(t_stack **stk)
{
	t_stack	*temp;
	long	t_stack_len;

	temp = *stk;
	t_stack_len = ft_stack_len(*stk);
	while (temp != NULL)
	{
		if (temp->position <= (t_stack_len / 2))
			temp->up_median = true;
		else
			temp->up_median = false;
		temp = temp->next;
	}
}