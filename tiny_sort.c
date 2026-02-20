/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:16:46 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/20 23:37:35 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack **stk)
{
	t_stack	*bigger;

	bigger = ft_find_hi(*stk);
	if (*stk == bigger)
		ra(stk);
	else if ((*stk)->next == bigger)
		rra(stk);
	if ((*stk)->next != NULL && (*stk)->index > (*stk)->next->index)
		sa(stk);
}
