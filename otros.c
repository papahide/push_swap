#include "push_swap.h"

void	ft_fill(stack **a, int number)
{
	stack*	new;

	new = malloc(sizeof(stack));
	// if (new == NULL)
	// 	return(3);
	new->num = number;
	new->next = *a;
	*a = new;
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return(i);
}

char	**ft_parse(char **splitted)
{
	char	**parsed;
	int		i;

	i = 0;
	parsed = malloc((ft_arrlen(splitted) + 1) * sizeof(char *));
	while (splitted[i])
	{
		parsed[i] = malloc((ft_arrlen(&splitted[i]) + 1) * sizeof(int));
		parsed[i] = ft_atoi(splitted[i]);
	}
	return(parsed);
}

void ft_acreator(char *argv[], int argc, stack *a)
{
	char	**parsed;
	char	**splitted;
	stack	filled;
	int		i;

	i = 0;
	if (argc == 2)
	{
		splitted = ft_psplit(argv[1], ' ');
		parsed = ft_parse(splitted);
	}
	else
		parsed = ft_parse(argv);
	while (parsed[i])
	{
		ft_fill(&a, parsed[i]);
		i++;
	}
	ft_freemem(&parsed);
}
