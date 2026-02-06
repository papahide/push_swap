/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:16:46 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/07 00:06:51 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	tiny_sort(stack **a)
{
	long	bigger;
	long	node_count;

	ft_positions(a);
	node_count = ft_stack_len(*a);
	if	(node_count < 3)
		return ;
	bigger = ft_find_bigger(a);
	if (bigger == 0)
		ra(a);
	else if (bigger == 1)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}