/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/15 15:26:52 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/15 18:55:01 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

stack	*ft_find_last_node(stack **stk)
{
	stack *last;
	last = *stk;
	while (last->next != NULL)
		last = last->next;
	return(last);
}
