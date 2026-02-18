/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 22:16:46 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/16 22:12:20 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(stack **stk)
{
	stack	*bigger;

	bigger = ft_find_hi(*stk);
	if (*stk == bigger)
		ra(stk);
	else if ((*stk)->next == bigger)
		rra(stk);
	if ((*stk)->next != NULL && (*stk)->num > (*stk)->next->num)
		sa(stk);
}