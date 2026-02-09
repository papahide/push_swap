/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:59:15 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/08 18:55:53 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_new_node(stack **stk, int number, int position)
{
	stack	*new;
	stack	*temp;

	new = malloc(sizeof(stack));
	if (new == NULL)
		return ;
	new->num = number;
	new->position = position;
	new->next = NULL;
	if (*stk == NULL)
	{
		new->prev = NULL;
		*stk = new;
	}
	else
	{
		temp = *stk;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
}

void ft_create_stack(stack **stk, char *argv[], bool split)
{
	bool	check;
	int		num;
	int		i;

	i = 1;
	check = ft_numcheck(&argv[1]);
	if (!check)
	{
		write(2, "Error\n", 6);
		if (split)
			ft_free_arr(argv);
		exit(1);
	}
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		ft_new_node(stk, (int)num, i - 1);
		i++;
	}
	if (split)
	{
		ft_free_arr(argv);
		argv = NULL;
	}
}
