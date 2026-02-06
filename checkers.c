/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:09:59 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/06 23:51:46 by paapahid         ###   ########.fr       */
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
		if (!(str[i] >= '0' && str[i] <= '9'))
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
	int		i;
	long	num;

	i = 0;
	num = ft_atol(str);
	while (argv[i])
	{
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			return(false);
		if (i < index && num == ft_atol(argv[i]))
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
			break;
		i++;
	}
	i = 0;
	while (argv[i])
	{
		check = ft_unique(argv, argv[i], i);
		if (check == false)
			break;
		i++;
	}
	return(check);
}
