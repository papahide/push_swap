/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paapahid <paapahid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:33:46 by paapahid          #+#    #+#             */
/*   Updated: 2026/02/07 00:15:17 by paapahid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numcount(char *str, char separator)
{
	int count;
	bool in_num;
	int i;

	i = 0;
	count = 0;
	in_num = false;
	while (str[i])
	{
		in_num = false;
		while (str[i] && str[i] == separator)
			i++;
		while (str[i] && str[i] != separator)
		{
			if (in_num == false)
			{
				in_num = true;
				count++;
			}
			i++;
		}
	}
	return(count);
}

int	ft_numlen(char *str, char separator)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != separator)
		i++;
	return(i);
}

char *ft_substr(char *str, int start, int len)
{
	int i;
	char *sub;
	
	i = 0;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && str[start])
	{
		sub[i] = str[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

char **ft_split(char *numstr, char separator)
{
	char	**nums;
	int		nbrcount;
	int		numlen;
	int		i;
	int		j;

	j = 0;
	i = 0;
	nbrcount = ft_numcount(numstr, separator);
	nums = malloc((nbrcount + 2) * (sizeof(char *)));
	nums[i] = ft_substr("./push_swap", 0, 11);
	if (!nums)
		return(NULL);
	while (++i < nbrcount)
	{
		while (numstr[j] && numstr[j] == separator)
			j++;
		numlen = ft_numlen(&numstr[j], separator);
		nums[i] = ft_substr(&numstr[j], j, numlen);
		if (!nums[i])
			return(ft_freemem(nums, i));
		j = j + numlen;
	}
	nums[i] = NULL;
	return(nums);
}
