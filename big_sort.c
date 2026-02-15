/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:46:56 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/15 19:17:16 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_set_median(stack **stk)
{
	stack	*temp;
	long	stack_len;

	temp = *stk;
	stack_len = ft_stack_len(*stk);
	while (temp != NULL)
	{
		if (temp->position <= (stack_len / 2))
			temp->up_median = true;
		else
			temp->up_median = false;
		temp = temp->next;
	}
}

static void	ft_push_until_tiny(stack **stk, stack **target)
{
	while (ft_stack_len(*stk) > 3)
	{
		ft_set_positions(stk);
		ft_set_positions(target);
		ft_set_median(stk);
		ft_set_median(target);
		ft_set_target_node(stk, target);
		ft_set_price(stk, target);
		ft_move_cheapest(stk, target);
		pb(stk, target);
	}
}

static void	ft_return(stack **stk, stack **target)
{
	while (*stk != NULL)
	{
		ft_set_positions(stk);
		ft_set_positions(target);
		ft_set_target_node(stk, target);
		if ((*target) == (*stk)->target)
			pa(target, stk);
		else
			ra(target);
	}
}

static void	rotate_until_sort(stack **stk)
{
	stack	*smallest;

	smallest = ft_find_smallest(*stk);
	ft_set_median(stk);
	while (!ft_sorted(*stk))
	{
		if (smallest->up_median)
			ra(stk);
		else
			rra(stk);
	}
}

void	big_sort(stack **a, stack **b)
{
	long	len;

	if (ft_sorted(*a))
		return ;
	pb(a, b);
	pb(a, b);
	if ((*b)->num < (*b)->next->num)
		sb(b);
	len = ft_stack_len(*a);
	if (len > 3 && !ft_sorted(*a))
		ft_push_until_tiny(a, b);
	if (ft_stack_len(*a) == 3 && !ft_sorted(*a))
		tiny_sort(a);
	else if (ft_stack_len(*a) < 3 && !ft_sorted(*a))
		sa(a);
	ft_return(b, a);
	while (!ft_sorted(*a))
		rotate_until_sort(a);
}
