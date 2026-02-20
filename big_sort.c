/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:46:56 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/20 23:38:33 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_until_tiny(t_stack **stk, t_stack **target)
{
	while (ft_stack_len(*stk) > 3 && !ft_sorted(*stk))
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

void	ft_rotate_until_target(t_stack **stk, t_stack *node)
{
	if (node->up_median)
		while ((*stk) != node)
			ra(stk);
	else
		while ((*stk) != node)
			rra(stk);
}

static void	ft_return(t_stack **stk, t_stack **target)
{
	while (*stk != NULL)
	{
		ft_set_positions(stk);
		ft_set_positions(target);
		ft_set_target_back(stk, target);
		if ((*target) == (*stk)->target)
			pa(target, stk);
		else
			ft_rotate_until_target(target, (*stk)->target);
	}
}

static void	rotate_until_sort(t_stack **stk)
{
	t_stack	*smallest;

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

void	big_sort(t_stack **a, t_stack **b)
{
	long	len;

	if (ft_sorted(*a))
		return ;
	pb(a, b);
	pb(a, b);
	len = ft_stack_len(*a);
	if (len > 3 && !ft_sorted(*a))
		ft_push_until_tiny(a, b);
	if (ft_stack_len(*a) == 3 && !ft_sorted(*a))
	{
		tiny_sort(a);
		if ((*b)->index < (*b)->next->index)
			sb(b);
	}
	else if (ft_stack_len(*a) < 3 && !ft_sorted(*a))
		sa(a);
	ft_return(b, a);
	while (!ft_sorted(*a))
		rotate_until_sort(a);
}
