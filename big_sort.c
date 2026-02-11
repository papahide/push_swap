/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 20:46:56 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/10 22:48:12 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_until_sort(stack **a)
{
	stack	*smallest;

	smallest = ft_find_smallest(*a);
	while ((*a) != smallest)
	{
		if (smallest->up_median)
			ra(a);
		else
			rra(a);
	}
}

void	big_sort(stack **a, stack **b)
{
	long	len;
	bool	sorted;

	len = ft_stack_len(*a);
	sorted = ft_sorted(a);
	if (sorted)
		return ;
	pb(a, b);
	pb(a, b);
	if (len > 3 && !ft_sorted(a))
		ft_push_until_tiny(a, b);
	if (ft_stack_len(*a) == 3 && !ft_sorted(*a))
		tiny_sort(a);
	else if (ft_stack_len(*a) < 3 && !ft_sorted(*a))
		sa(a);
	ft_return_a(a, b);
	if (!ft_sorted(a))
		rotate_until_sort(a);
}
