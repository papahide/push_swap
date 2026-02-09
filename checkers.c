/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:09:59 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/07 03:15:36 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	ft_strcheck(char *str)
{
	bool	check;
	int i;
	
	i = 0;
	check = true;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') 
			|| (str[i] == '-' || str[i] == '+')))
		{
			check = false;
			break;
		}
		if (i == 0 && ((str[i] == '-' || str[i] == '+') 
			&& !(str[i + 1] >= '0' && str[i + 1] <= '9')))
		{
			check = false;
			break;
		}
		i++;
	}
	return(check);
}

static bool	ft_unique(char **argv, char *str, int index)
{
	long	to_compare;
	long	num;
	int		i;

	i = 0;
	to_compare = ft_atol(str);
	while (argv[i])
	{
		num = ft_atol(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			return(false);
		if (i < index && to_compare == num)
			return(false);
		i++;
	}
	return(true);
}

bool	ft_numcheck(char **argv)
{
	bool	check;
	
	check = false;
	int i;

	i = 0;
	while (argv[i])
	{
		check = ft_strcheck(argv[i]);
		if (check == false)
			return(check);
		i++;
	}
	i = 0;
	while (argv[i])
	{
		check = ft_unique(argv, argv[i], i);
		if (check == false)
			return(check);
		i++;
	}
	return(check);
}
