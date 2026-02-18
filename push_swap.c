/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 12:24:31 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/17 01:13:09 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	stack *a;
	stack *b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return(0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_create_stack(&a, argv, argc == 2);
	ft_set_index(&a);
	argv = NULL;
	if (!ft_sorted(a))
	{
		if (ft_stack_len(a) == 2)
			sa(&a);
		else if (ft_stack_len(a) == 3)
			tiny_sort(&a);
		else
			big_sort(&a, &b);
	}
	// if (ft_sorted(a))
	// 	printf("Sorted!!");
	ft_free_stack(a);
	a = NULL;
	return(0);
}
