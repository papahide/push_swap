/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 17:59:15 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/20 23:23:57 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_new_node(t_stack **stk, int number, int position)
{
	t_stack	*new;
	t_stack	*temp;

	new = malloc(sizeof(t_stack));
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

void	ft_create_stack(t_stack **stk, char *argv[], bool split)
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
