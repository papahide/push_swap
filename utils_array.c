/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 21:55:19 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/10 20:01:29 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_freemem(char **str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		str[j] = NULL;
		j++;
	}
	free(str);
	str = NULL;
	return(NULL);
}

void	ft_free_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

int	ft_strcmp(char *str, char *cmp)
{
	int	i;

	i = 0;
	while (str[i] && cmp[i])
	{
		if (str[i] != cmp[i])
			return (1);
		i++;
	}
	return(0);
}
long	ft_atol(const char *str)
{
	long	lnum;
	long	sign;
	int		i;

	i = 0;
	sign = 1;
	lnum = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++; 
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		lnum = (lnum * 10) + (str[i] - '0');
		i++;
	}
	return(lnum * sign);
}
