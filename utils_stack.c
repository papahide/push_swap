/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 23:13:31 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/10 22:47:48 by paapahid         ###   ########.fr       */
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

long	ft_find_bigger(stack **stk)
{
	long	max_pos;
	long	max_num;
	stack	*aux;

	aux = *stk;
	max_pos = aux->position;
	max_num = aux->num;
	while (aux != NULL)
	{
		if(aux->num > max_num)
		{
			max_pos = aux->position;
			max_num = aux->num;
		}
		aux = aux->next;
	}
	return(max_pos);
}

void	ft_positions(stack **stk)
{
	stack	*temp;
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

stack	*find_hi(stack *stk)
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

stack	*ft_find_smallest(stack *stk)
{
	stack	*smallest;

	smallest = stk;
	while (stk->next != NULL)
	{
		if (stk->num < smallest->num)
			smallest = stk;
		stk = stk->next;
	}
	return(smallest);
}
