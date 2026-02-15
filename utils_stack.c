/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:13:31 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/15 15:28:35 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_sorted(stack *stk)
{
	if (stk == NULL)
		return(true);
	while (stk->next != NULL)
	{
		if (stk->num > stk->next->num)
			return(false);
		stk = stk->next;
	}
	return(true);
}

void	ft_free_stack(stack *stk)
{
	stack	*temp;

	while (stk != NULL)
	{
		temp = stk->next;
		free(stk);
		stk = NULL;
		stk = temp;
	}
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
