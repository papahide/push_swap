/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:16:35 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/20 23:35:26 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_get_cost(t_stack *stk, long len)
{
	long	cost;

	cost = 0;
	if (stk->up_median)
		cost = stk->position;
	else
		cost = len - stk->position;
	return (cost);
}

void	ft_set_price(t_stack **stk, t_stack **target)
{
	t_stack	*temp;
	long	len_a;
	long	len_b;
	long	cost_a;
	long	cost_b;

	temp = *stk;
	len_a = ft_stack_len(*stk);
	len_b = ft_stack_len(*target);
	while (temp != NULL)
	{
		cost_a = ft_get_cost(temp, len_a);
		cost_b = ft_get_cost(temp->target, len_b);
		if (temp->up_median == temp->target->up_median && cost_a < cost_b)
			temp->price = cost_b;
		else if (temp->up_median == temp->target->up_median)
			temp->price = cost_a;
		else
			temp->price = cost_a + cost_b;
		temp = temp->next;
	}
}

static t_stack	*ft_set_cheapest(t_stack *stk)
{
	t_stack	*temp;
	t_stack	*move;

	temp = stk;
	move = stk;
	while (temp != NULL)
	{
		temp->move = false;
		temp = temp->next;
	}
	temp = stk;
	while (temp != NULL)
	{
		if (temp->price < move->price)
			move = temp;
		temp = temp->next;
	}
	move->move = true;
	return (move);
}

static void	ft_get_cheapest(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest)
	{
		if (cheapest->up_median)
			ra(a);
		else
			rra(a);
	}
	while (*b != cheapest->target)
	{
		if (cheapest->target->up_median)
			rb(b);
		else
			rrb(b);
	}
}

void	ft_move_cheapest(t_stack **stk, t_stack **target)
{
	t_stack	*cheapest;

	cheapest = ft_set_cheapest(*stk);
	if (cheapest->up_median && cheapest->target->up_median)
	{
		while (*stk != cheapest && *target != cheapest->target)
			rr(stk, target);
	}
	else if (!cheapest->up_median && !cheapest->target->up_median)
	{
		while (*stk != cheapest && *target != cheapest->target)
			rrr(stk, target);
	}
	if (*stk != cheapest || *target != cheapest->target)
		ft_get_cheapest(stk, target, cheapest);
}
